#include "HCGUIHinge.h"
#include "QGridLayout"
#include "MDIWindow.h"
#include "Standard_Handle.hxx"
#include "AIS_InteractiveContext.hxx"
#include "DocumentCommon.h"
#include "TopoDS_Edge.hxx"
#include "TopoDS.hxx"
#include "TopoDS_Vertex.hxx"
#include "BRep_Tool.hxx"
#include "Geom_Circle.hxx"
#include <QDebug>
#include "gp_Circ.hxx"

HCGUIHinge::HCGUIHinge(QWidget *parent)
	: QDialog(parent),
	m_ModelA(nullptr),
	m_ModelB(nullptr)
{
	ui.setupUi(this);
	initGUI();

	
}

HCGUIHinge::~HCGUIHinge()
{
}

void HCGUIHinge::initGUI()
{
	m_OKButton = new QPushButton(tr("OK"), this);
	m_OKButton->setFixedWidth(100);

	m_PartALabel = new QLabel(this);
	m_PartALabel->setText("PartA:");
	m_PartALabel->setFixedWidth(40);
	m_PartAName = new QLineEdit(this);
	m_PartAName->setFixedWidth(200);
	m_PartAName->setFixedHeight(20);
	m_PartASelectBtn = new QPushButton(tr("..."), this);
	m_PartASelectBtn->setFixedWidth(100);

	m_PivotALabel = new QLabel(this);
	m_PivotALabel->setText("PivotA");
	m_PivotALabel->setFixedWidth(40);
	m_PivotAEdit = new QLineEdit(this);
	m_PivotAEdit->setFixedWidth(200);
	m_PivotAEdit->setFixedHeight(20);
	m_PivotASelectBtn = new QPushButton(tr("..."), this);
	m_PivotASelectBtn->setFixedWidth(100);

	m_AxisInALabel = new QLabel(this);
	m_AxisInALabel->setText("AxisA");
	m_AxisInALabel->setFixedWidth(40);
	m_AxisInAEdit = new QLineEdit(this);
	m_AxisInAEdit->setFixedWidth(200);
	m_AxisInAEdit->setFixedHeight(20);
	m_AxisInASelectBtn = new QPushButton(tr("..."), this);
	m_AxisInASelectBtn->setFixedWidth(100);



	m_PartBLabel = new QLabel(this);
	m_PartBLabel->setText("PartB:");
	m_PartBLabel->setFixedWidth(40);
	m_PartBName = new QLineEdit(this);
	m_PartBName->setFixedWidth(200);
	m_PartBName->setFixedHeight(20);
	m_PartBSelectBtn = new QPushButton(tr("..."), this);
	m_PartBSelectBtn->setFixedWidth(100);

	m_PivotBLabel = new QLabel(this);
	m_PivotBLabel->setText("PivotB");
	m_PivotBLabel->setFixedWidth(40);
	m_PivotBEdit = new QLineEdit(this);
	m_PivotBEdit->setFixedWidth(200);
	m_PivotBEdit->setFixedHeight(20);
	m_PivotBSelectBtn = new QPushButton(tr("..."), this);
	m_PivotBSelectBtn->setFixedWidth(100);

	m_AxisInBLabel = new QLabel(this);
	m_AxisInBLabel->setText("AxisB");
	m_AxisInBLabel->setFixedWidth(40);
	m_AxisInBEdit = new QLineEdit(this);
	m_AxisInBEdit->setFixedWidth(200);
	m_AxisInBEdit->setFixedHeight(20);
	m_AxisInBSelectBtn = new QPushButton(tr("..."), this);
	m_AxisInBSelectBtn->setFixedWidth(100);

	QVBoxLayout* m_VLayout = new QVBoxLayout(this);

	QHBoxLayout* pPartALayout = new QHBoxLayout;
	pPartALayout->addWidget(m_PartALabel);
	pPartALayout->addWidget(m_PartAName);
	pPartALayout->addWidget(m_PartASelectBtn);

	QHBoxLayout* pPivotALayout = new QHBoxLayout;
	pPivotALayout->addWidget(m_PivotALabel);
	pPivotALayout->addWidget(m_PivotAEdit);
	pPivotALayout->addWidget(m_PivotASelectBtn);

	QHBoxLayout* pAxisInALayout = new QHBoxLayout;
	pAxisInALayout->addWidget(m_AxisInALabel);
	pAxisInALayout->addWidget(m_AxisInAEdit);
	pAxisInALayout->addWidget(m_AxisInASelectBtn);


	QHBoxLayout* pPartBLayout = new QHBoxLayout;
	pPartBLayout->addWidget(m_PartBLabel);
	pPartBLayout->addWidget(m_PartBName);
	pPartBLayout->addWidget(m_PartBSelectBtn);

	QHBoxLayout* pPivotBLayout = new QHBoxLayout;
	pPivotBLayout->addWidget(m_PivotBLabel);
	pPivotBLayout->addWidget(m_PivotBEdit);
	pPivotBLayout->addWidget(m_PivotBSelectBtn);

	QHBoxLayout* pAxisInBLayout = new QHBoxLayout;
	pAxisInBLayout->addWidget(m_AxisInBLabel);
	pAxisInBLayout->addWidget(m_AxisInBEdit);
	pAxisInBLayout->addWidget(m_AxisInBSelectBtn);

	
	m_VLayout->addItem(pPartALayout);
	m_VLayout->addItem(pPivotALayout);
	m_VLayout->addItem(pAxisInALayout);
	m_VLayout->addItem(pPartBLayout);
	m_VLayout->addItem(pPivotBLayout);
	m_VLayout->addItem(pAxisInBLayout);
	m_VLayout->addWidget(m_OKButton);

	setLayout(m_VLayout);

	//QGridLayout gridLay;
	connect(m_OKButton, SIGNAL(clicked()), this, SLOT(onOk()));
	connect(m_PartASelectBtn, SIGNAL(clicked()), this, SLOT(onSelectPartABtn()));
	connect(m_PartBSelectBtn, SIGNAL(clicked()), this, SLOT(onSelectPartBBtn()));
	connect(m_PivotASelectBtn, SIGNAL(clicked()), this, SLOT(onSelectPivotABtn()));
	connect(m_PivotBSelectBtn, SIGNAL(clicked()), this, SLOT(onSelectPivotBBtn()));
	connect(m_AxisInASelectBtn, SIGNAL(clicked()), this, SLOT(onSelectAxisABtn()));
	connect(m_AxisInBSelectBtn, SIGNAL(clicked()), this, SLOT(onSelectAxisBBtn()));
}

