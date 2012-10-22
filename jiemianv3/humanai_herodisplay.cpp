#include "humanai_herodisplay.h"
#include <QPainter>
#include <QPixmap>
#include <QPalette>

heroDisplay::heroDisplay(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(200,100);
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/bg1.jpg")));
    setPalette(palette);
}

void heroDisplay::setHeroIndex(int HI)
{
    heroIndex = HI;
}

void heroDisplay::setSelected(bool wether)
{
    selected = wether;
}

void heroDisplay::setHeroInfo(DS14::HeroInfo HI)
{
    heroInfo = HI;
}

void heroDisplay::paintEvent(QPaintEvent *e)
{
    QPainter  paint(this);
    if (selected) paint.drawPixmap(0,0,200,100,QPixmap(":/image/kuang.png"));
    //头像

    if (heroIndex>2) paint.drawPixmap(10,37,25,25,QPixmap(":/image/hero2.png"));
    else paint.drawPixmap(10,37,25,25,QPixmap(":/image/hero1.png"));
    //血
    paint.drawText(45,15,75,20,0,QString("HP: "+QString::number(heroInfo.currentHP)+"/"+QString::number(100+10*heroInfo.heroTechTree.strenth)));
    //属性
    paint.drawText(140,15,60,20,0,QString("Str:"+QString::number(heroInfo.heroTechTree.strenth)));
    paint.drawText(140,45,60,20,0,QString("Agi:"+QString::number(heroInfo.heroTechTree.agility)));
    //技能
    if(heroInfo.missileCD==0)
    {
        paint.drawPixmap(45,40,20,20,QPixmap(":/image/missile.png"));
    }
    else
    {
        paint.drawPixmap(45,40,20,20,QPixmap(":/image/missile1.png"));
    }
    if(heroInfo.heroTechTree.fastWalkLevel>0)
    {
        if(heroInfo.fastWalkCD==0)
        {
            paint.drawPixmap(65,40,20,20,QPixmap(":/image/fastwalk.png"));
        }
        else
        {
            paint.drawPixmap(65,40,20,20,QPixmap(":/image/fastwalk1.png"));
        }
    }
    if(heroInfo.heroTechTree.stunLevel>0)
    {
        if(heroInfo.stunCD==0)
        {
            paint.drawPixmap(85,40,20,20,QPixmap(":/image/stun.png"));
        }
        else
        {
            paint.drawPixmap(85,40,20,20,QPixmap(":/image/stun1.png"));
        }
    }
    if(heroInfo.heroTechTree.attackLevel>0)
    {
        paint.drawPixmap(105,40,20,20,QPixmap(":/image/attack.png"));
    }
    //状态
    if(heroInfo.StunLast>0&&heroInfo.FastwalkLast>0)
    {
        paint.drawPixmap(45,75,20,20,QPixmap(":/image/stun.png"));
        paint.drawPixmap(65,75,20,20,QPixmap(":/image/fastwalk.png"));
    }
    else if(heroInfo.StunLast>0)
    {
        paint.drawPixmap(45,75,20,20,QPixmap(":/image/stun.png"));
    }
    else if(heroInfo.FastwalkLast>0)
    {
        paint.drawPixmap(45,75,20,20,QPixmap(":/image/fastwalk.png"));
    }
    //包子
    if(heroInfo.hasSword)
    {
        paint.drawPixmap(45,20,45,45,QPixmap(":/image/jian.png"));
    }
}
