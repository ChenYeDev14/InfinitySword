/********************************************************************************
** Form generated from reading UI file 'beginbottum.ui'
**
** Created: Sat Oct 20 16:32:31 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEGINBOTTUM_H
#define UI_BEGINBOTTUM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BeginBottum
{
public:
    QPushButton *startsingle;
    QPushButton *webfight;
    QPushButton *website;
    QPushButton *team;
    QPushButton *exitmain;

    void setupUi(QWidget *BeginBottum)
    {
        if (BeginBottum->objectName().isEmpty())
            BeginBottum->setObjectName(QString::fromUtf8("BeginBottum"));
        BeginBottum->resize(261, 342);
        startsingle = new QPushButton(BeginBottum);
        startsingle->setObjectName(QString::fromUtf8("startsingle"));
        startsingle->setGeometry(QRect(30, 50, 141, 31));
        webfight = new QPushButton(BeginBottum);
        webfight->setObjectName(QString::fromUtf8("webfight"));
        webfight->setGeometry(QRect(30, 110, 141, 31));
        website = new QPushButton(BeginBottum);
        website->setObjectName(QString::fromUtf8("website"));
        website->setGeometry(QRect(30, 170, 141, 31));
        team = new QPushButton(BeginBottum);
        team->setObjectName(QString::fromUtf8("team"));
        team->setGeometry(QRect(30, 230, 141, 31));
        exitmain = new QPushButton(BeginBottum);
        exitmain->setObjectName(QString::fromUtf8("exitmain"));
        exitmain->setGeometry(QRect(30, 290, 141, 31));

        retranslateUi(BeginBottum);

        QMetaObject::connectSlotsByName(BeginBottum);
    } // setupUi

    void retranslateUi(QWidget *BeginBottum)
    {
        BeginBottum->setWindowTitle(QApplication::translate("BeginBottum", "Form", 0, QApplication::UnicodeUTF8));
        startsingle->setText(QApplication::translate("BeginBottum", "\345\215\225\344\272\272\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        webfight->setText(QApplication::translate("BeginBottum", "\347\275\221\347\273\234\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        website->setText(QApplication::translate("BeginBottum", "\351\230\237\345\274\217\347\275\221\347\253\231", 0, QApplication::UnicodeUTF8));
        team->setText(QApplication::translate("BeginBottum", "\345\274\200\345\217\221\344\272\272\345\221\230", 0, QApplication::UnicodeUTF8));
        exitmain->setText(QApplication::translate("BeginBottum", "\351\200\200\345\207\272\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BeginBottum: public Ui_BeginBottum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEGINBOTTUM_H
