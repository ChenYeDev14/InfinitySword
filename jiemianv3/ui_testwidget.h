/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created: Wed Oct 24 02:37:38 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestWidget
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *test1;
    QLabel *test2;
    QLabel *test3;
    QLabel *test4;
    QLabel *test5;
    QLabel *test6;
    QLabel *test7;
    QLabel *test8;
    QLabel *test9;
    QLabel *test10;
    QProgressBar *progressBar;
    QLabel *label_nickname;

    void setupUi(QWidget *TestWidget)
    {
        if (TestWidget->objectName().isEmpty())
            TestWidget->setObjectName(QString::fromUtf8("TestWidget"));
        TestWidget->resize(1024, 768);
        pushButton = new QPushButton(TestWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 660, 141, 31));
        lineEdit = new QLineEdit(TestWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 50, 250, 31));
        pushButton_2 = new QPushButton(TestWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 50, 141, 31));
        pushButton_3 = new QPushButton(TestWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(630, 210, 141, 31));
        pushButton_4 = new QPushButton(TestWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(680, 260, 141, 31));
        pushButton_5 = new QPushButton(TestWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(570, 310, 141, 31));
        pushButton_6 = new QPushButton(TestWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(500, 360, 141, 31));
        pushButton_7 = new QPushButton(TestWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(680, 460, 141, 31));
        pushButton_8 = new QPushButton(TestWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(590, 510, 141, 31));
        pushButton_9 = new QPushButton(TestWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(610, 410, 141, 31));
        pushButton_10 = new QPushButton(TestWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(510, 560, 141, 31));
        pushButton_11 = new QPushButton(TestWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(580, 610, 141, 31));
        pushButton_12 = new QPushButton(TestWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(650, 650, 141, 31));
        label = new QLabel(TestWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 240, 151, 371));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/image/form.png);"));
        label_2 = new QLabel(TestWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 150, 151, 51));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/image/title.png);"));
        label_3 = new QLabel(TestWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 240, 54, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_3->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_4 = new QLabel(TestWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 277, 54, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette1);
        label_4->setFont(font);
        label_5 = new QLabel(TestWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 315, 54, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette2);
        label_5->setFont(font);
        label_6 = new QLabel(TestWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 355, 54, 31));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_6->setPalette(palette3);
        label_6->setFont(font);
        label_7 = new QLabel(TestWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(40, 390, 54, 31));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_7->setPalette(palette4);
        label_7->setFont(font);
        label_8 = new QLabel(TestWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(40, 430, 54, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_8->setPalette(palette5);
        label_8->setFont(font);
        label_9 = new QLabel(TestWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(40, 467, 54, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_9->setPalette(palette6);
        label_9->setFont(font);
        label_10 = new QLabel(TestWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 503, 54, 31));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_10->setPalette(palette7);
        label_10->setFont(font);
        label_11 = new QLabel(TestWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(40, 540, 54, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_11->setPalette(palette8);
        label_11->setFont(font);
        label_12 = new QLabel(TestWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 580, 54, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_12->setPalette(palette9);
        label_12->setFont(font);
        test1 = new QLabel(TestWidget);
        test1->setObjectName(QString::fromUtf8("test1"));
        test1->setGeometry(QRect(120, 240, 54, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test1->setPalette(palette10);
        test1->setFont(font);
        test1->setAlignment(Qt::AlignCenter);
        test2 = new QLabel(TestWidget);
        test2->setObjectName(QString::fromUtf8("test2"));
        test2->setGeometry(QRect(120, 277, 54, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test2->setPalette(palette11);
        test2->setFont(font);
        test2->setAlignment(Qt::AlignCenter);
        test3 = new QLabel(TestWidget);
        test3->setObjectName(QString::fromUtf8("test3"));
        test3->setGeometry(QRect(120, 315, 54, 31));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test3->setPalette(palette12);
        test3->setFont(font);
        test3->setAlignment(Qt::AlignCenter);
        test4 = new QLabel(TestWidget);
        test4->setObjectName(QString::fromUtf8("test4"));
        test4->setGeometry(QRect(120, 355, 54, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test4->setPalette(palette13);
        test4->setFont(font);
        test4->setAlignment(Qt::AlignCenter);
        test5 = new QLabel(TestWidget);
        test5->setObjectName(QString::fromUtf8("test5"));
        test5->setGeometry(QRect(120, 390, 54, 31));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test5->setPalette(palette14);
        test5->setFont(font);
        test5->setAlignment(Qt::AlignCenter);
        test6 = new QLabel(TestWidget);
        test6->setObjectName(QString::fromUtf8("test6"));
        test6->setGeometry(QRect(120, 430, 54, 31));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test6->setPalette(palette15);
        test6->setFont(font);
        test6->setAlignment(Qt::AlignCenter);
        test7 = new QLabel(TestWidget);
        test7->setObjectName(QString::fromUtf8("test7"));
        test7->setGeometry(QRect(120, 467, 54, 31));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test7->setPalette(palette16);
        test7->setFont(font);
        test7->setAlignment(Qt::AlignCenter);
        test8 = new QLabel(TestWidget);
        test8->setObjectName(QString::fromUtf8("test8"));
        test8->setGeometry(QRect(120, 503, 54, 31));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test8->setPalette(palette17);
        test8->setFont(font);
        test8->setAlignment(Qt::AlignCenter);
        test9 = new QLabel(TestWidget);
        test9->setObjectName(QString::fromUtf8("test9"));
        test9->setGeometry(QRect(120, 540, 54, 31));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test9->setPalette(palette18);
        test9->setFont(font);
        test9->setAlignment(Qt::AlignCenter);
        test10 = new QLabel(TestWidget);
        test10->setObjectName(QString::fromUtf8("test10"));
        test10->setGeometry(QRect(120, 580, 54, 31));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        test10->setPalette(palette19);
        test10->setFont(font);
        test10->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(TestWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 730, 941, 23));
        progressBar->setValue(24);
        label_nickname = new QLabel(TestWidget);
        label_nickname->setObjectName(QString::fromUtf8("label_nickname"));
        label_nickname->setGeometry(QRect(38, 160, 541, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_nickname->setFont(font1);

        retranslateUi(TestWidget);

        QMetaObject::connectSlotsByName(TestWidget);
    } // setupUi

    void retranslateUi(QWidget *TestWidget)
    {
        TestWidget->setWindowTitle(QApplication::translate("TestWidget", "TestWidget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TestWidget", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("TestWidget", "\350\275\275\345\205\245AI", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("TestWidget", "\347\254\254\345\215\201\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("TestWidget", "\347\254\254\344\271\235\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("TestWidget", "\347\254\254\345\205\253\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\203\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("TestWidget", "\347\254\254\345\205\255\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("TestWidget", "\347\254\254\344\272\224\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("TestWidget", "\347\254\254\345\233\233\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\211\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("TestWidget", "\347\254\254\344\272\214\345\205\263", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\200\345\205\263", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\200\345\205\263", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TestWidget", "\347\254\254\344\272\214\345\205\263", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\211\345\205\263", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TestWidget", "\347\254\254\345\233\233\345\205\263", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TestWidget", "\347\254\254\344\272\224\345\205\263", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TestWidget", "\347\254\254\345\205\255\345\205\263", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TestWidget", "\347\254\254\344\270\203\345\205\263", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("TestWidget", "\347\254\254\345\205\253\345\205\263", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("TestWidget", "\347\254\254\344\271\235\345\205\263", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("TestWidget", "\347\254\254\345\215\201\345\205\263", 0, QApplication::UnicodeUTF8));
        test1->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test2->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test3->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test4->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test5->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test6->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test7->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test8->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test9->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        test10->setText(QApplication::translate("TestWidget", "0", 0, QApplication::UnicodeUTF8));
        label_nickname->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TestWidget: public Ui_TestWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
