#include "HCMotionCommon.h"
#include <QCoreApplication>
#include <QString>



HCMotionCommon::HCMotionCommon()
{
}


HCMotionCommon::~HCMotionCommon()
{
}

void HCMotionCommon::initHCLogFile()
{
	QString strAppPath = QCoreApplication::applicationDirPath() + "//Log//HCMotionCalculator";
	std::string strPath = strAppPath.toStdString();
	std::string strFileName = "HCMotionLog_";
	HCLOG::HCLogManager::getInstance().initLog(strPath, "Hecate", strFileName);
}
