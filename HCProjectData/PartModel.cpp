#include "PartModel.h"



PartModel::PartModel()
{
	m_PartName = "";
	//m_PartShape = nullptr;
	m_nPartID = -1;
	m_PartColor = Quantity_Color();
	m_PartTransform.clear();
	m_OriginalTrs = gp_Trsf();
}


PartModel::~PartModel()
{
	//if (m_PartShape)
	//{
	//	m_PartShape->Free();
	//	m_PartShape = nullptr;
	//}
	m_PartName = "";
}

void PartModel::setPartName(QString partName)
{
	m_PartName = partName;

}

QString PartModel::getPartName()
{
	return m_PartName;

}

void PartModel::setPartShape(TopoDS_Shape partShape)
{
	m_PartShape = partShape;
	m_OriginalTrs = partShape.Location().Transformation();
}

TopoDS_Shape PartModel::getPartShape()
{
	return m_PartShape;

}

void PartModel::setPartID(int nPartID)
{
	m_nPartID = nPartID;
}

int PartModel::getPartID()
{
	return m_nPartID;
}

void PartModel::setQuantityColor(Quantity_Color oQuantityColor)
{
	m_PartColor = oQuantityColor;
}

Quantity_Color PartModel::getQuantityColor()
{
	return m_PartColor;
}

void PartModel::setPartModelTransform(QList<gp_Trsf> oPartTransformList)
{
	m_PartTransform.append(oPartTransformList);
}

QList<gp_Trsf>& PartModel::getPartModelTransform()
{
	return m_PartTransform;
}

gp_Trsf PartModel::getPartModelOriginal()
{
	return m_OriginalTrs;
}
