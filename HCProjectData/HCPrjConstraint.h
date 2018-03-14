#pragma once
#include "QString"
#include "QVector"
#include "PartModel.h"
#include "hcprojectdata_global.h"
class HCPROJECTDATA_EXPORT HCPrjConstraint
{
public:
	// 约束类型根据Bullet中btTypedConstraint派生关系命名
	enum ConstraintType {
		CT_TypeConstraint=0,
		CT_ConeTwist,
		CT_Contact,
		CT_Gear,
		CT_Gneric5Dof,
		CT_Generic6DofSpring,
		CT_Universal,
		CT_Generic6DofSpring2,
		CT_Fixed,
		CT_Hinge2,
		CT_Hinge,
		CT_HingeAccumulatedAngle,
		CT_Point2Point,
		CT_Slider
	};
public:
	HCPrjConstraint();
	virtual ~HCPrjConstraint();
	const virtual PartModel* getPartModelA();
	const virtual PartModel* getPartModelB();
	ConstraintType getConstraintType();
protected:
	ConstraintType m_ConstraintType;
	QString m_ConstraintName;
	int m_ConstraintID;
	PartModel* m_ModelA;
	PartModel* m_ModelB;

};

