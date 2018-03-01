#pragma once

#include "hcmotioncalculator_global.h"
#include "PartModel.h"
#include "QList"

class HCMOTIONCALCULATOR_EXPORT HCMotionCalculator
{
public:
	HCMotionCalculator(QList<PartModel*> calcList);
	~HCMotionCalculator();
	QList<PartModel*> getCalcList();
private:

	QList<PartModel*> m_CalcPartList;
};
