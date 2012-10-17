/********************************************************************************
** Form generated from reading UI file 'replaywindow.ui'
**
** Created: Wed Oct 17 01:47:12 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAYWINDOW_H
#define UI_REPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplayWindow
{
public:
    QPushButton *loadButton;
    QPushButton *startButton;
    QPushButton *stopButton_1;
    QPushButton *pushButton_2;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QFrame *line;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QFrame *line_2;
    QLineEdit *lineEdit_4;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QFrame *line_3;

    void setupUi(QWidget *ReplayWindow)
    {
        if (ReplayWindow->objectName().isEmpty())
            ReplayWindow->setObjectName(QString::fromUtf8("ReplayWindow"));
        ReplayWindow->resize(1024, 768);
        ReplayWindow->setMinimumSize(QSize(0, 601));
        loadButton = new QPushButton(ReplayWindow);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(10, 250, 141, 31));
        startButton = new QPushButton(ReplayWindow);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 300, 141, 31));
        stopButton_1 = new QPushButton(ReplayWindow);
        stopButton_1->setObjectName(QString::fromUtf8("stopButton_1"));
        stopButton_1->setGeometry(QRect(10, 350, 141, 31));
        pushButton_2 = new QPushButton(ReplayWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 400, 141, 31));
        horizontalSlider = new QSlider(ReplayWindow);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 680, 651, 31));
        horizontalSlider->setMaximum(2400);
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(ReplayWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(680, 680, 71, 31));
        pushButton = new QPushButton(ReplayWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(830, 680, 141, 31));
        pushButton_3 = new QPushButton(ReplayWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 450, 141, 31));
        pushButton_6 = new QPushButton(ReplayWindow);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 500, 141, 31));
        horizontalSlider_2 = new QSlider(ReplayWindow);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(true);
        horizontalSlider_2->setGeometry(QRect(40, 630, 161, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(58, 240, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(167, 255, 216, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(112, 247, 187, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(29, 120, 79, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(38, 160, 105, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(156, 247, 206, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        horizontalSlider_2->setPalette(palette);
        horizontalSlider_2->setCursor(QCursor(Qt::UpArrowCursor));
        horizontalSlider_2->setSliderPosition(99);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(ReplayWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 630, 61, 31));
        label_2->setTextFormat(Qt::AutoText);
        label_3 = new QLabel(ReplayWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 630, 61, 31));
        label_3->setTextFormat(Qt::AutoText);
        label = new QLabel(ReplayWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(860, 90, 91, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(ReplayWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(850, 130, 113, 31));
        lineEdit->setFont(font);
        lineEdit->setLayoutDirection(Qt::LeftToRight);
        lineEdit->setFrame(true);
        lineEdit->setEchoMode(QLineEdit::Normal);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        label_4 = new QLabel(ReplayWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(860, 170, 91, 31));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(ReplayWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(850, 210, 113, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setLayoutDirection(Qt::LeftToRight);
        lineEdit_2->setFrame(true);
        lineEdit_2->setEchoMode(QLineEdit::Normal);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        label_5 = new QLabel(ReplayWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(860, 250, 91, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(ReplayWindow);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(850, 290, 113, 31));
        lineEdit_3->setFont(font);
        lineEdit_3->setLayoutDirection(Qt::LeftToRight);
        lineEdit_3->setFrame(true);
        lineEdit_3->setEchoMode(QLineEdit::Normal);
        lineEdit_3->setAlignment(Qt::AlignCenter);
        lineEdit_3->setReadOnly(true);
        line = new QFrame(ReplayWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(820, 350, 171, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(ReplayWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(860, 540, 91, 31));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        lineEdit_6 = new QLineEdit(ReplayWindow);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(850, 580, 113, 31));
        lineEdit_6->setFont(font);
        lineEdit_6->setLayoutDirection(Qt::LeftToRight);
        lineEdit_6->setAutoFillBackground(false);
        lineEdit_6->setFrame(true);
        lineEdit_6->setEchoMode(QLineEdit::Normal);
        lineEdit_6->setAlignment(Qt::AlignCenter);
        lineEdit_6->setReadOnly(true);
        line_2 = new QFrame(ReplayWindow);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(820, 640, 171, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lineEdit_4 = new QLineEdit(ReplayWindow);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(850, 420, 113, 31));
        lineEdit_4->setFont(font);
        lineEdit_4->setLayoutDirection(Qt::LeftToRight);
        lineEdit_4->setFrame(true);
        lineEdit_4->setEchoMode(QLineEdit::Normal);
        lineEdit_4->setAlignment(Qt::AlignCenter);
        lineEdit_4->setReadOnly(true);
        label_7 = new QLabel(ReplayWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(860, 380, 91, 31));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        lineEdit_5 = new QLineEdit(ReplayWindow);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(850, 500, 113, 31));
        lineEdit_5->setFont(font);
        lineEdit_5->setLayoutDirection(Qt::LeftToRight);
        lineEdit_5->setFrame(true);
        lineEdit_5->setEchoMode(QLineEdit::Normal);
        lineEdit_5->setAlignment(Qt::AlignCenter);
        lineEdit_5->setReadOnly(true);
        label_8 = new QLabel(ReplayWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(860, 460, 91, 31));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        line_3 = new QFrame(ReplayWindow);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(820, 70, 171, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        loadButton->raise();
        startButton->raise();
        stopButton_1->raise();
        pushButton_2->raise();
        horizontalSlider->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_6->raise();
        horizontalSlider_2->raise();
        label_2->raise();
        label_3->raise();
        spinBox->raise();
        label->raise();
        lineEdit->raise();
        label_4->raise();
        lineEdit_2->raise();
        label_5->raise();
        lineEdit_3->raise();
        line->raise();
        label_6->raise();
        lineEdit_6->raise();
        line_2->raise();
        lineEdit_4->raise();
        label_7->raise();
        lineEdit_5->raise();
        label_8->raise();
        line_3->raise();

        retranslateUi(ReplayWindow);

        QMetaObject::connectSlotsByName(ReplayWindow);
    } // setupUi

    void retranslateUi(QWidget *ReplayWindow)
    {
        ReplayWindow->setWindowTitle(QApplication::translate("ReplayWindow", "Form", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("ReplayWindow", "\350\275\275\345\205\245\345\233\236\346\224\276\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("ReplayWindow", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        stopButton_1->setText(QApplication::translate("ReplayWindow", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ReplayWindow", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ReplayWindow", "\350\277\224\345\233\236\344\270\212\347\272\247", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ReplayWindow", "\344\270\212\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ReplayWindow", "\344\270\213\344\270\200\346\255\245", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ReplayWindow", "\351\276\237\351\200\237", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ReplayWindow", "\347\245\236\351\200\237", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ReplayWindow", "\351\230\237\344\274\2151\357\274\210\347\272\242\357\274\211", 0, QApplication::UnicodeUTF8));
        lineEdit->setInputMask(QString());
        lineEdit->setText(QApplication::translate("ReplayWindow", "\351\230\237\344\274\215\345\220\215", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ReplayWindow", "\351\207\221\351\222\261", 0, QApplication::UnicodeUTF8));
        lineEdit_2->setInputMask(QString());
        lineEdit_2->setText(QApplication::translate("ReplayWindow", "\351\207\221\351\222\261", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ReplayWindow", "\345\256\235\345\211\221\346\225\260", 0, QApplication::UnicodeUTF8));
        lineEdit_3->setInputMask(QString());
        lineEdit_3->setText(QApplication::translate("ReplayWindow", "\345\256\235\345\211\221\346\225\260", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ReplayWindow", "\345\256\235\345\211\221\346\225\260", 0, QApplication::UnicodeUTF8));
        lineEdit_6->setInputMask(QString());
        lineEdit_6->setText(QApplication::translate("ReplayWindow", "\345\256\235\345\211\221\346\225\260", 0, QApplication::UnicodeUTF8));
        lineEdit_4->setInputMask(QString());
        lineEdit_4->setText(QApplication::translate("ReplayWindow", "\351\230\237\344\274\215\345\220\215", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ReplayWindow", "\351\230\237\344\274\2152\357\274\210\350\223\235\357\274\211", 0, QApplication::UnicodeUTF8));
        lineEdit_5->setInputMask(QString());
        lineEdit_5->setText(QApplication::translate("ReplayWindow", "\351\207\221\351\222\261", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ReplayWindow", "\351\207\221\351\222\261", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReplayWindow: public Ui_ReplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAYWINDOW_H
