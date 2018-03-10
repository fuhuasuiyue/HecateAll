#pragma once

#include <QObject>
#include <QList>
#include "PartModel.h"

typedef QList<PartModel*> PartList;
typedef void(*HCMotionCalc)(PartList calcList);

class LibManager : public QObject
{
	Q_OBJECT

public:
	LibManager(QObject *parent);
	~LibManager();
	static HCMotionCalc loadHCMotionCalc();
};
