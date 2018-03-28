#include "LibManager.h"
#include <QLibrary>
#include "QGuiApplication"

LibManager::LibManager(QObject *parent)
	: QObject(parent)
{
}

LibManager::~LibManager()
{
}

HCMotionCalc LibManager::loadHCMotionCalc()
{
	static QLibrary oHCMLib(qApp->applicationDirPath() + "/HCMotionCalculator.dll");
	if (!oHCMLib.isLoaded())
	{
		if (!oHCMLib.load())
		{
			return nullptr;
		}

	}
	HCMotionCalc pHC = (HCMotionCalc)oHCMLib.resolve("HCFunction");
	return pHC;
}

HCCalculator LibManager::loadHCCalculator()
{
	static QLibrary oHCMLib(qApp->applicationDirPath() + "/HCMotionCalculator.dll");
	if (!oHCMLib.isLoaded())
	{
		if (!oHCMLib.load())
		{
			return nullptr;
		}
	}
	HCCalculator pHC = (HCCalculator)oHCMLib.resolve("HCCalculator");
	return pHC;
}
