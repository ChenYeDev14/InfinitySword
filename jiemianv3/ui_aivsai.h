/********************************************************************************
** Form generated from reading UI file 'aivsai.ui'
**
** Created: Thu Oct 25 00:56:02 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIVSAI_H
#define UI_AIVSAI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AIvsAI
{
public:
    QProgressBar *progressBar;
    QPushButton *Map;
    QPushButton *AI1;
    QPushButton *AI2;
    QPushButton *Start;
    QPushButton *ReturnPre;
    QComboBox *comboBox_AI1;
    QComboBox *comboBox_AI2;
    QComboBox *comboBox_map;

    void setupUi(QWidget *AIvsAI)
    {
        if (AIvsAI->objectName().isEmpty())
            AIvsAI->setObjectName(QString::fromUtf8("AIvsAI"));
        AIvsAI->resize(1024, 768);
        progressBar = new QProgressBar(AIvsAI);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 590, 501, 20));
        progressBar->setValue(24);
        Map = new QPushButton(AIvsAI);
        Map->setObjectName(QString::fromUtf8("Map"));
        Map->setGeometry(QRect(50, 430, 141, 33));
        AI1 = new QPushButton(AIvsAI);
        AI1->setObjectName(QString::fromUtf8("AI1"));
        AI1->setGeometry(QRect(50, 270, 141, 33));
        AI2 = new QPushButton(AIvsAI);
        AI2->setObjectName(QString::fromUtf8("AI2"));
        AI2->setGeometry(QRect(50, 350, 141, 33));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AI2->sizePolicy().hasHeightForWidth());
        AI2->setSizePolicy(sizePolicy);
        Start = new QPushButton(AIvsAI);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(791, 563, 141, 33));
        ReturnPre = new QPushButton(AIvsAI);
        ReturnPre->setObjectName(QString::fromUtf8("ReturnPre"));
        ReturnPre->setGeometry(QRect(791, 610, 141, 33));
        comboBox_AI1 = new QComboBox(AIvsAI);
        comboBox_AI1->setObjectName(QString::fromUtf8("comboBox_AI1"));
        comboBox_AI1->setGeometry(QRect(220, 273, 250, 27));
        comboBox_AI2 = new QComboBox(AIvsAI);
        comboBox_AI2->setObjectName(QString::fromUtf8("comboBox_AI2"));
        comboBox_AI2->setGeometry(QRect(220, 353, 250, 27));
        comboBox_map = new QComboBox(AIvsAI);
        comboBox_map->setObjectName(QString::fromUtf8("comboBox_map"));
        comboBox_map->setGeometry(QRect(220, 433, 250, 27));

        retranslateUi(AIvsAI);

        QMetaObject::connectSlotsByName(AIvsAI);
    } // setupUi

    void retranslateUi(QWidget *AIvsAI)
    {
        AIvsAI->setWindowTitle(QApplication::translate("AIvsAI", "Form", 0, QApplication::UnicodeUTF8));
        Map->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        AI1->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245AI1", 0, QApplication::UnicodeUTF8));
        AI2->setText(QApplication::translate("AIvsAI", "\350\275\275\345\205\245AI2", 0, QApplication::UnicodeUTF8));
        Start->setText(QApplication::translate("AIvsAI", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        ReturnPre->setText(QApplication::translate("AIvsAI", "\350\277\224\345\233\236\344\270\212\347\272\247", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AIvsAI: public Ui_AIvsAI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AIVSAI_H
