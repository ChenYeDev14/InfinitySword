#include "herodisplay.h"
#include <QPainter>
#include <QPixmap>
#include <QPalette>
#include <QPushButton>
#include <QLabel>

using namespace DS14;
heroDisplay::heroDisplay(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(178,150);
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/bg1.jpg")));
    setPalette(palette);
    detail_button = new QPushButton(QString(tr("详细")), this);
    detail_button->setGeometry(120,75,50,25);
    connect(detail_button, SIGNAL(clicked()), this, SLOT(detail_clicked()));
    detail_label = new QLabel(this, Qt::Window);

}

heroDisplay::~heroDisplay()
{
    delete detail_button;
    detail_label->close();
    delete detail_label;
}

void heroDisplay::setDetailPosition(QPoint p)
{
    detail_label->move(p);
}

void heroDisplay::detail_clicked()
{
    detail_label->show();
    detail_label->setFocus();
}

void heroDisplay::setHeroIndex(int HI)
{
    heroIndex = HI;
}

void heroDisplay::setHeroInfo(DS14::HeroInfo HI)
{
    heroInfo = HI;

    QString text;
    if (heroIndex > 3) text = QString(tr("AI2 Hero")) + QString::number(heroIndex - 3);
    else text = QString(tr("AI1 Hero")) + QString::number(heroIndex);
    if (heroInfo.RebornWait > 0)
        text += tr("\n  (dead)\n");
    else
        text += tr("\n  (%1,%2)\n")
                .arg(heroInfo.heroPosition.x)
                .arg(heroInfo.heroPosition.y);
    text += tr("HP: %1 \nmissileCD: %2 \nfastWalkCD: %3 \nstunCD: %4 \nFastwalkLast: %5    \nRebornWait: %6")
            .arg(heroInfo.currentHP)
            .arg(heroInfo.missleCD)
            .arg((heroInfo.fastWalkCD == -1)? QString("no tech") : QString::number(heroInfo.fastWalkCD))
            .arg((heroInfo.stunCD == -1)? QString("no tech") : QString::number(heroInfo.stunCD))
            .arg(heroInfo.FastwalkLast)
            .arg(heroInfo.RebornWait);
    detail_label->setText(text);
}

void heroDisplay::paintEvent(QPaintEvent *e)
{
    QPainter * paint = new QPainter(this);
    //头像
    paint->drawPixmap(10,37,25,25,QPixmap(":/images/hero"+QString::number(heroIndex+1)+".png"));
    //血
    int index = heroIndex;
    index -= (index > 3) * 3;
    paint->drawText(5,15,30,20,0,QString("Hero"+QString::number(index)));
    paint->drawText(45,15,75,20,0,QString("HP: "+QString::number(heroInfo.currentHP)+"/"+QString::number(100+10*heroInfo.heroTechTree.strenth)));
    //属性
    paint->drawText(120,15,60,20,0,QString("Str:"+QString::number(heroInfo.heroTechTree.strenth)));
    paint->drawText(120,45,60,20,0,QString("Agi:"+QString::number(heroInfo.heroTechTree.agility)));
    //技能
    if(heroInfo.missleCD==0)
    {
        paint->drawPixmap(45,40,20,20,QPixmap(":/images/missile.png"));
    }
    else
    {
        paint->drawPixmap(45,40,20,20,QPixmap(":/images/missile1.png"));
    }
    if(heroInfo.heroTechTree.fastWalkLevel>0)
    {
        if(heroInfo.fastWalkCD==0)
        {
            paint->drawPixmap(65,40,20,20,QPixmap(":/images/fastwalk.png"));
        }
        else
        {
            paint->drawPixmap(65,40,20,20,QPixmap(":/images/fastwalk1.png"));
        }
    }
    if(heroInfo.heroTechTree.stunLevel>0)
    {
        if(heroInfo.stunCD==0)
        {
            paint->drawPixmap(85,40,20,20,QPixmap(":/images/stun.png"));
        }
        else
        {
            paint->drawPixmap(85,40,20,20,QPixmap(":/images/stun1.png"));
        }
    }
    if(heroInfo.heroTechTree.attackLevel>0)
    {
        paint->drawPixmap(105,40,20,20,QPixmap(":/images/attack.png"));
    }
    //状态
    if(heroInfo.StunLast>0&&heroInfo.FastwalkLast>0)
    {
        paint->drawPixmap(45,75,20,20,QPixmap(":/images/stun.png"));
        paint->drawPixmap(65,75,20,20,QPixmap(":/images/fastwalk.png"));
    }
    else if(heroInfo.StunLast>0)
    {
        paint->drawPixmap(45,75,20,20,QPixmap(":/images/stun.png"));
    }
    else if(heroInfo.FastwalkLast>0)
    {
        paint->drawPixmap(45,75,20,20,QPixmap(":/images/fastwalk.png"));
    }
    //包子
    if(heroInfo.hasPot)
    {
        paint->drawPixmap(45,20,45,45,QPixmap(":/images/jian.png"));
    }
}