HCPrjHingeConstraint * HCGUIHinge::getHingeConstraint()
{
	return m_Hinge;
}

void HCGUIHinge::onSelectPartABtn()
{
	
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopAbs_ShapeEnum oldSelectEnum = pCurrentDoc->getSelectType();
	Handle(AIS_InteractiveContext) ipContext = pCurrentDoc->getContext();

	ipContext->InitSelected();
	//Handle(AIS_Shape) S = Handle(AIS_Shape)::DownCast(myContext->Interactive());
	if (ipContext->MoreSelected())
	{
		Handle(AIS_Shape) aSelInteractive = (Handle(AIS_Shape)::DownCast(ipContext->SelectedInteractive()));
		if (aSelInteractive.IsNull())
		{
			qDebug() << "No AIS_Shape is selected!";
			return;
		}
		//getContext()->SetColor(aSelInteractive, Quantity_Color(Quantity_NOC_RED), false);

		for (ipContext->InitSelected(); ipContext->MoreSelected(); ipContext->NextSelected())
		{
			const TopoDS_Shape& aSelShape = ipContext->SelectedShape();
			TopAbs_ShapeEnum nShapeEnum = aSelShape.ShapeType();
			switch (nShapeEnum)
			{
			case TopAbs_COMPOUND:
				break;
			case TopAbs_COMPSOLID:
				break;
			case TopAbs_SOLID:
				{
				HCProject* pPro = pCurrentDoc->getProject();
				PartModel* pCurrentModel = pPro->getPartModel(aSelShape);
				m_PartAName->setText(pCurrentModel->getPartName());
				m_ModelA = pCurrentModel;
				break;
				}
			case TopAbs_SHELL:
				break;
			case TopAbs_FACE:
				break;
			case TopAbs_WIRE:
				break;
			case TopAbs_EDGE:
			{
				TopoDS_Edge aSelEdge = TopoDS::Edge(ipContext->SelectedShape().Located(TopLoc_Location()));
				Standard_Real first, second;
				Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
				Handle(Standard_Type) oType = aCurve->DynamicType();
				if (!oType.IsNull())
				{
					if (std::string(oType->Name()).compare(std::string("Geom_Circle")) == 0)
					{
						qDebug() << "Geom_Circle ";
						Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
						gp_Ax1 aCircleAx = ipCurrentCircle->Axis();
						qDebug() << "aCircleAx Location: " << aCircleAx.Location().X() << aCircleAx.Location().Y() << aCircleAx.Location().Z();

					}
					if (std::string(oType->Name()).compare(std::string("Geom_Line")) == 0)
					{
						qDebug() << "Geom_Line ";
					}

				}
			}
			break;
			case TopAbs_VERTEX:
			{
				TopoDS_Vertex aSleVertex = TopoDS::Vertex(ipContext->SelectedShape().Located(TopLoc_Location()));
				gp_Pnt p = BRep_Tool::Pnt(aSleVertex);
				Standard_Real dTolerance = BRep_Tool::Tolerance(aSleVertex);
				qDebug() << "Vertex position: (" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
				qDebug() << "Vertex Tolerance: " << dTolerance;
				//std::cout << "Vertex orientation: " << DumpOrientation(v.Orientation()) << std::endl;
			}
			break;
			case TopAbs_SHAPE:
				break;
			default:
				break;
			}
		}
	}
	
}

