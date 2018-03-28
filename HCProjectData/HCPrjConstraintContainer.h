#pragma once
#include "QVector"
#include "HCPrjConstraint.h"
#include "hcprojectdata_global.h"
class HCPROJECTDATA_EXPORT HCPrjConstraintContainer
{

public:
	HCPrjConstraintContainer();
	~HCPrjConstraintContainer();
	QVector<HCPrjConstraint*> m_ConstraintContainer;
protected:
	

};

