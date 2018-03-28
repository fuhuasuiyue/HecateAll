#pragma once

#include <QDialog>
#include <QPushButton>
#include "ui_HCGUIHinge.h"
#include "HCPrjHingeConstriant.h"
#include "QLabel"
#include <QTextEdit> 
#include "QComboBox"
#include <QLineEdit>


class HCGUIHinge : public QDialog
{
	Q_OBJECT

public:
	HCGUIHinge(QWidget *parent = Q_NULLPTR);
	~HCGUIHinge();
	void initGUI();
	HCPrjHingeConstraint* getHingeConstraint();
public slots:
	void onSelectPartABtn();
	void onSelectPartBBtn();
	void onSelectAxisABtn();
	void onSelectAxisBBtn();
	void onSelectPivotABtn();
	void onSelectPivotBBtn();
	void onOk();
	void clearData();
signals:
	void hingeConstraintChanged();


private:
	Ui::HCGUIHinge ui;
	HCPrjHingeConstraint *m_Hinge;
	PartModel* m_ModelA;
	PartModel* m_ModelB;
	gp_Pnt m_PivotA;
	gp_Pnt m_PivotB;
	gp_Vec m_AxisInA;
	gp_Vec m_AxisInB;
	QPushButton *m_OKButton;
	QLabel *m_PartALabel;
	QLabel *m_PartBLabel;
	QLabel *m_PivotALabel;
	QLabel *m_PivotBLabel;
	QLabel *m_AxisInALabel;
	QLabel *m_AxisInBLabel;

	QPushButton *m_PartASelectBtn;
	QPushButton *m_PartBSelectBtn;
	QPushButton *m_PivotASelectBtn;
	QPushButton *m_PivotBSelectBtn;
	QPushButton *m_AxisInASelectBtn;
	QPushButton *m_AxisInBSelectBtn;

	QLineEdit *m_PartAName;
	QLineEdit *m_PartBName;
	QLineEdit *m_PivotAEdit;
	QLineEdit *m_PivotBEdit;
	QLineEdit *m_AxisInAEdit;
	QLineEdit *m_AxisInBEdit;


};
