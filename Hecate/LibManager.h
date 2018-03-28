#pragma once

#include <QObject>
#include <QList>
#include "PartModel.h"
#include "HCProject.h"

typedef QList<PartModel*> PartList;
typedef void(*HCMotionCalc)(PartList calcList);
typedef void(*HCCalculator)(HCProject* pProject);

class LibManager : public QObject
{
	Q_OBJECT

public:
	LibManager(QObject *parent);
	~LibManager();
	static HCMotionCalc loadHCMotionCalc();
	static HCCalculator loadHCCalculator();
};
