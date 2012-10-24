/********************************************************************************
** Form generated from reading UI file 'widgetssingle.ui'
**
** Created: Wed Oct 24 01:24:51 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSSINGLE_H
#define UI_WIDGETSSINGLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetssingle
{
public:
    QPushButton *playervsai;
    QPushButton *levelmode;
    QPushButton *aivsai;
    QPushButton *replay;
    QPushButton *mapedit;
    QPushButton *returnpre;

    void setupUi(QWidget *widgetssingle)
    {
        if (widgetssingle->objectName().isEmpty())
            widgetssingle->setObjectName(QString::fromUtf8("widgetssingle"));
        widgetssingle->resize(178, 400);
        playervsai = new QPushButton(widgetssingle);
        playervsai->setObjectName(QString::fromUtf8("playervsai"));
        playervsai->setGeometry(QRect(30, 110, 141, 31));
        levelmode = new QPushButton(widgetssingle);
        levelmode->setObjectName(QString::fromUtf8("levelmode"));
        levelmode->setGeometry(QRect(30, 170, 141, 31));
        aivsai = new QPushButton(widgetssingle);
        aivsai->setObjectName(QString::fromUtf8("aivsai"));
        aivsai->setGeometry(QRect(30, 50, 141, 31));
        replay = new QPushButton(widgetssingle);
        replay->setObjectName(QString::fromUtf8("replay"));
        replay->setGeometry(QRect(30, 230, 141, 31));
        mapedit = new QPushButton(widgetssingle);
        mapedit->setObjectName(QString::fromUtf8("mapedit"));
        mapedit->setGeometry(QRect(30, 290, 141, 31));
        returnpre = new QPushButton(widgetssingle);
        returnpre->setObjectName(QString::fromUtf8("returnpre"));
        returnpre->setGeometry(QRect(30, 350, 141, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(returnpre->sizePolicy().hasHeightForWidth());
        returnpre->setSizePolicy(sizePolicy);

        retranslateUi(widgetssingle);

        QMetaObject::connectSlotsByName(widgetssingle);
    } // setupUi

    void retranslateUi(QWidget *widgetssingle)
    {
        widgetssingle->setWindowTitle(QApplication::translate("widgetssingle", "Form", 0, QApplication::UnicodeUTF8));
        playervsai->setText(QApplication::translate("widgetssingle", "\344\272\272\346\234\272\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        levelmode->setText(QApplication::translate("widgetssingle", "\351\227\257\345\205\263\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        aivsai->setText(QApplication::translate("widgetssingle", "AI\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        replay->setText(QApplication::translate("widgetssingle", "\346\210\230\344\272\211\345\233\236\346\224\276", 0, QApplication::UnicodeUTF8));
        mapedit->setText(QApplication::translate("widgetssingle", "\347\274\226\350\276\221\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        returnpre->setText(QApplication::translate("widgetssingle", "\350\277\224\345\233\236\344\270\212\347\272\247", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class widgetssingle: public Ui_widgetssingle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSSINGLE_H
