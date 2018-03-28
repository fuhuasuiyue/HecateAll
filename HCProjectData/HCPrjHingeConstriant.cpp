#include "HCPrjHingeConstriant.h"


CONSTRAINTIMESUBCLASS(HCPrjHingeConstraint, CT_Hinge)

HCPrjHingeConstraint::HCPrjHingeConstraint()
	:HCPrjConstraint()
{
	
}


HCPrjHingeConstraint::HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Pnt pivotInA, gp_Vec axis)
{
	m_ModelA = pModelA;
	m_ModelB = pModelB;
	m_PivotA = m_PivotB = pivotInA;
	m_AxisInA = m_AxisInB = axis;

}

HCPrjHingeConstraint::HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Ax1 pivotAxis)
{
	m_ModelA = pModelA;
	m_ModelB = pModelB;
	m_PivotA = m_PivotB = pivotAxis.Location();
	m_AxisInA = m_AxisInB = pivotAxis.Direction();
}

HCPrjHingeConstraint::HCPrjHingeConstraint(PartModel* pModelA, PartModel* pModelB, gp_Pnt pivotInA, gp_Pnt pivotInB, gp_Vec axisInA, gp_Vec axisInB)
{
	m_ModelA = pModelA;
	m_ModelB = pModelB;
	m_PivotA = pivotInA;
	m_PivotB = pivotInB;
	m_AxisInA = axisInA;
	m_AxisInB = axisInB;

}

HCPrjHingeConstraint::~HCPrjHingeConstraint()
{
}

void HCPrjHingeConstraint::setPivotA(gp_Pnt pivotA)
{
	m_PivotA = pivotA;
}

gp_Pnt HCPrjHingeConstraint::getPivotA()
{
	return m_PivotA;
}

void HCPrjHingeConstraint::setPivotB(gp_Pnt pivotB)
{
	m_PivotB = pivotB;
}

gp_Pnt HCPrjHingeConstraint::getPivotB()
{
	return m_PivotB;
}

void HCPrjHingeConstraint::setAxisA(gp_Vec axisA)
{
	m_AxisInA = axisA;
}

gp_Vec HCPrjHingeConstraint::getAxisA()
{
	return m_AxisInA;
}

void HCPrjHingeConstraint::setAxisB(gp_Vec axisB)
{
	m_AxisInB = axisB;
}

gp_Vec HCPrjHingeConstraint::getAxisB()
{
	return m_AxisInB;
}
