#include "hcmotioncalculator_global.h"
#include <QMessageBox>
#include "HCMotionCalculator.h"

typedef QList<PartModel*> PartList;
extern "C"
{
	void HCMOTIONCALCULATOR_EXPORT HCFunction(PartList calcList)
	{
		int nPartListSize = calcList.size();
		QMessageBox::warning(NULL, QObject::tr("Test"), QObject::tr("PartListSize is ") + QString("%1").arg(nPartListSize));
	}
};