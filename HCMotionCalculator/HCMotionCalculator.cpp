#include "HCMotionCalculator.h"
#include <QDebug>
HCMotionCalculator::HCMotionCalculator(QList<PartModel*> calcList)
	:m_CalcPartList(calcList)
{
}

HCMotionCalculator::~HCMotionCalculator()
{

}

QList<PartModel*> HCMotionCalculator::getCalcList()
{
	return m_CalcPartList;
}
