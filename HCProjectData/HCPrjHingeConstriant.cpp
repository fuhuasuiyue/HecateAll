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