void HCGUIHinge::onSelectPartBBtn()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopAbs_ShapeEnum oldSelectEnum = pCurrentDoc->getSelectType();
	Handle(AIS_InteractiveContext) ipContext = pCurrentDoc->getContext();

	ipContext->InitSelected();
	//Handle(AIS_Shape) S = Handle(AIS_Shape)::DownCast(myContext->Interactive());
	if (ipContext->MoreSelected())
	{
		Handle(AIS_Shape) aSelInteractive = (Handle(AIS_Shape)::DownCast(ipContext->SelectedInteractive()));
		if (aSelInteractive.IsNull())
		{
			qDebug() << "No AIS_Shape is selected!";
			return;
		}
		//getContext()->SetColor(aSelInteractive, Quantity_Color(Quantity_NOC_RED), false);

		for (ipContext->InitSelected(); ipContext->MoreSelected(); ipContext->NextSelected())
		{
			const TopoDS_Shape& aSelShape = ipContext->SelectedShape();
			TopAbs_ShapeEnum nShapeEnum = aSelShape.ShapeType();
			switch (nShapeEnum)
			{
			case TopAbs_COMPOUND:
				break;
			case TopAbs_COMPSOLID:
				break;
			case TopAbs_SOLID:
			{
				HCProject* pPro = pCurrentDoc->getProject();
				PartModel* pCurrentModel = pPro->getPartModel(aSelShape);
				m_PartBName->setText(pCurrentModel->getPartName());
				m_ModelB = pCurrentModel;
				break;
			}
			case TopAbs_SHELL:
				break;
			case TopAbs_FACE:
				break;
			case TopAbs_WIRE:
				break;
			case TopAbs_EDGE:
			{
				TopoDS_Edge aSelEdge = TopoDS::Edge(ipContext->SelectedShape().Located(TopLoc_Location()));
				Standard_Real first, second;
				Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
				Handle(Standard_Type) oType = aCurve->DynamicType();
				if (!oType.IsNull())
				{
					if (std::string(oType->Name()).compare(std::string("Geom_Circle")) == 0)
					{
						qDebug() << "Geom_Circle ";
						Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
						gp_Ax1 aCircleAx = ipCurrentCircle->Axis();
						qDebug() << "aCircleAx Location: " << aCircleAx.Location().X() << aCircleAx.Location().Y() << aCircleAx.Location().Z();

					}
					if (std::string(oType->Name()).compare(std::string("Geom_Line")) == 0)
					{
						qDebug() << "Geom_Line ";
					}

				}
			}
			break;
			case TopAbs_VERTEX:
			{
				TopoDS_Vertex aSleVertex = TopoDS::Vertex(ipContext->SelectedShape().Located(TopLoc_Location()));
				gp_Pnt p = BRep_Tool::Pnt(aSleVertex);
				Standard_Real dTolerance = BRep_Tool::Tolerance(aSleVertex);
				qDebug() << "Vertex position: (" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
				qDebug() << "Vertex Tolerance: " << dTolerance;
				//std::cout << "Vertex orientation: " << DumpOrientation(v.Orientation()) << std::endl;
			}
			break;
			case TopAbs_SHAPE:
				break;
			default:
				break;
			}
		}
	}
}

void HCGUIHinge::onSelectAxisABtn()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopoDS_Shape oCurrentShape = pCurrentDoc->getSelectShape();
	TopAbs_ShapeEnum nShapeEnum = oCurrentShape.ShapeType();
	if (TopAbs_EDGE != nShapeEnum)
	{
		return;
	}
	TopoDS_Edge aSelEdge = TopoDS::Edge(oCurrentShape.Located(TopLoc_Location()));
	Standard_Real first, second;
	Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
	Handle(Standard_Type) oType = aCurve->DynamicType();
	if (!oType.IsNull())
	{
		Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
		gp_Ax1 aCircleAx = ipCurrentCircle->Axis();
		m_AxisInA = aCircleAx.Direction();
		m_AxisInAEdit->setText(QString("Dir:%1 %2 %3").arg(m_AxisInA.X()).arg(m_AxisInA.Y()).arg(m_AxisInA.Z()));
	}

}

