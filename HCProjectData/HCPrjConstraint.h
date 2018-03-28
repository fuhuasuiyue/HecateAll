#pragma once
#include "QString"
#include "QVector"
#include "PartModel.h"
#include "hcprojectdata_global.h"



// 约束类型根据Bullet中btTypedConstraint派生关系命名
enum ConstraintType {
	CT_TypeConstraint = 0,
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

#define CONSTRAINTDEFSUBCLASS(_class_)									\
public:																	\
 ConstraintType getConstraintType(){return _class_::m_ConstraintType;}	\
private:																\
static ConstraintType _class_::m_ConstraintType;

#define CONSTRAINTIMESUBCLASS(_class_, _constraintType)					\
ConstraintType _class_::m_ConstraintType = _constraintType;

class HCPROJECTDATA_EXPORT HCPrjConstraint
{
public:

public:
	HCPrjConstraint();
	virtual ~HCPrjConstraint();
	virtual PartModel* getPartModelA();
	virtual PartModel* getPartModelB();
	virtual void setPartModelA(PartModel* partA);
	virtual void setPartModelB(PartModel* partB);
	virtual ConstraintType getConstraintType();
protected:	
	QString m_ConstraintName;
	int m_ConstraintID;
	PartModel* m_ModelA;
	PartModel* m_ModelB;
private:
	static ConstraintType m_ConstraintType;

};

