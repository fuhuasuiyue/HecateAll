#include "HCPrjConstraint.h"

ConstraintType HCPrjConstraint::m_ConstraintType = CT_TypeConstraint;

HCPrjConstraint::HCPrjConstraint()
	:m_ModelA(nullptr),
	m_ModelB(nullptr),
	m_ConstraintID(-1),
	m_ConstraintName("")
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

ConstraintType HCPrjConstraint::getConstraintType()
{
	return m_ConstraintType;
}
