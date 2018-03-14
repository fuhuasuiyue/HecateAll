#pragma once
#include "btBulletDynamicsCommon.h"
#include "LinearMath\btVector3.h"
#include "QMap"
class HCDynamicsWorld
{
public:
	static HCDynamicsWorld* getInstance();
public:
	~HCDynamicsWorld();
	void setGravity(const btVector3& gravity);
	void addRigidBody(int nBodyID, btRigidBody* body);
	void setCountSteps(int nCountStep);
	int getCountSteps();
	int	stepSimulation(btScalar timeStep, int maxSubSteps = 1, btScalar fixedTimeStep = btScalar(1.) / btScalar(60.));
	void startSimulation();
	void endSimulation();
	void addConstraint(btTypedConstraint* constraint, bool disableCollisionsBetweenLinkedBodies = false);
	QMap<int, QList<btTransform>> getBodyTransform();
private:
	HCDynamicsWorld();
	/*
	* 初始化动力学空间
	*/
	void initDW();
private:
	btDefaultCollisionConfiguration* m_CollisionConfiguration;
	btCollisionDispatcher* m_Dispatcher;
	btBroadphaseInterface* m_OverlappingPairCache;
	btSequentialImpulseConstraintSolver* m_Solver;
	btDiscreteDynamicsWorld* m_DynamicsWorld;
	int m_nCountStep;
	btScalar m_TimeStep;
	int m_MaxSubSteps ;
	btScalar m_FixedTimeStep;
	QMap<int, btRigidBody*> m_BodyMap;
	QMap<int, QList<btTransform>> m_BodyTrsMap;

};

