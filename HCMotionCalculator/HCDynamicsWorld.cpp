#include "HCDynamicsWorld.h"
#include "qlogging.h"
#include <QDebug>
#include "HCLogManager.h"




HCDynamicsWorld::HCDynamicsWorld()
	:m_nCountStep(0),
	m_TimeStep(btScalar()),
	m_MaxSubSteps(1),
	m_FixedTimeStep(btScalar(1.) / btScalar(60.))


{
	initDW();
}


void HCDynamicsWorld::initDW()
{
	
	m_CollisionConfiguration = new btDefaultCollisionConfiguration;

	m_Dispatcher = new btCollisionDispatcher(m_CollisionConfiguration);

	m_OverlappingPairCache = new btDbvtBroadphase();

	m_Solver = new btSequentialImpulseConstraintSolver;

	m_DynamicsWorld = new btDiscreteDynamicsWorld(m_Dispatcher, m_OverlappingPairCache, m_Solver, m_CollisionConfiguration);

}

HCDynamicsWorld* HCDynamicsWorld::getInstance()
{
	static HCDynamicsWorld oDynamicsWorld;
	return &oDynamicsWorld;
}

HCDynamicsWorld::~HCDynamicsWorld()
{
	delete m_CollisionConfiguration;
	delete m_Dispatcher;
	delete m_OverlappingPairCache;
	delete m_Solver;
	delete m_DynamicsWorld;
}

void HCDynamicsWorld::setGravity(const btVector3& gravity)
{
	m_DynamicsWorld->setGravity(gravity);
}

void HCDynamicsWorld::addRigidBody(int nBodyID, btRigidBody* body)
{
	m_BodyMap.insert(nBodyID, body);
	m_DynamicsWorld->addRigidBody(body);
}

void HCDynamicsWorld::setCountSteps(int nCountStep)
{
	m_nCountStep = nCountStep;
}

int HCDynamicsWorld::getCountSteps()
{
	return m_nCountStep;
}

int HCDynamicsWorld::stepSimulation(btScalar timeStep, int maxSubSteps /*= 1*/, btScalar fixedTimeStep /*= btScalar(1.) / btScalar(60.)*/)
{
	m_TimeStep = timeStep;
	m_MaxSubSteps = maxSubSteps;
	m_FixedTimeStep = fixedTimeStep;

	int nReturn = m_DynamicsWorld->stepSimulation(m_TimeStep, m_MaxSubSteps, m_FixedTimeStep);
	return nReturn;
}

void HCDynamicsWorld::startSimulation()
{
	
	for (int i = 0; i < m_nCountStep; i++)
	{
		//stepSimulation(m_TimeStep, m_MaxSubSteps, m_FixedTimeStep);
		m_DynamicsWorld->stepSimulation(1 / 60.f, 10);

		//print positions of all objects
		QMap<int, btRigidBody*>::iterator iter = m_BodyMap.begin();
		while (iter!=m_BodyMap.end())
		{
			btRigidBody* pCurrentBody = iter.value();
			btTransform oCurrenttrans;
			if (pCurrentBody && pCurrentBody->getMotionState())
			{
				pCurrentBody->getMotionState()->getWorldTransform(oCurrenttrans);
			}
			else
			{
				oCurrenttrans = pCurrentBody->getWorldTransform();
			}
			int nBodyID = iter.key();
			if (m_BodyTrsMap.contains(nBodyID))
			{
				m_BodyTrsMap[nBodyID].push_back(oCurrenttrans);
			}
			else
			{
				QList<btTransform> oCurrentIDTrs;
				oCurrentIDTrs.push_back(oCurrenttrans);
				m_BodyTrsMap.insert(nBodyID, oCurrentIDTrs);
			}
			//m_BodyTrsMap.insert(iter.key(), oCurrenttrans);
			++iter;

			qDebug() << "pCurrentBody pos object " << " = " << float(oCurrenttrans.getOrigin().getX()) << float(oCurrenttrans.getOrigin().getY()) << float(oCurrenttrans.getOrigin().getZ());
			qDebug() << "pCurrentBody rotation  " << float(oCurrenttrans.getRotation().getAngle());
			using namespace HCLOG;
			HC_LOG(INFO) << "pCurrentBody pos object " << " = " << float(oCurrenttrans.getOrigin().getX()) << float(oCurrenttrans.getOrigin().getY()) << float(oCurrenttrans.getOrigin().getZ());
			HC_LOG(INFO) << "pCurrentBody rotation  " << float(oCurrenttrans.getRotation().getAngle());
			
		}
		
	}
}

void HCDynamicsWorld::endSimulation()
{
	for (int i = m_DynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = m_DynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body = btRigidBody::upcast(obj);
		if (body && body->getMotionState())
		{
			while (body->getNumConstraintRefs())
			{
				btTypedConstraint* constraint = body->getConstraintRef(0);
				m_DynamicsWorld->removeConstraint(constraint);
				delete constraint;
			}
			delete body->getMotionState();
			m_DynamicsWorld->removeRigidBody(body);
		}
		m_DynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}
}

void HCDynamicsWorld::addConstraint(btTypedConstraint* constraint, bool disableCollisionsBetweenLinkedBodies /*= false*/)
{
	m_DynamicsWorld->addConstraint(constraint, disableCollisionsBetweenLinkedBodies);
}

QMap<int, QList<btTransform>> HCDynamicsWorld::getBodyTransform()
{
	return m_BodyTrsMap;

}
