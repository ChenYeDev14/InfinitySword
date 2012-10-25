/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created: Thu Oct 25 20:30:53 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_login;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_code;
    QCheckBox *checkBox_remember;

    void setupUi(QWidget *LogInWidget)
    {
        if (LogInWidget->objectName().isEmpty())
            LogInWidget->setObjectName(QString::fromUtf8("LogInWidget"));
        LogInWidget->resize(1024, 768);
        label = new QLabel(LogInWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 200, 91, 31));
        label->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(LogInWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 250, 91, 31));
        label_2->setSizeIncrement(QSize(0, 0));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        pushButton_login = new QPushButton(LogInWidget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(100, 350, 141, 31));
        pushButton_2 = new QPushButton(LogInWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 350, 141, 31));
        lineEdit_user = new QLineEdit(LogInWidget);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setGeometry(QRect(210, 200, 171, 31));
        lineEdit_code = new QLineEdit(LogInWidget);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));
        lineEdit_code->setGeometry(QRect(210, 250, 171, 31));
        lineEdit_code->setFrame(true);
        lineEdit_code->setEchoMode(QLineEdit::Password);
        lineEdit_code->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        checkBox_remember = new QCheckBox(LogInWidget);
        checkBox_remember->setObjectName(QString::fromUtf8("checkBox_remember"));
        checkBox_remember->setGeometry(QRect(290, 300, 91, 16));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        checkBox_remember->setPalette(palette);

        retranslateUi(LogInWidget);

        QMetaObject::connectSlotsByName(LogInWidget);
    } // setupUi

    void retranslateUi(QWidget *LogInWidget)
    {
        LogInWidget->setWindowTitle(QApplication::translate("LogInWidget", "LogInWidget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LogInWidget", "\351\202\256\347\256\261\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LogInWidget", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("LogInWidget", "\347\231\273\351\231\206", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LogInWidget", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        checkBox_remember->setText(QApplication::translate("LogInWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogInWidget: public Ui_LogInWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
