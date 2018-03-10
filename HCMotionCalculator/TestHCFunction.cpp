#include "hcmotioncalculator_global.h"
#include <QMessageBox>
#include "HCMotionCalculator.h"
#include "HCDynamicsWorld.h"
#include "BulletCollision\CollisionShapes\btTriangleMesh.h"
#include "BulletCollision\CollisionShapes\btMultimaterialTriangleMeshShape.h"
#include "TColgp_Array1OfPnt.hxx"
#include "Poly_Array1OfTriangle.hxx"
#include "BRepMesh_IncrementalMesh.hxx"
#include "TopExp_Explorer.hxx"
#include "TopoDS.hxx"
#include <QDebug>
#include "HCMotionCommon.h"
typedef QList<PartModel*> PartList;

typedef struct TriangleMesh
{
	btVector3 vertex0;
	btVector3 vertex1;
	btVector3 vertex2;
}TriangleMesh;

typedef QList<TriangleMesh> TriangleList;

extern "C"
{
	TriangleList* buildMesh(TopoDS_Shape aShape);

	void HCMOTIONCALCULATOR_EXPORT HCFunction(PartList calcList)
	{
		HCMotionCommon::getInstance()->initHCLogFile();
		int nPartListSize = calcList.size();
		// QMessageBox::warning(NULL, QObject::tr("Test"), QObject::tr("PartListSize is ") + QString("%1").arg(nPartListSize));
		if (1 == nPartListSize)
		{
			PartModel* pCurrentModel = calcList.at(0);
			TopoDS_Shape aCurrentShape = pCurrentModel->getPartShape();
			TopLoc_Location aShapeLocation = aCurrentShape.Location();
			gp_Trsf aSTrs = aShapeLocation.Transformation();
			gp_XYZ aTranslation = aSTrs.TranslationPart(); // 应该是shape的局部坐标
			qDebug() << "aTranslation : " << aTranslation.X() << aTranslation.Y() << aTranslation.Z();

			HCDynamicsWorld *pCurrentWorld = HCDynamicsWorld::getInstance();
			pCurrentWorld->setGravity(btVector3(0, -10, 0));
			btTriangleMesh *pTriMesh = new btTriangleMesh();
			TriangleList* pCurrentShapeTri = buildMesh(aCurrentShape);

			for (int nIndex = 0; nIndex < pCurrentShapeTri->size(); ++nIndex)
			{
				TriangleMesh aCurrentTriMesh = pCurrentShapeTri->at(nIndex);
				pTriMesh->addTriangle(aCurrentTriMesh.vertex0, aCurrentTriMesh.vertex1, aCurrentTriMesh.vertex2);
			}


			btMultimaterialTriangleMeshShape *pMultimaterialShape = new btMultimaterialTriangleMeshShape(pTriMesh, false);
			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(aTranslation.X(), aTranslation.Y(), aTranslation.Z()));

			btScalar mass(50.);
			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
//			if (isDynamic)
//				pMultimaterialShape->calculateLocalInertia(mass, localInertia);
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, pMultimaterialShape, localInertia);
			btQuaternion orn(btVector3(0, 0, 1), 0.1);
			rbInfo.m_startWorldTransform.setRotation(orn);
			btRigidBody* body = new btRigidBody(rbInfo);
			body->setLinearVelocity(btVector3(1, 0, 0)); // 线性速度设置
			body->setAngularVelocity(btVector3(0, 3, 0)); // 旋转速度设置
			int nPartID = pCurrentModel->getPartID();

			pCurrentWorld->addRigidBody(nPartID, body);
			pCurrentWorld->setCountSteps(1000);
			pCurrentWorld->stepSimulation(1.f / 60.f, 10);
			pCurrentWorld->startSimulation();
			pCurrentWorld->endSimulation();
		}
		// 获得图形位置输出
		for (int nPartSize=0; nPartSize<calcList.size(); ++nPartSize)
		{
			PartModel* pCurrentModel = calcList.at(nPartSize);
			HCDynamicsWorld *pCurrentWorld = HCDynamicsWorld::getInstance();
			QMap<int, QList<btTransform>> oPartModelTrs = pCurrentWorld->getBodyTransform();
			QMap<int, QList<btTransform>>::iterator iterModel = oPartModelTrs.begin();
			while (iterModel!=oPartModelTrs.end())
			{
				int nCurrentKey = iterModel.key();
				QList<btTransform> oCurrentTrs = iterModel.value();
				QList<gp_Trsf> pModelTrs;
				QList<btTransform>::iterator iterBtTrs = oCurrentTrs.begin();
				while (iterBtTrs!= oCurrentTrs.end())
				{
					gp_Trsf oModelTrs;
					btMatrix3x3 bodyBiss = iterBtTrs->getBasis();
					btVector3 bodyOri = iterBtTrs->getOrigin();
					btVector3 a1Vec = bodyBiss.getRow(0);
					btVector3 a2Vec = bodyBiss.getRow(1);
					btVector3 a3Vec = bodyBiss.getRow(2);

					double a11 = a1Vec.x();
					double a12 = a2Vec.x();
					double a13 = a3Vec.x();
					double a14 = bodyOri.x();
					double a21 = a1Vec.y();
					double a22 = a2Vec.y();
					double a23 = a3Vec.y();
					double a24 = bodyOri.y();
					double a31 = a1Vec.z();
					double a32 = a2Vec.z();
					double a33 = a3Vec.z();
					double a34 = bodyOri.z();
					oModelTrs.SetValues(a11, a12, a13, a14, a21, a22, a23, a24, a31, a32, a33, a34);
					//oModelTrs.SetTranslationPart(gp_Vec(bodyOri.x, bodyOri.y, bodyOri.z));
					pModelTrs.push_back(oModelTrs);


					iterBtTrs++;
				}

				pCurrentModel->setPartModelTransform(pModelTrs);
				iterModel++;
			}

		}
	}


	TriangleList* buildMesh(TopoDS_Shape aShape)
	{
		TriangleList* pResultTriList = new TriangleList;;
		BRepMesh_IncrementalMesh(aShape, 1);
		TopExp_Explorer faceExplorer;
		for (faceExplorer.Init(aShape, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next())
		{
			TopLoc_Location loc;

			TopoDS_Face aFace = TopoDS::Face(faceExplorer.Current());
			Handle_Poly_Triangulation triFace = BRep_Tool::Triangulation(aFace, loc);
			// 获得当前面在世界坐标系中的转换，即当前面坐标系的值
			gp_Trsf tempTrsf = loc.Transformation();
			Standard_Integer nTriangles = triFace->NbTriangles();
			gp_Pnt vertex1;
			gp_Pnt vertex2;
			gp_Pnt vertex3;

			Standard_Integer nVertexIndex1 = 0;
			Standard_Integer nVertexIndex2 = 0;
			Standard_Integer nVertexIndex3 = 0;
			TColgp_Array1OfPnt nodes(1, triFace->NbNodes());
			Poly_Array1OfTriangle triangles(1, triFace->NbTriangles());
			nodes = triFace->Nodes();
			triangles = triFace->Triangles();
			for (Standard_Integer i = 1; i <= nTriangles; i++)
			{
				Poly_Triangle aTriangle = triangles.Value(i);
				aTriangle.Get(nVertexIndex1, nVertexIndex2, nVertexIndex3);
				vertex1 = nodes.Value(nVertexIndex1);
				vertex2 = nodes.Value(nVertexIndex2);
				vertex3 = nodes.Value(nVertexIndex3);
				// 转换到世界坐标系
				vertex1.Transform(tempTrsf);
				vertex2.Transform(tempTrsf);
				vertex3.Transform(tempTrsf);
				gp_XYZ vector12(vertex2.XYZ() - vertex1.XYZ());
				gp_XYZ vector13(vertex3.XYZ() - vertex1.XYZ());
				gp_XYZ normal = vector12.Crossed(vector13);
				Standard_Real rModulus = normal.Modulus();
				if (rModulus > gp::Resolution())
				{
					normal.Normalize();
				}
				else
				{
					normal.SetCoord(0., 0., 0.);
				}
				TriangleMesh tempTri;
				tempTri.vertex0.setX(vertex1.X());
				tempTri.vertex0.setY(vertex1.Y());
				tempTri.vertex0.setZ(vertex1.Z());
				tempTri.vertex1.setX(vertex2.X());
				tempTri.vertex1.setY(vertex2.Y());
				tempTri.vertex1.setZ(vertex2.Z());
				tempTri.vertex2.setX(vertex3.X());
				tempTri.vertex2.setY(vertex3.Y());
				tempTri.vertex2.setZ(vertex3.Z());
				pResultTriList->append(tempTri);
			}
		}
		return pResultTriList;
	}
};