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
#include "HCModelTranslator.h"
#include "HCProject.h"
#include "HCPrjHingeConstriant.h"
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
			
			btCollisionShape* pMultimaterialShape = HCModelTranslator::createConvexShapeFromTopoDS(aCurrentShape);
			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(aTranslation.X(), aTranslation.Y(), aTranslation.Z()));

			btScalar mass(50.);
			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				pMultimaterialShape->calculateLocalInertia(mass, localInertia); // 必须正确设置这个值
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, pMultimaterialShape, localInertia);
			//btQuaternion orn(btVector3(0, 0, 1), 0.1);
			//rbInfo.m_startWorldTransform.setRotation(orn);
			btRigidBody* body = new btRigidBody(rbInfo);
			btHingeConstraint* hinge = new btHingeConstraint(*body, btVector3(0, 0, 0), btVector3(0, 1, 0), true);
			//hinge->setMotorTargetVelocity(10.);
			
			//body->setLinearVelocity(btVector3(1, 0, 0)); // 线性速度设置
			body->setAngularVelocity(btVector3(0, 3, 0)); // 旋转速度设置
			int nPartID = pCurrentModel->getPartID();
			pCurrentWorld->addRigidBody(nPartID, body);
			pCurrentWorld->addConstraint(hinge);
			pCurrentWorld->setCountSteps(1000);
			//pCurrentWorld->stepSimulation(1.f / 60.f, 10);
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
	void HCMOTIONCALCULATOR_EXPORT HCCalculator(HCProject* pProject)
	{
		PartList pPartList = pProject->getPartModelList();
		if (pPartList.empty())
		{
			return;
		}
		QMap<PartModel*, btRigidBody*> partRigidmap;
		HCDynamicsWorld *pCurrentWorld = HCDynamicsWorld::getInstance();
		pCurrentWorld->setGravity(btVector3(0, -10, 0));
		for (int nIndex=0; nIndex<pPartList.size(); ++nIndex)
		{
			PartModel* pCurrentModel = pPartList.at(nIndex);
			TopoDS_Shape aCurrentShape = pCurrentModel->getPartShape();
			
			TopLoc_Location aShapeLocation = aCurrentShape.Location();
			gp_Trsf aSTrs = aShapeLocation.Transformation();
			gp_XYZ aTranslation = aSTrs.TranslationPart(); // 应该是shape的局部坐标

			btCollisionShape* pMultimaterialShape = HCModelTranslator::createConvexShapeFromTopoDS(aCurrentShape);
			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(aTranslation.X(), aTranslation.Y(), aTranslation.Z()));

			btScalar mass(50.);
			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				pMultimaterialShape->calculateLocalInertia(mass, localInertia); // 必须正确设置这个值
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, pMultimaterialShape, localInertia);
			//btQuaternion orn(btVector3(0, 0, 1), 0.1);
			//rbInfo.m_startWorldTransform.setRotation(orn);
			btRigidBody* body = new btRigidBody(rbInfo);
			if (nIndex==0)
			{
				body->setAngularVelocity(btVector3(0, 0, 1)); // 旋转速度设置
			}
			partRigidmap.insert(pCurrentModel, body);
			int nPartID = pCurrentModel->getPartID();
			pCurrentWorld->addRigidBody(nPartID, body);
		}
		HCPrjConstraintContainer* pConstraintContainer = pProject->getConstraintContainer();
		QVector<HCPrjConstraint*> vecContainer = pConstraintContainer->m_ConstraintContainer;
		for (int nCIndex=0; nCIndex<vecContainer.size(); nCIndex++)
		{
			HCPrjConstraint* pCurrentConstraint = vecContainer.value(nCIndex);
			switch (pCurrentConstraint->getConstraintType())
			{
			case CT_TypeConstraint:
				break;
			case CT_ConeTwist:
				break;
			case CT_Contact:
				break;
			case CT_Gear:
				break;
			case CT_Gneric5Dof:
				break;
			case CT_Generic6DofSpring:
				break;
			case CT_Universal:
				break;
			case CT_Generic6DofSpring2:
				break;
			case CT_Fixed:
				break;
			case CT_Hinge2:
				break;
			case CT_Hinge:
			{
				HCPrjHingeConstraint* pHinge = dynamic_cast<HCPrjHingeConstraint*>(pCurrentConstraint);
				PartModel* pModelA = pHinge->getPartModelA();
				PartModel* pModelB = pHinge->getPartModelB();
				if (nullptr!=pModelA && nullptr==pModelB)
				{
					btRigidBody* body = partRigidmap.value(pModelA);
					btScalar pntX = pHinge->getPivotA().X();
					btScalar pntY = pHinge->getPivotA().Y();
					btScalar pntZ = pHinge->getPivotA().Z();
					btVector3 pivotInA = btVector3(pntX, pntY, pntZ);
					btScalar axisX = pHinge->getAxisA().X();
					btScalar axisY = pHinge->getAxisA().Y();
					btScalar axisZ = pHinge->getAxisA().Z();
					btVector3 axisInA = btVector3(axisX, axisY, axisZ);
					btHingeConstraint* hinge = new btHingeConstraint(*body, pivotInA, axisInA, true);
					pCurrentWorld->addConstraint(hinge);
				}

				if (nullptr != pModelA && nullptr != pModelB)
				{
					btRigidBody* pBodyA = partRigidmap.value(pModelA);
					btRigidBody* pBodyB = partRigidmap.value(pModelB);
					btScalar pntAX = pHinge->getPivotA().X();
					btScalar pntAY = pHinge->getPivotA().Y();
					btScalar pntAZ = pHinge->getPivotA().Z();
					btVector3 pivotInA = btVector3(pntAX, pntAY, pntAZ);
					btScalar axisAX = pHinge->getAxisA().X();
					btScalar axisAY = pHinge->getAxisA().Y();
					btScalar axisAZ = pHinge->getAxisA().Z();
					btVector3 axisInA = btVector3(axisAX, axisAY, axisAZ);

					btScalar pntBX = pHinge->getPivotB().X();
					btScalar pntBY = pHinge->getPivotB().Y();
					btScalar pntBZ = pHinge->getPivotB().Z();
					btVector3 pivotInB = btVector3(pntBX, pntBY, pntBZ);
					btScalar axisBX = pHinge->getAxisB().X();
					btScalar axisBY = pHinge->getAxisB().Y();
					btScalar axisBZ = pHinge->getAxisB().Z();
					btVector3 axisInB = btVector3(axisBX, axisBY, axisBZ);
					btHingeConstraint* hinge = new btHingeConstraint(*pBodyA, *pBodyB, pivotInA, pivotInB, axisInB,axisInA, true);
					pCurrentWorld->addConstraint(hinge);
				}

			}
				break;
			case CT_HingeAccumulatedAngle:
				break;
			case CT_Point2Point:
				break;
			case CT_Slider:
				break;
			default:
				break;
			}

		}
		pCurrentWorld->setCountSteps(1000);
		//pCurrentWorld->stepSimulation(1.f / 60.f, 10);
		pCurrentWorld->startSimulation();
		pCurrentWorld->endSimulation();
		for (int nIndex = 0; nIndex<pPartList.size(); ++nIndex)
		{
			PartModel* pCurrentModel = pPartList.at(nIndex);
			HCDynamicsWorld *pCurrentWorld = HCDynamicsWorld::getInstance();
			QMap<int, QList<btTransform>> oPartModelTrs = pCurrentWorld->getBodyTransform();
			QMap<int, QList<btTransform>>::iterator iterModel = oPartModelTrs.begin();
			while (iterModel != oPartModelTrs.end())
			{
				int nCurrentKey = iterModel.key();
				QList<btTransform> oCurrentTrs = iterModel.value();
				QList<gp_Trsf> pModelTrs;
				QList<btTransform>::iterator iterBtTrs = oCurrentTrs.begin();
				while (iterBtTrs != oCurrentTrs.end())
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
};