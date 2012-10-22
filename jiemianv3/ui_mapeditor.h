/********************************************************************************
** Form generated from reading UI file 'mapeditor.ui'
**
** Created: Sat Oct 20 16:32:32 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPEDITOR_H
#define UI_MAPEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapEditor
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *frame;
    QLabel *label;
    QFrame *line;
    QFrame *line_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QFrame *line_3;
    QFrame *line_4;
    QPushButton *pushButton_5;
    QRadioButton *radioButton_8;
    QRadioButton *radioButton_6;
    QPushButton *pushButton_6;

    void setupUi(QWidget *MapEditor)
    {
        if (MapEditor->objectName().isEmpty())
            MapEditor->setObjectName(QString::fromUtf8("MapEditor"));
        MapEditor->resize(1024, 768);
        pushButton = new QPushButton(MapEditor);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 250, 141, 31));
        pushButton_2 = new QPushButton(MapEditor);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 310, 141, 31));
        pushButton_3 = new QPushButton(MapEditor);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 370, 141, 31));
        pushButton_4 = new QPushButton(MapEditor);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 430, 141, 31));
        frame = new QFrame(MapEditor);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(830, 50, 181, 721));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 81, 22));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFocusPolicy(Qt::NoFocus);
        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 60, 51, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(130, 60, 51, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        radioButton = new QRadioButton(frame);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 90, 180, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font1.setPointSize(11);
        font1.setItalic(false);
        radioButton->setFont(font1);
        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 130, 180, 30));
        radioButton_2->setFont(font1);
        radioButton_3 = new QRadioButton(frame);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 170, 180, 30));
        radioButton_3->setFont(font1);
        radioButton_4 = new QRadioButton(frame);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 210, 180, 30));
        radioButton_4->setFont(font1);
        radioButton_5 = new QRadioButton(frame);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 250, 180, 30));
        radioButton_5->setFont(font1);
        line_3 = new QFrame(frame);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(0, 460, 181, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(frame);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 700, 181, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 660, 141, 31));
        radioButton_8 = new QRadioButton(frame);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setGeometry(QRect(10, 330, 180, 30));
        radioButton_8->setFont(font1);
        radioButton_6 = new QRadioButton(frame);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 290, 180, 30));
        radioButton_6->setFont(font1);
        pushButton_6 = new QPushButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 410, 141, 31));
        label->raise();
        radioButton_8->raise();
        radioButton_5->raise();
        radioButton_3->raise();
        line->raise();
        radioButton_6->raise();
        line_2->raise();
        line_3->raise();
        radioButton->raise();
        radioButton_4->raise();
        line_4->raise();
        pushButton_5->raise();
        radioButton_2->raise();
        pushButton_6->raise();

        retranslateUi(MapEditor);

        QMetaObject::connectSlotsByName(MapEditor);
    } // setupUi

    void retranslateUi(QWidget *MapEditor)
    {
        MapEditor->setWindowTitle(QApplication::translate("MapEditor", "MapEditor", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MapEditor", "\346\226\260\345\273\272", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MapEditor", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MapEditor", "\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MapEditor", "\345\217\246\345\255\230\344\270\272", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MapEditor", "\345\234\260\345\233\276\345\205\203\347\264\240", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MapEditor", "\345\267\261\346\226\271\344\270\273\345\237\272\345\234\260                         ", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MapEditor", "\346\225\214\346\226\271\344\270\273\345\237\272\345\234\260                         ", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MapEditor", "\345\207\217\351\200\237\345\234\260\345\270\246                         ", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MapEditor", "\347\246\201\346\255\242\351\200\232\350\241\214\345\214\272\345\237\237                         ", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("MapEditor", "\345\267\261\346\226\271\350\213\261\351\233\204\345\207\272\347\224\237\347\202\271                         ", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MapEditor", "\347\246\273\345\274\200", 0, QApplication::UnicodeUTF8));
        radioButton_8->setText(QApplication::translate("MapEditor", "\345\210\240\351\231\244\345\205\203\347\264\240                         ", 0, QApplication::UnicodeUTF8));
        radioButton_6->setText(QApplication::translate("MapEditor", "\346\225\214\346\226\271\350\213\261\351\233\204\345\207\272\347\224\237\347\202\271                         ", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MapEditor", "\345\210\267\347\231\275", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MapEditor: public Ui_MapEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPEDITOR_H
