/********************************************************************************
** Form generated from reading UI file 'backwidget.ui'
**
** Created: Tue Nov 6 13:28:53 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKWIDGET_H
#define UI_BACKWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackWidget
{
public:
    QWidget *widget;

    void setupUi(QWidget *BackWidget)
    {
        if (BackWidget->objectName().isEmpty())
            BackWidget->setObjectName(QString::fromUtf8("BackWidget"));
        BackWidget->resize(1024, 768);
        widget = new QWidget(BackWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 1024, 768));

        retranslateUi(BackWidget);

        QMetaObject::connectSlotsByName(BackWidget);
    } // setupUi

    void retranslateUi(QWidget *BackWidget)
    {
        BackWidget->setWindowTitle(QApplication::translate("BackWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BackWidget: public Ui_BackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKWIDGET_H
