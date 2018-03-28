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

PartModel* HCPrjConstraint::getPartModelA()
{
	return m_ModelA;
}

PartModel * HCPrjConstraint::getPartModelB()
{
	return m_ModelB;
}

void HCPrjConstraint::setPartModelA(PartModel * partA)
{
	m_ModelA = partA;
}

void HCPrjConstraint::setPartModelB(PartModel * partB)
{
	m_ModelB = partB;
}

ConstraintType HCPrjConstraint::getConstraintType()
{
	return m_ConstraintType;
}
