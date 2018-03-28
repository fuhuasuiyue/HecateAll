/********************************************************************************
** Form generated from reading UI file 'HCGUIHinge.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HCGUIHINGE_H
#define UI_HCGUIHINGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HCGUIHinge
{
public:

    void setupUi(QWidget *HCGUIHinge)
    {
        if (HCGUIHinge->objectName().isEmpty())
            HCGUIHinge->setObjectName(QStringLiteral("HCGUIHinge"));
        HCGUIHinge->resize(400, 300);

        retranslateUi(HCGUIHinge);

        QMetaObject::connectSlotsByName(HCGUIHinge);
    } // setupUi

    void retranslateUi(QWidget *HCGUIHinge)
    {
        HCGUIHinge->setWindowTitle(QApplication::translate("HCGUIHinge", "HCGUIHinge", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HCGUIHinge: public Ui_HCGUIHinge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HCGUIHINGE_H
