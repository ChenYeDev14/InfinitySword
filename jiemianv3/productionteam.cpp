#include <QtGui>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ProductionTeam.h"

ProductionTeam::ProductionTeam(QWidget *parent) :
    QWidget(parent)
{
    resize(1000,564);

    const char* pcszStr ="�����Ŷ�";
    QString s = QString::fromLocal8Bit(pcszStr);
    this->setWindowTitle(s);
    const char* pcszStr0="\n\n\n\n\n\n\n\n\n\n";
    QString s0 = QString::fromLocal8Bit(pcszStr0);
    label=new QLabel(s0);
    productionteamtiltle=new ProductionTeamTiltle;
    QPalette palette = label->palette();
    palette.setColor(QPalette::Foreground,QColor(255,0,0));
    label->setPalette(palette);
    const char* pcszStr1 = "                                                                                       \n"
                           "                                    ��       ��  ë  ��       ��  ��  Ĳ  ��  ��  ��  ��  ��  ׿  ��  ��  ��  ��       ��  ��  ��  ��  ��  ��  ��       ƽ  ��  ׯ  ��  ��  ��       ��  ��  ��  ��  ��       ��  ��  ��  ��  ��  ��  ��       3  ��  ��  ��  ʷ  ��  ��       ��  ��  ��  ��  ��       ��  ��  ��  ��  Ǯ  ��  ��  ��                     \n"
                           "                                                                                       \n"
                           "                                    ��       ��  ��  ��       ��  ��  ͫ  ʫ  ��  ɺ  ��  ��  ��  ��  ��  ��  ��       ��  ��  Х  ��  ��  ��  ��       ̨  ��  ��  ��  Զ  ��       ��  ��  ��  ��  ��       վ  ��  ��  ��  ��  ��  ��       D  ��  ��  ��  ΰ  ��  ��       ��  ٻ  ��  ��  ��       ��  ��  ��  ��  ¡  ��  ��  ��                     \n"
                           "                                                                                       \n"
                           "                                    ��           �D  ��       ָ  ��      ��          ��      �  ��  ��  ��  ��           ��  ��  ��  ��  ��  ��               ��                               ��  ��           ��          ��      ��          ��  ��  ��  ��  �h  ��           �  ��  ��               ��  Ң          ��  ��  ��                     \n"
                           "                                                                                       \n"
                           "                                    ��                        ��                                                                                                                                                                                                                                                                                          \n"
                           "                                                                                        \n" ;
    QString s1 = QString::fromLocal8Bit(pcszStr1);
    productionteamtiltle->setText(s1);
    QFont font = label->font();
    font.setFamily("��������");
    //font.setPointSize(20);
    label->setFont(font);
    const char* pcszStr2="\n\n\n\n\n\n\n\n\n\n";
    QString s2=QString::fromLocal8Bit(pcszStr2);
    space=new QLabel(s2);
    const char* pcszStr3="����������";
    QString s3 = QString::fromLocal8Bit(pcszStr3);
    QVBoxLayout* mainlayout=new QVBoxLayout;
    QHBoxLayout* hlayout=new QHBoxLayout;
    QHBoxLayout* tlayout=new QHBoxLayout;
    hlayout->addSpacing(this->width()-100);
    tlayout->addSpacing(100);
    tlayout->addWidget(productionteamtiltle);
    tlayout->addSpacing(100);
    mainlayout->addWidget(label);
    mainlayout->addLayout(tlayout);
    mainlayout->addWidget(space);
    mainlayout->addLayout(hlayout);
    setLayout(mainlayout);
}
