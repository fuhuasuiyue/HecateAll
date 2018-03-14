#pragma once
#include "QList"
#include "PartModel.h"
#include "HCPrjConstraintContainer.h"
class HCPROJECTDATA_EXPORT HCProject
{
public:
	HCProject();
	~HCProject();
	QList<PartModel*> getPartModelList();
	void setPartModelList(QList<PartModel*> listPart);
	HCPrjConstraintContainer* getConstraintContainer();
	void setConstraintContainer(HCPrjConstraintContainer* container);
	PartModel* getPartModel(TopoDS_Shape selectedShape);
	int getUniquePartModelID(int partID);
private:
	QList<PartModel*> m_partModelList;
	HCPrjConstraintContainer *m_ConstraintContainer;
};

