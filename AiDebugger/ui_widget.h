/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed Oct 17 02:05:26 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_AI;
    QLineEdit *lineEdit_AI;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Map;
    QLineEdit *lineEdit_Map;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QProgressBar *progressBar;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_round;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider_3;
    QCheckBox *checkBox_auto;
    QLabel *label_8;
    QLabel *label_show_round;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1406, 718);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 290, 75, 23));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 216, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_AI = new QPushButton(layoutWidget);
        pushButton_AI->setObjectName(QString::fromUtf8("pushButton_AI"));

        horizontalLayout->addWidget(pushButton_AI);

        lineEdit_AI = new QLineEdit(layoutWidget);
        lineEdit_AI->setObjectName(QString::fromUtf8("lineEdit_AI"));

        horizontalLayout->addWidget(lineEdit_AI);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 110, 216, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_Map = new QPushButton(layoutWidget1);
        pushButton_Map->setObjectName(QString::fromUtf8("pushButton_Map"));

        horizontalLayout_3->addWidget(pushButton_Map);

        lineEdit_Map = new QLineEdit(layoutWidget1);
        lineEdit_Map->setObjectName(QString::fromUtf8("lineEdit_Map"));

        horizontalLayout_3->addWidget(lineEdit_Map);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(23, 32, 149, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(260, 670, 991, 21));
        progressBar->setValue(24);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(90, 160, 31, 31));
        horizontalSlider->setMaximum(1);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(24, 170, 54, 12));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(144, 170, 54, 12));
        horizontalSlider_2 = new QSlider(Widget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(62, 240, 141, 19));
        horizontalSlider_2->setMinimum(10);
        horizontalSlider_2->setMaximum(1000000);
        horizontalSlider_2->setSingleStep(1);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(25, 214, 54, 12));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(28, 242, 31, 16));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(210, 240, 31, 16));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(260, 30, 961, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(83, 670, 111, 20));
        label_round = new QLabel(Widget);
        label_round->setObjectName(QString::fromUtf8("label_round"));
        label_round->setGeometry(QRect(190, 670, 61, 21));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 330, 75, 23));
        horizontalSlider_3 = new QSlider(Widget);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(260, 640, 961, 19));
        horizontalSlider_3->setMaximum(2400);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        checkBox_auto = new QCheckBox(Widget);
        checkBox_auto->setObjectName(QString::fromUtf8("checkBox_auto"));
        checkBox_auto->setGeometry(QRect(210, 640, 51, 16));
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(80, 640, 71, 16));
        label_show_round = new QLabel(Widget);
        label_show_round->setObjectName(QString::fromUtf8("label_show_round"));
        label_show_round->setGeometry(QRect(140, 640, 71, 16));

        retranslateUi(Widget);

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "DS14_AIDebugger", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        pushButton_AI->setText(QApplication::translate("Widget", "\350\275\275\345\205\245\345\257\271\346\210\230AI", 0, QApplication::UnicodeUTF8));
        pushButton_Map->setText(QApplication::translate("Widget", "\350\275\275\345\205\245\345\234\260\345\233\276", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\350\260\203\350\257\225AI\351\200\211\350\276\271\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\350\277\220\350\241\214\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\350\260\203\350\257\225\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\345\233\236\346\224\276\351\200\237\345\272\246\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\351\276\237\351\200\237", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\347\245\236\351\200\237", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "\346\270\270\346\210\217\345\267\262\350\277\233\350\241\214\345\210\260 Round", 0, QApplication::UnicodeUTF8));
        label_round->setText(QString());
        pushButton_2->setText(QApplication::translate("Widget", "\347\273\223\346\235\237\345\257\271\346\210\230", 0, QApplication::UnicodeUTF8));
        checkBox_auto->setText(QApplication::translate("Widget", "\350\207\252\345\212\250", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "\345\233\236\346\224\276Round:", 0, QApplication::UnicodeUTF8));
        label_show_round->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
