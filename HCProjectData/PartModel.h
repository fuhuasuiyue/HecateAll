#pragma once
#include <QString>
#include "TopoDS_Shape.hxx"
#include "Quantity_Color.hxx"
#include "hcprojectdata_global.h"
#include "gp_Trsf.hxx"
#include "QList"

class HCPROJECTDATA_EXPORT PartModel
{
public:
	PartModel();
	~PartModel();
	void setPartName(QString partName);
	QString getPartName();
	void setPartShape(TopoDS_Shape partShape);
	TopoDS_Shape getPartShape();
	void setPartID(int nPartID);
	int getPartID();
	void setQuantityColor(Quantity_Color oQuantityColor);
	Quantity_Color getQuantityColor();
	void setPartModelTransform(QList<gp_Trsf> oPartTransformList);
	QList<gp_Trsf>& getPartModelTransform();
	gp_Trsf getPartModelOriginal();
private:
	int m_nPartID;
	QString m_PartName;
	TopoDS_Shape m_PartShape;
	Quantity_Color m_PartColor;
	QList<gp_Trsf> m_PartTransform;
	gp_Trsf m_OriginalTrs;

};

