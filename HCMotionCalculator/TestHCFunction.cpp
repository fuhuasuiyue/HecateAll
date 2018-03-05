#include "hcmotioncalculator_global.h"
#include <QMessageBox>
#include "HCMotionCalculator.h"
#include "HCDynamicsWorld.h"
#include "BulletCollision\CollisionShapes\btTriangleMesh.h"
#include "BulletCollision\CollisionShapes\btMultimaterialTriangleMeshShape.h"

typedef QList<PartModel*> PartList;
extern "C"
{
	void HCMOTIONCALCULATOR_EXPORT HCFunction(PartList calcList)
	{
		int nPartListSize = calcList.size();
		QMessageBox::warning(NULL, QObject::tr("Test"), QObject::tr("PartListSize is ") + QString("%1").arg(nPartListSize));
		if (1 == nPartListSize)
		{
			PartModel* pCurrentModel = calcList.at(0);
			TopoDS_Shape aCurrentShape = pCurrentModel->getPartShape();
			HCDynamicsWorld *pCurrentWorld = HCDynamicsWorld::getInstance();
			pCurrentWorld->setGravity(btVector3(0, -10, 0));
			btTriangleMesh *pTriMesh = new btTriangleMesh();
			btMultimaterialTriangleMeshShape *pMultimaterialShape = new btMultimaterialTriangleMeshShape(pTriMesh, false);
			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(0, -56, 0));

			btScalar mass(5.);
			//rigidbody is dynamic if and only if mass is non zero, otherwise static
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				pMultimaterialShape->calculateLocalInertia(mass, localInertia);
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, pMultimaterialShape, localInertia);
			btRigidBody* body = new btRigidBody(rbInfo);
			pCurrentWorld->addRigidBody(body);
			pCurrentWorld->setCountSteps(100);
			pCurrentWorld->startSimulation();
			pCurrentWorld->endSimulation();

		}
	}
};