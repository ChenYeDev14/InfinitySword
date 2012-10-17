/********************************************************************************
** Form generated from reading UI file 'teammenu.ui'
**
** Created: Tue Oct 16 05:33:06 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMMENU_H
#define UI_TEAMMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamMenu
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *TeamMenu)
    {
        if (TeamMenu->objectName().isEmpty())
            TeamMenu->setObjectName(QString::fromUtf8("TeamMenu"));
        TeamMenu->resize(1024, 768);
        pushButton = new QPushButton(TeamMenu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 590, 141, 31));

        retranslateUi(TeamMenu);

        QMetaObject::connectSlotsByName(TeamMenu);
    } // setupUi

    void retranslateUi(QWidget *TeamMenu)
    {
        TeamMenu->setWindowTitle(QApplication::translate("TeamMenu", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TeamMenu", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TeamMenu: public Ui_TeamMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMMENU_H