void HCGUIHinge::onSelectAxisBBtn()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopoDS_Shape oCurrentShape = pCurrentDoc->getSelectShape();
	TopAbs_ShapeEnum nShapeEnum = oCurrentShape.ShapeType();
	if (TopAbs_EDGE != nShapeEnum)
	{
		return;
	}
	TopoDS_Edge aSelEdge = TopoDS::Edge(oCurrentShape.Located(TopLoc_Location()));
	Standard_Real first, second;
	Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
	Handle(Standard_Type) oType = aCurve->DynamicType();
	if (!oType.IsNull())
	{
		Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
		gp_Ax1 aCircleAx = ipCurrentCircle->Axis();
		m_AxisInB = aCircleAx.Direction();
		m_AxisInBEdit->setText(QString("Dir:%1 %2 %3").arg(m_AxisInB.X()).arg(m_AxisInB.Y()).arg(m_AxisInB.Z()));
	}
}

void HCGUIHinge::onSelectPivotABtn()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopoDS_Shape oCurrentShape = pCurrentDoc->getSelectShape();
	TopAbs_ShapeEnum nShapeEnum = oCurrentShape.ShapeType();
	if (TopAbs_EDGE != nShapeEnum)
	{
		return;
	}
	TopoDS_Edge aSelEdge = TopoDS::Edge(oCurrentShape.Located(TopLoc_Location()));
	Standard_Real first, second;
	Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
	Handle(Standard_Type) oType = aCurve->DynamicType();
	if (!oType.IsNull())
	{
		
		Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
		m_PivotA = ipCurrentCircle->Circ().Position().Location();
		m_PivotAEdit->setText(QString("Loc:%1 %2 %3").arg(m_PivotA.X()).arg(m_PivotA.Y()).arg(m_PivotA.Z()));
	}
}

void HCGUIHinge::onSelectPivotBBtn()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	TopoDS_Shape oCurrentShape = pCurrentDoc->getSelectShape();
	TopAbs_ShapeEnum nShapeEnum = oCurrentShape.ShapeType();
	if (TopAbs_EDGE != nShapeEnum)
	{
		return;
	}
	TopoDS_Edge aSelEdge = TopoDS::Edge(oCurrentShape.Located(TopLoc_Location()));
	Standard_Real first, second;
	Handle(Geom_Curve) aCurve = BRep_Tool::Curve(aSelEdge, first, second);
	Handle(Standard_Type) oType = aCurve->DynamicType();
	if (!oType.IsNull())
	{

		Handle(Geom_Circle) ipCurrentCircle = Handle(Geom_Circle)::DownCast(aCurve);
		m_PivotB = ipCurrentCircle->Circ().Position().Location();
		m_PivotBEdit->setText(QString("Loc:%1 %2 %3").arg(m_PivotB.X()).arg(m_PivotB.Y()).arg(m_PivotB.Z()));
	}
}

void HCGUIHinge::onOk()
{
	MDIWindow* pParentWin = qobject_cast<MDIWindow*>(parent());
	if (nullptr == pParentWin)
	{
		return;
	}
	DocumentCommon* pCurrentDoc = pParentWin->getDocument();
	HCProject* pCurrentProj = pCurrentDoc->getProject();
	m_Hinge = new HCPrjHingeConstraint;
	m_Hinge->setPartModelA(m_ModelA);
	m_Hinge->setPartModelB(m_ModelB);
	m_Hinge->setAxisA(m_AxisInA);
	m_Hinge->setAxisB(m_AxisInB);
	m_Hinge->setPivotA(m_PivotA);
	m_Hinge->setPivotB(m_PivotB);
	pCurrentProj->getConstraintContainer()->m_ConstraintContainer.push_back(m_Hinge);
	clearData();
	this->hide();
//	emit hingeConstraintChanged();
}

void HCGUIHinge::clearData()
{
	m_ModelA = m_ModelB = nullptr;
	m_AxisInA = m_AxisInB = gp_Vec();
	m_PivotA = m_PivotB = gp_Pnt();
	m_PartAName->clear();
	m_PartBName->clear();
	m_AxisInAEdit->clear();
	m_AxisInBEdit->clear();
	m_PivotAEdit->clear();
	m_PivotBEdit->clear();
}
