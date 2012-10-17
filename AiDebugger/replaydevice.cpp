#include "replaydevice.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <math.h>
#include <QPainter>

#include <iostream>

replayDevice::replayDevice(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(600,600);
    this->setCursor(QCursor(QPixmap(":/images/nc.png")));
}


QPoint replayDevice::toProCo(DS14::Coordinate gameCo)
{
    QPoint z;
    z.setX(300+gameCo.x/4);
    z.setY(300-gameCo.y/4);
    return z;
}

DS14::Coordinate replayDevice::toGameCo(QPoint programCo)
{
    DS14::Coordinate z;
    z.x = double((programCo.rx()-300))*4;
    z.y = double((300-programCo.ry()))*4;
    return z;
}

void replayDevice::paintEvent(QPaintEvent *e)
{
    QPainter * painter = new QPainter(this);
    //画背景
    painter->drawPixmap(0,0,600,600,QPixmap(":/images/background.png"));
    //画减速区域
    for(int i = 0;i<=gameStatus.mapInfo.slowDownAreaNumber-1;i++)
    {
        painter->drawPixmap(toProCo(gameStatus.mapInfo.slowDownArea[i]).rx()-double(DS14::RADIUS_OF_SLOWDOWNAREA)/4,toProCo(gameStatus.mapInfo.slowDownArea[i]).ry()-double(DS14::RADIUS_OF_SLOWDOWNAREA)/4,double(2*DS14::RADIUS_OF_SLOWDOWNAREA)/4,double(2*DS14::RADIUS_OF_SLOWDOWNAREA)/4,QPixmap(":/images/slow.png"));
    }
    //画爆炸区域
    for(int i = 0;i<=5;i++)
    {
        if(gameStatus.missleArea[i].real)
        {
            painter->drawPixmap(toProCo(gameStatus.missleArea[i].centerPosition).rx()-double(gameStatus.missleArea[i].radius)/4,toProCo(gameStatus.missleArea[i].centerPosition).ry()-double(gameStatus.missleArea[i].radius)/4,double(gameStatus.missleArea[i].radius*2)/4,double(gameStatus.missleArea[i].radius*2)/4,QPixmap(":/images/missilearea.png"));
        }
    }
    //画基地
    painter->drawPixmap(toProCo(gameStatus.mapInfo.AIBases[0]).rx()-double(DS14::BASE_RADIUS)/4,toProCo(gameStatus.mapInfo.AIBases[0]).ry()-double(DS14::BASE_RADIUS)/4,double(DS14::BASE_RADIUS*2)/4,double(DS14::BASE_RADIUS*2)/4,QPixmap(":/images/base1.png"));
    painter->drawPixmap(toProCo(gameStatus.mapInfo.AIBases[1]).rx()-double(DS14::BASE_RADIUS)/4,toProCo(gameStatus.mapInfo.AIBases[1]).ry()-double(DS14::BASE_RADIUS)/4,double(DS14::BASE_RADIUS*2)/4,double(DS14::BASE_RADIUS*2)/4,QPixmap(":/images/base2.png"));
    //画出生点
    for(int i = 0;i<3;i++)
    {
        painter->drawPixmap(toProCo(gameStatus.mapInfo.AIHeroBirthPlace[0][i]).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.mapInfo.AIHeroBirthPlace[0][i]).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/birthPoint1.png"));
        painter->drawPixmap(toProCo(gameStatus.mapInfo.AIHeroBirthPlace[1][i]).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.mapInfo.AIHeroBirthPlace[1][i]).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/birthPoint2.png"));

    }

    //画路障
    for(int i = 0;i<=gameStatus.mapInfo.roadBlockNumber-1;i++)
    {
        painter->drawPixmap(toProCo(gameStatus.mapInfo.roadBlock[i]).rx()-double(DS14::RADIUS_OF_ROADBLOCK)/4,toProCo(gameStatus.mapInfo.roadBlock[i]).ry()-double(DS14::RADIUS_OF_ROADBLOCK)/4,double(2*DS14::RADIUS_OF_ROADBLOCK)/4,double(2*DS14::RADIUS_OF_ROADBLOCK)/4,QPixmap(":/images/stuck.png"));
    }

    //画地图上面的英雄
    for(int i = 1;i<=6;i++)
    {
        if(i<=3)
        {
            if (gameStatus.AI1HeroInfo[i-1].hasPot)
                painter->drawPixmap(toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/hero1s.png"));
            else
                painter->drawPixmap(toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/hero1.png"));
        }
        else
        {
            if (gameStatus.AI2HeroInfo[i-4].hasPot)
                painter->drawPixmap(toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/hero2s.png"));
            else
                painter->drawPixmap(toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/images/hero2.png"));
        }
    }

    //画包子
    for(int i = 0;i<gameStatus.potInfo.groundNumber;i++)
    {
        painter->drawPixmap(toProCo(gameStatus.potInfo.groundPots[i]).rx()-double(DS14::POT_RADIUS)/4,toProCo(gameStatus.potInfo.groundPots[i]).ry()-double(DS14::POT_RADIUS)/4,double(2*DS14::POT_RADIUS)/4,double(2*DS14::POT_RADIUS)/4,QPixmap(":/images/jian.png"));
    }
    if(!gameStatus.potInfo.QingFenCD)
    {
        DS14::Coordinate center;
        center.x = 0;
        center.y = 0;
        painter->drawPixmap(toProCo(center).rx()-double(DS14::POT_RADIUS)/4,toProCo(center).ry()-double(DS14::POT_RADIUS)/4,double(DS14::POT_RADIUS)*2/4,double(DS14::POT_RADIUS*2/4),QPixmap(":/images/jian.png"));
    }

}

void replayDevice::setStatus(DS14::Status GS)
{
    gameStatus = GS;
}


