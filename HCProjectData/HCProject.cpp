#include "HCProject.h"



HCProject::HCProject():
	m_ConstraintContainer(nullptr)
{
	
	m_partModelList.clear();
}


HCProject::~HCProject()
{
}

QList<PartModel*> HCProject::getPartModelList()
{
	return m_partModelList;
}

PartModel* HCProject::addPartModel()
{
	PartModel* pAddModel = new PartModel;
	int nPartID = 0;
	if (!m_partModelList.isEmpty())
	{
		nPartID = getUniquePartModelID(nPartID);
	}
	pAddModel->setPartID(nPartID);
	m_partModelList.append(pAddModel);
	return pAddModel;
}

void HCProject::setPartModelList(QList<PartModel*> listPart)
{
	m_partModelList = listPart;
}

HCPrjConstraintContainer * HCProject::getConstraintContainer()
{
	if (nullptr == m_ConstraintContainer)
	{
		m_ConstraintContainer = new HCPrjConstraintContainer;
	}
	return m_ConstraintContainer;
}

void HCProject::setConstraintContainer(HCPrjConstraintContainer * container)
{
	m_ConstraintContainer = container;
}

PartModel * HCProject::getPartModel(TopoDS_Shape selectedShape)
{
	if (m_partModelList.isEmpty())
	{
		return nullptr;
	}
	for (int nCurrentNum = 0; nCurrentNum < m_partModelList.size(); ++nCurrentNum)
	{
		PartModel* pModel = m_partModelList.at(nCurrentNum);
		if (pModel->getPartShape().IsEqual(selectedShape))
		{
			return pModel;
		}
	}
	return nullptr;
}

int HCProject::getUniquePartModelID(int partID)
{
	if (m_partModelList.isEmpty())
	{
		return 0;
	}
	QList<PartModel*>::iterator itPart = m_partModelList.begin();
	for (; itPart != m_partModelList.end(); ++itPart)
	{
		if ((*itPart)->getPartID() == partID)
		{
			partID++;
		}
	}

	return partID;

}
