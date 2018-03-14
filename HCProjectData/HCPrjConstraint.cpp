#include "HCPrjConstraint.h"



HCPrjConstraint::HCPrjConstraint()
	:m_ModelA(nullptr),
	m_ModelB(nullptr),
	m_ConstraintID(-1),
	m_ConstraintName(""),
	m_ConstraintType(CT_TypeConstraint)
{
}


HCPrjConstraint::~HCPrjConstraint()
{
}

const PartModel* HCPrjConstraint::getPartModelA()
{
	return m_ModelA;
}

const PartModel * HCPrjConstraint::getPartModelB()
{
	return m_ModelB;
}

HCPrjConstraint::ConstraintType HCPrjConstraint::getConstraintType()
{
	return m_ConstraintType;
}
