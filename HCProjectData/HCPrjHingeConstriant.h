#pragma once
#include "HCPrjConstraint.h"
#include "gp_Ax1.hxx"


class HCPROJECTDATA_EXPORT HCPrjHingeConstraint : public HCPrjConstraint
{
	CONSTRAINTDEFSUBCLASS(HCPrjHingeConstraint)
public:
	HCPrjHingeConstraint();
	HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Pnt pivotInA, gp_Vec axis);
	HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Ax1 pivotAxis);
	//btHingeConstraint(btRigidBody& rbA, btRigidBody& rbB, const btVector3& pivotInA, const btVector3& pivotInB, const btVector3& axisInA, const btVector3& axisInB, bool useReferenceFrameA = false);
	HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Pnt pivotInA, gp_Pnt pivotInB, gp_Vec axisInA, gp_Vec axisInB);
	//btHingeConstraint(btRigidBody& rbA, const btVector3& pivotInA, const btVector3& axisInA, bool useReferenceFrameA = false);

	//btHingeConstraint(btRigidBody& rbA, btRigidBody& rbB, const btTransform& rbAFrame, const btTransform& rbBFrame, bool useReferenceFrameA = false);

	//btHingeConstraint(btRigidBody& rbA, const btTransform& rbAFrame, bool useReferenceFrameA = false);
	~HCPrjHingeConstraint();
	void setPivotA(gp_Pnt pivotA);
	gp_Pnt getPivotA();
	void setPivotB(gp_Pnt pivotB);
	gp_Pnt getPivotB();
	void setAxisA(gp_Vec axisA);
	gp_Vec getAxisA();
	void setAxisB(gp_Vec axisB);
	gp_Vec getAxisB();

private:
	gp_Pnt m_PivotA;
	gp_Pnt m_PivotB;
	gp_Vec m_AxisInA;
	gp_Vec m_AxisInB;

	
};

