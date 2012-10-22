/********************************************************************************
** Form generated from reading UI file 'humainaibattle.ui'
**
** Created: Fri Oct 19 02:16:02 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUMAINAIBATTLE_H
#define UI_HUMAINAIBATTLE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Button_loadMap;
    QPushButton *AI2;
    QPushButton *Button_start;
    QPushButton *Button_back;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *Layout_game;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(1024, 768);
        verticalLayoutWidget = new QWidget(Form);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 590, 81, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Button_loadMap = new QPushButton(verticalLayoutWidget);
        Button_loadMap->setObjectName(QString::fromUtf8("Button_loadMap"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button_loadMap->sizePolicy().hasHeightForWidth());
        Button_loadMap->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Button_loadMap);

        AI2 = new QPushButton(verticalLayoutWidget);
        AI2->setObjectName(QString::fromUtf8("AI2"));
        sizePolicy.setHeightForWidth(AI2->sizePolicy().hasHeightForWidth());
        AI2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(AI2);

        Button_start = new QPushButton(verticalLayoutWidget);
        Button_start->setObjectName(QString::fromUtf8("Button_start"));
        sizePolicy.setHeightForWidth(Button_start->sizePolicy().hasHeightForWidth());
        Button_start->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Button_start);

        Button_back = new QPushButton(verticalLayoutWidget);
        Button_back->setObjectName(QString::fromUtf8("Button_back"));
        sizePolicy.setHeightForWidth(Button_back->sizePolicy().hasHeightForWidth());
        Button_back->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(Button_back);

        verticalLayoutWidget_2 = new QWidget(Form);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(170, 50, 801, 671));
        Layout_game = new QVBoxLayout(verticalLayoutWidget_2);
        Layout_game->setObjectName(QString::fromUtf8("Layout_game"));
        Layout_game->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        Button_loadMap->setText(QApplication::translate("Form", "\350\275\275\345\205\245AI", 0, QApplication::UnicodeUTF8));
        AI2->setText(QApplication::translate("Form", "\350\275\275\345\205\245\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        Button_start->setText(QApplication::translate("Form", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        Button_back->setText(QApplication::translate("Form", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUMAINAIBATTLE_H
