/********************************************************************************
** Form generated from reading UI file 'humanai.ui'
**
** Created: Sun Oct 21 19:00:59 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUMANAI_H
#define UI_HUMANAI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_humanai
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *Layout_AI1;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *Layout_AI2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *Layout_display;
    QLabel *AI1Info;
    QLabel *AI2Info;
    QLabel *flag1;
    QLabel *flag2;
    QPushButton *Button_help;
    QProgressBar *progressBar;
    QLabel *label;
    QLCDNumber *lcdNumber_round;
    QPushButton *Button_loadMap;
    QPushButton *Button_start;
    QPushButton *Button_back;
    QPushButton *Button_loadAI;

    void setupUi(QWidget *humanai)
    {
        if (humanai->objectName().isEmpty())
            humanai->setObjectName(QString::fromUtf8("humanai"));
        humanai->resize(1024, 768);
        verticalLayoutWidget_2 = new QWidget(humanai);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 170, 181, 381));
        Layout_AI1 = new QVBoxLayout(verticalLayoutWidget_2);
        Layout_AI1->setObjectName(QString::fromUtf8("Layout_AI1"));
        Layout_AI1->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_3 = new QWidget(humanai);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(840, 170, 181, 381));
        Layout_AI2 = new QVBoxLayout(verticalLayoutWidget_3);
        Layout_AI2->setObjectName(QString::fromUtf8("Layout_AI2"));
        Layout_AI2->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_4 = new QWidget(humanai);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(210, 40, 601, 641));
        Layout_display = new QVBoxLayout(verticalLayoutWidget_4);
        Layout_display->setObjectName(QString::fromUtf8("Layout_display"));
        Layout_display->setContentsMargins(0, 0, 0, 0);
        AI1Info = new QLabel(humanai);
        AI1Info->setObjectName(QString::fromUtf8("AI1Info"));
        AI1Info->setGeometry(QRect(0, 120, 181, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        AI1Info->setFont(font);
        AI1Info->setAlignment(Qt::AlignCenter);
        AI2Info = new QLabel(humanai);
        AI2Info->setObjectName(QString::fromUtf8("AI2Info"));
        AI2Info->setGeometry(QRect(840, 120, 181, 51));
        AI2Info->setFont(font);
        AI2Info->setCursor(QCursor(Qt::ArrowCursor));
        AI2Info->setAlignment(Qt::AlignCenter);
        flag1 = new QLabel(humanai);
        flag1->setObjectName(QString::fromUtf8("flag1"));
        flag1->setGeometry(QRect(0, 80, 181, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flag1->sizePolicy().hasHeightForWidth());
        flag1->setSizePolicy(sizePolicy);
        flag1->setFont(font);
        flag1->setTextFormat(Qt::RichText);
        flag1->setAlignment(Qt::AlignCenter);
        flag2 = new QLabel(humanai);
        flag2->setObjectName(QString::fromUtf8("flag2"));
        flag2->setGeometry(QRect(840, 80, 181, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        flag2->setFont(font1);
        flag2->setAlignment(Qt::AlignCenter);
        Button_help = new QPushButton(humanai);
        Button_help->setObjectName(QString::fromUtf8("Button_help"));
        Button_help->setGeometry(QRect(20, 20, 141, 33));
        progressBar = new QProgressBar(humanai);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(150, 730, 841, 23));
        progressBar->setValue(0);
        label = new QLabel(humanai);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 726, 51, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        lcdNumber_round = new QLCDNumber(humanai);
        lcdNumber_round->setObjectName(QString::fromUtf8("lcdNumber_round"));
        lcdNumber_round->setGeometry(QRect(70, 730, 64, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(204, 232, 207, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        lcdNumber_round->setPalette(palette);
        Button_loadMap = new QPushButton(humanai);
        Button_loadMap->setObjectName(QString::fromUtf8("Button_loadMap"));
        Button_loadMap->setGeometry(QRect(20, 646, 141, 33));
        sizePolicy.setHeightForWidth(Button_loadMap->sizePolicy().hasHeightForWidth());
        Button_loadMap->setSizePolicy(sizePolicy);
        Button_start = new QPushButton(humanai);
        Button_start->setObjectName(QString::fromUtf8("Button_start"));
        Button_start->setGeometry(QRect(860, 610, 141, 33));
        sizePolicy.setHeightForWidth(Button_start->sizePolicy().hasHeightForWidth());
        Button_start->setSizePolicy(sizePolicy);
        Button_back = new QPushButton(humanai);
        Button_back->setObjectName(QString::fromUtf8("Button_back"));
        Button_back->setGeometry(QRect(860, 646, 141, 33));
        sizePolicy.setHeightForWidth(Button_back->sizePolicy().hasHeightForWidth());
        Button_back->setSizePolicy(sizePolicy);
        Button_loadAI = new QPushButton(humanai);
        Button_loadAI->setObjectName(QString::fromUtf8("Button_loadAI"));
        Button_loadAI->setGeometry(QRect(20, 610, 141, 33));
        sizePolicy.setHeightForWidth(Button_loadAI->sizePolicy().hasHeightForWidth());
        Button_loadAI->setSizePolicy(sizePolicy);

        retranslateUi(humanai);

        QMetaObject::connectSlotsByName(humanai);
    } // setupUi

    void retranslateUi(QWidget *humanai)
    {
        humanai->setWindowTitle(QApplication::translate("humanai", "Form", 0, QApplication::UnicodeUTF8));
        AI1Info->setText(QString());
        AI2Info->setText(QString());
        flag1->setText(QString());
        flag2->setText(QString());
        Button_help->setText(QApplication::translate("humanai", "\345\270\256\345\212\251", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QString());
        label->setText(QApplication::translate("humanai", "Round:", 0, QApplication::UnicodeUTF8));
        Button_loadMap->setText(QApplication::translate("humanai", "\350\275\275\345\205\245\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        Button_start->setText(QApplication::translate("humanai", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        Button_back->setText(QApplication::translate("humanai", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
        Button_loadAI->setText(QApplication::translate("humanai", "\350\275\275\345\205\245AI", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class humanai: public Ui_humanai {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUMANAI_H
