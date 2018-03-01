#include "hcmotioncalculator_global.h"
#include <QMessageBox>

extern "C"
{
	void HCMOTIONCALCULATOR_EXPORT TestHCFunction()
	{
		QMessageBox::warning(NULL, QObject::tr("Test"), QObject::tr("TestHCFunction"));
	}
};