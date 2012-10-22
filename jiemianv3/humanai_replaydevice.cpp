#include "humanai_replaydevice.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <math.h>
#include <QPainter>

#include <iostream>

replayDevice::replayDevice(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(600,600);
    heroChoosen = 0;
    attacking = false;
    missiling = false;
    for(int i = 0;i<=2;i++)
    {
        userCommand.heroOrder[i] = DS14::walk;
        userCommand.target[i].x = gameStatus.AI1HeroInfo[i].heroPosition.x;
        userCommand.target[i].y = gameStatus.AI1HeroInfo[i].heroPosition.y;
        for(int j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
        {
            userCommand.updateScience[i][j] = DS14::none;
        }
    }
    this->setCursor(QCursor(QPixmap(":/image/nc.png")));
}

double replayDevice::dist(double x1, double y1, double x2, double y2)
{
    double z = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return z;
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
    QPainter painter(this);
    //画背景
    painter.drawPixmap(0,0,600,600,QPixmap(":/image/humanai_back.png"));
    //画减速区域
    for(int i = 0;i<=gameStatus.mapInfo.slowDownAreaNumber-1;i++)
    {
        painter.drawPixmap(toProCo(gameStatus.mapInfo.slowDownArea[i]).rx()-double(DS14::RADIUS_OF_SLOWDOWNAREA)/4,toProCo(gameStatus.mapInfo.slowDownArea[i]).ry()-double(DS14::RADIUS_OF_SLOWDOWNAREA)/4,double(2*DS14::RADIUS_OF_SLOWDOWNAREA)/4,double(2*DS14::RADIUS_OF_SLOWDOWNAREA)/4,QPixmap(":/image/slow.png"));
    }
    //画爆炸区域
    for(int i = 0;i<=5;i++)
    {
        if(gameStatus.missileArea[i].real)
        {
            painter.drawPixmap(toProCo(gameStatus.missileArea[i].centerPosition).rx()-double(gameStatus.missileArea[i].radius)/4,toProCo(gameStatus.missileArea[i].centerPosition).ry()-double(gameStatus.missileArea[i].radius)/4,double(gameStatus.missileArea[i].radius*2)/4,double(gameStatus.missileArea[i].radius*2)/4,QPixmap(":/image/missilearea.png"));
        }
    }
    //画基地
    painter.drawPixmap(toProCo(gameStatus.mapInfo.AIBases[0]).rx()-double(DS14::BASE_RADIUS)/4,toProCo(gameStatus.mapInfo.AIBases[0]).ry()-double(DS14::BASE_RADIUS)/4,double(DS14::BASE_RADIUS*2)/4,double(DS14::BASE_RADIUS*2)/4,QPixmap(":/image/base1.png"));
    painter.drawPixmap(toProCo(gameStatus.mapInfo.AIBases[1]).rx()-double(DS14::BASE_RADIUS)/4,toProCo(gameStatus.mapInfo.AIBases[1]).ry()-double(DS14::BASE_RADIUS)/4,double(DS14::BASE_RADIUS*2)/4,double(DS14::BASE_RADIUS*2)/4,QPixmap(":/image/base2.png"));
    //画出生点
    for(int i = 0;i<3;i++)
    {
        painter.drawPixmap(toProCo(gameStatus.mapInfo.AIHeroBirthPlace[0][i]).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.mapInfo.AIHeroBirthPlace[0][i]).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/birthPoint1.png"));
    }
    for(int i = 0;i<3;i++)
    {
        painter.drawPixmap(toProCo(gameStatus.mapInfo.AIHeroBirthPlace[1][i]).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.mapInfo.AIHeroBirthPlace[1][i]).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/birthPoint2.png"));
    }

    //画路障
    for(int i = 0;i<=gameStatus.mapInfo.roadBlockNumber-1;i++)
    {
        painter.drawPixmap(toProCo(gameStatus.mapInfo.roadBlock[i]).rx()-double(DS14::RADIUS_OF_ROADBLOCK)/4,toProCo(gameStatus.mapInfo.roadBlock[i]).ry()-double(DS14::RADIUS_OF_ROADBLOCK)/4,double(2*DS14::RADIUS_OF_ROADBLOCK)/4,double(2*DS14::RADIUS_OF_ROADBLOCK)/4,QPixmap(":/image/stuck.png"));
    }

    //标记选择的英雄
    if (humanSide == 2)
        painter.drawPixmap(toProCo(gameStatus.AI2HeroInfo[heroChoosen].heroPosition).rx()-double(DS14::HERO_RADIUS)/4-2,toProCo(gameStatus.AI2HeroInfo[heroChoosen].heroPosition).ry()-double(DS14::HERO_RADIUS)/4-2,double(2*DS14::HERO_RADIUS)/4+4,double(2*DS14::HERO_RADIUS)/4+4,QPixmap(":/image/select.png"));
    else painter.drawPixmap(toProCo(gameStatus.AI1HeroInfo[heroChoosen].heroPosition).rx()-double(DS14::HERO_RADIUS)/4-2,toProCo(gameStatus.AI1HeroInfo[heroChoosen].heroPosition).ry()-double(DS14::HERO_RADIUS)/4-2,double(2*DS14::HERO_RADIUS)/4+4,double(2*DS14::HERO_RADIUS)/4+4,QPixmap(":/image/select.png"));

    //画地图上面的英雄
    for(int i = 1;i<=6;i++)
    {
        if(i<=3)
        {
            if (gameStatus.AI1HeroInfo[i-1].hasSword)
                painter.drawPixmap(toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/hero1s.png"));
            else painter.drawPixmap(toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI1HeroInfo[i-1].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/hero1.png"));
        }
        else
        {
            if (gameStatus.AI2HeroInfo[i-4].hasSword)
                painter.drawPixmap(toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/hero2s.png"));
            else painter.drawPixmap(toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).rx()-double(DS14::HERO_RADIUS)/4,toProCo(gameStatus.AI2HeroInfo[i-4].heroPosition).ry()-double(DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,double(2*DS14::HERO_RADIUS)/4,QPixmap(":/image/hero2.png"));
        }
    }
    //画包子
    for(int i = 0;i<gameStatus.swordInfo.groundNumber;i++)
    {
        painter.drawPixmap(toProCo(gameStatus.swordInfo.groundSwords[i]).rx()-double(DS14::SWORD_RADIUS)/4,toProCo(gameStatus.swordInfo.groundSwords[i]).ry()-double(DS14::SWORD_RADIUS)/4,double(2*DS14::SWORD_RADIUS)/4,double(2*DS14::SWORD_RADIUS)/4,QPixmap(":/image/jian.png"));
    }
    if(!gameStatus.swordInfo.CentreSwordCD)
    {
        DS14::Coordinate center;
        center.x = 0;
        center.y = 0;
        painter.drawPixmap(toProCo(center).rx()-double(DS14::SWORD_RADIUS)/4,toProCo(center).ry()-double(DS14::SWORD_RADIUS)/4,double(DS14::SWORD_RADIUS)*2/4,double(DS14::SWORD_RADIUS*2/4),QPixmap(":/image/jian.png"));
    }

}

void replayDevice::setStatus(DS14::Status GS)
{
    gameStatus = GS;
}

void replayDevice::mousePressEvent(QMouseEvent *e)
{
    if(attacking == false && missiling == false)
    {
        if(e->button() == Qt::RightButton)
        {
            QPoint currentPositon;
            currentPositon.setX(e->x());
            currentPositon.setY(e->y());
            DS14::Coordinate tmpco = toGameCo(currentPositon);
            userCommand.heroOrder[heroChoosen] = DS14::walk;
            userCommand.target[heroChoosen].x = tmpco.x;
            userCommand.target[heroChoosen].y = tmpco.y;
        }
    }
    else if(missiling == true)
    {
        if(e->button() == Qt::LeftButton)
        {
            QPoint currentPositon;
            currentPositon.setX(e->x());
            currentPositon.setY(e->y());
            DS14::Coordinate tmpco = toGameCo(currentPositon);
            userCommand.heroOrder[heroChoosen] = DS14::launchMissile;
            userCommand.target[heroChoosen].x = tmpco.x;
            userCommand.target[heroChoosen].y = tmpco.y;
            missiling = false;
            this->setCursor(QCursor(QPixmap(":/image/nc.png")));
        }
        else if(e->button() == Qt::RightButton)
        {
            missiling = false;
            this->setCursor(QCursor(QPixmap(":/image/nc.png")));
        }
    }
    else if(attacking == true)
    {
        if(e->button() == Qt::LeftButton)
        {
            QPoint currentPositon;
            currentPositon.setX(e->x());
            currentPositon.setY(e->y());
            DS14::Coordinate tmpco = toGameCo(currentPositon);
            DS14::Coordinate target;
            target.x = -2500;
            target.y = -2500;
            if (humanSide == 1)
                for(int i = 0 ;i<=2;i++)
                {
                    if(dist(tmpco.x,tmpco.y,gameStatus.AI2HeroInfo[i].heroPosition.x,gameStatus.AI2HeroInfo[i].heroPosition.y)<=50)
                    {
                        target = gameStatus.AI2HeroInfo[i].heroPosition;
                        break;
                    }
                }
            else
                for(int i = 0 ;i<=2;i++)
                {
                     if(dist(tmpco.x,tmpco.y,gameStatus.AI1HeroInfo[i].heroPosition.x,gameStatus.AI1HeroInfo[i].heroPosition.y)<=50)
                    {
                        target = gameStatus.AI1HeroInfo[i].heroPosition;
                        break;
                    }
                }
            if(target.x != -2500)
            {
                userCommand.heroOrder[heroChoosen] = DS14::attack;
                userCommand.target[heroChoosen] = target;
            }
            attacking = false;
            this->setCursor(QCursor(QPixmap(":/image/nc.png")));
            }
            else if(e->button() == Qt::RightButton)
            {
                attacking = false;
                this->setCursor(QCursor(QPixmap(":/image/nc.png")));
            }
    }
}

void replayDevice::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == 0x31)
    {
        heroChoosen = 0;
        attacking = false;
        missiling = false;
    }
    else if(e->key() == 0x32)
    {
        heroChoosen = 1;
        attacking = false;
        missiling = false;
    }
    else if(e->key() == 0x33)
    {
        heroChoosen = 2;
        attacking = false;
        missiling = false;
    }
    if(e->key() == 0x41 &&
            (humanSide == 1 && gameStatus.AI1HeroInfo[heroChoosen].heroTechTree.attackLevel > 0 ||
            humanSide == 2 && gameStatus.AI2HeroInfo[heroChoosen].heroTechTree.attackLevel > 0))
    {
        attacking = true;
        missiling = false;
        this->setCursor(QCursor(QPixmap(":/image/nc1.png")));
    }
    if(e->key() == 0x43 &&
            (humanSide == 1 && gameStatus.AI1HeroInfo[heroChoosen].missileCD == 0 ||
            humanSide == 2 && gameStatus.AI2HeroInfo[heroChoosen].missileCD == 0))
    {
        missiling = true;
        attacking = false;
        this->setCursor(QCursor(QPixmap(":/image/nc1.png")));
    }
    if(e->key() == 0x54)
    {
        userCommand.heroOrder[heroChoosen] = DS14::stun;
    }
    if(e->key() == 0x57)
    {
        userCommand.heroOrder[heroChoosen] = DS14::fastWalk;
    }
    /*
     update: Y for agility
     U for strenth
     I for fastwalk
     O for stun
     P for attack
     */
        if(e->key() == 0x55)
        {
            int j;
            for(j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                if(userCommand.updateScience[heroChoosen][j] == DS14::none)
                {
                    break;
                }
            }
            if(userCommand.updateScience[heroChoosen][j] == DS14::none)
            {
                userCommand.updateScience[heroChoosen][j] = DS14::updateAgility;
            }
        }
        else if(e->key() == 0x59)
        {
            int j;
            for(j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                if(userCommand.updateScience[heroChoosen][j] == DS14::none)
                {
                    break;
                }
            }
            if(userCommand.updateScience[heroChoosen][j] == DS14::none)
            {
                userCommand.updateScience[heroChoosen][j] = DS14::updateStrenth;
            }
        }
        else if(e->key() == 0x49)
        {
            int j;
            for(j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                if(userCommand.updateScience[heroChoosen][j] == DS14::none)
                {
                    break;
                }
            }
            if(userCommand.updateScience[heroChoosen][j] == DS14::none)
            {
                userCommand.updateScience[heroChoosen][j] = DS14::updateFastWalk;
            }
        }
        else if(e->key() == 0x4f)
        {
            int j;
            for(j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                if(userCommand.updateScience[heroChoosen][j] == DS14::none)
                {
                    break;
                }
            }
            if(userCommand.updateScience[heroChoosen][j] == DS14::none)
            {
                userCommand.updateScience[heroChoosen][j] = DS14::updateStun;
            }
        }
        else if(e->key() == 0x50)
        {
            int j;
            for(j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
            {
                if(userCommand.updateScience[heroChoosen][j] == DS14::none)
                {
                    break;
                }
            }
            if(userCommand.updateScience[heroChoosen][j] == DS14::none)
            {
                userCommand.updateScience[heroChoosen][j] = DS14::updateAttack;
            }
        }
}

DS14::PlayerCommand replayDevice::getHumanCommand()
{
    DS14::PlayerCommand userCommand1 = userCommand;

    for(int i = 0;i<=2;i++)
    {
        for(int j = 0;j<DS14::MAX_UPDATE_NUMBER_PER_ROUND;j++)
        {
            userCommand.updateScience[i][j] = DS14::none;
        }
    }

    return userCommand1;
}

