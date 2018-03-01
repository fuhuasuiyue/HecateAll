#pragma once
#include <QString>
#include "TopoDS_Shape.hxx"
#include "Quantity_Color.hxx"

class PartModel
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
private:
	int m_nPartID;
	QString m_PartName;
	TopoDS_Shape m_PartShape;
	Quantity_Color m_PartColor;

};

