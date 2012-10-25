/********************************************************************************
** Form generated from reading UI file 'clickbottum.ui'
**
** Created: Thu Oct 25 01:57:57 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLICKBOTTUM_H
#define UI_CLICKBOTTUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClickBottum
{
public:
    QCheckBox *checkBox;

    void setupUi(QWidget *ClickBottum)
    {
        if (ClickBottum->objectName().isEmpty())
            ClickBottum->setObjectName(QString::fromUtf8("ClickBottum"));
        ClickBottum->resize(154, 68);
        checkBox = new QCheckBox(ClickBottum);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 20, 101, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        checkBox->setPalette(palette);

        retranslateUi(ClickBottum);

        QMetaObject::connectSlotsByName(ClickBottum);
    } // setupUi

    void retranslateUi(QWidget *ClickBottum)
    {
        ClickBottum->setWindowTitle(QApplication::translate("ClickBottum", "Form", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ClickBottum", "\350\203\214\346\231\257\351\237\263\344\271\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClickBottum: public Ui_ClickBottum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLICKBOTTUM_H
