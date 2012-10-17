#include "maindevice.h"
#include <iostream>
#include <QFile>
#include <QMessageBox>


maindevice::maindevice(const DS14::Status s, QWidget *parent) :
    QWidget(parent), state(s)
{
    setFixedSize(956,600);
    for(int i = 0;i<3;i++)
    {

        setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/bg2.jpg")));
        setPalette(palette);

        AI1Hero[i].setParent(this);
        AI2Hero[i].setParent(this);
        AI1Hero[i].setHeroIndex(i);
        AI1Hero[i].setHeroInfo(state.AI1HeroInfo[i]);
        AI1Hero[i].setGeometry(0,150*i,178,150);
        AI2Hero[i].setHeroIndex(i+3);
        AI2Hero[i].setHeroInfo(state.AI2HeroInfo[i]);
        AI2Hero[i].setGeometry(778,150*i,178,150);
        AI1Hero[i].repaint();
        AI2Hero[i].repaint();
    }
    gameDisplay.setParent(this);
    gameDisplay.setStatus(state);
    gameDisplay.setGeometry(178,0,600,600);

    AI1Info.setParent(this);
    AI2Info.setParent(this);
    AI1Info.setGeometry(20,450,100,50);
    AI1Info.setText(QString("Gold:"+QString::number(state.AI1gold)+"\nSwordNum:"+QString::number(state.potInfo.AI1PotNumber)) + QString("\n AI1"));
    AI2Info.setGeometry(778, 450, 100,50);
    AI2Info.setText(QString("AI2 \n Gold:"+QString::number(state.AI2gold)+"\nSwordNum:"+QString::number(state.potInfo.AI1PotNumber)));


}

void maindevice::repaint()
{
    for(int i = 0;i<=2;i++)
    {
        AI1Hero[i].setHeroIndex(i+1);
        AI2Hero[i].setHeroIndex(i+4);
        AI1Hero[i].setHeroInfo(state.AI1HeroInfo[i]);
        AI2Hero[i].setHeroInfo(state.AI2HeroInfo[i]);
        AI1Hero[i].setDetailPosition(QPoint(120, i*150+60));
        AI2Hero[i].setDetailPosition(QPoint(1210, i*150+60));
        AI1Hero[i].repaint();
        AI2Hero[i].repaint();
    }
    AI1Info.setText(QString("Gold:"+QString::number(state.AI1gold)+"\nSwordNum:"+QString::number(state.potInfo.AI1PotNumber)));
    AI2Info.setText(QString("Gold:"+QString::number(state.AI2gold)+"\nSwordNum:"+QString::number(state.potInfo.AI2PotNumber)));

    gameDisplay.setStatus(state);
    gameDisplay.repaint();
}

maindevice::~maindevice()
{

}

