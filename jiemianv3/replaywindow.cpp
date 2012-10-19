#include "replaywindow.h"
#include "ui_replaywindow.h"
#include <QMovie>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QFileDialog>
#include <QDebug>
#include <QPixmap>
#include <QSize>
#include <QString>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <fstream>
#include <QPainter>
#include <QTimer>
#include <QStateMachine>
#include <QPropertyAnimation>
#include <QSignalTransition>
#include <QEventTransition>
#include <QDebug>
#include <QTime>

using namespace DS14;

const double X=195.0;
const double Y=78.0;
const double W=540.0;
const double H=540.0;
static int Time=250;
static int round=0;
static bool pause=false;
static bool timerison=false;

ReplayWindow::ReplayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplayWindow),
    ifStatus(false),
    isRun(false),
    roundNum(2400)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    timerison=false;

    timer=new QTimer;

//设置滚轮和数字显示的链接
    ui->spinBox->setRange(0,roundNum);
    ui->horizontalSlider->setRange(0,roundNum);
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
    QObject::connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)));
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(ChangeRound(int)));
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timerDone()));

//调速的滚轮设置
    ui->horizontalSlider_2->setRange(100,500);
    ui->horizontalSlider_2->setValue(250);


    ui->stopButton_1->setEnabled(false);
    ui->startButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);


//设置6个英雄
    hero[0]=new QLabel(this);
    hero[1]=new QLabel(this);
    hero[2]=new QLabel(this);
    hero[3]=new QLabel(this);
    hero[4]=new QLabel(this);
    hero[5]=new QLabel(this);

    for ( int i = 0 ; i < 6 ; i++ ){
        hero[i]->setMouseTracking(true);
    }

    Label_showInfo =new QLabel(this);
    Label_showInfo->hide();
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::yellow);
    Label_showInfo->setPalette(pe);
    pe.setColor(QPalette::WindowText,Qt::red);
    ui->label->setPalette(pe);
    ui->label_4->setPalette(pe);
    ui->label_5->setPalette(pe);
    pe.setColor(QPalette::WindowText,Qt::blue);
    ui->label_6->setPalette(pe);
    ui->label_7->setPalette(pe);
    ui->label_8->setPalette(pe);

    ui->lineEdit->setText(tr("队伍名"));
    ui->lineEdit_2->setText(tr("金钱"));
    ui->lineEdit_3->setText(tr("宝剑数"));
    ui->lineEdit_4->setText(tr("队伍名"));
    ui->lineEdit_5->setText(tr("金钱"));
    ui->lineEdit_6->setText(tr("宝剑数"));


    connect(this,SIGNAL(show(int,int)),this,SLOT(Label_show(int,int)));

//设置格式

}

ReplayWindow::~ReplayWindow()
{
    delete ui;
}

//载入回放文件
void ReplayWindow::on_loadButton_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "RepFiles/", tr("FILES (*.rep)"));
    //fileName

    ReplayFile rFile;
        if (!rFile.OpenFile(fileName))
        {
            if ( fileName == "" )
                return;
            QMessageBox box;
            box.setWindowTitle(tr("错误！"));
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("回放加载错误！"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
            return;
        }
        if (!rFile.ReadInitialInfo(pInfo[0], pInfo[1]))
        {
            QMessageBox box;
            box.setWindowTitle(tr("错误！"));
            box.setIcon(QMessageBox::Warning);
            box.setText(tr("回放版本号错误！"));
            box.setStandardButtons(QMessageBox::Yes);
            box.exec();
            return;
        }
        rFile.ReadAllRoundInfo(roundNum, statusList);
        int winner;
        rFile.ReadWinner(winner);
        ifStatus =true;
        if ( timer->isActive() == true )
            timer->stop();
        ui->startButton->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->stopButton_1->setEnabled(false);
        ui->pushButton_2->setEnabled(false);

        ui->spinBox->setRange(0,roundNum);
        ui->horizontalSlider->setRange(0,roundNum);
        ui->spinBox->setValue(0);

        if ( picture.count() != 0 )
            picture.clear();
        QString num;

        ui->lineEdit->setText(tr("%1").arg(QString::fromWCharArray(pInfo[0].teamName)));
        ui->lineEdit_4->setText(tr("%1").arg(QString::fromWCharArray(pInfo[1].teamName)));
        num.setNum(0);
        ui->lineEdit_2->setText(num);
        ui->lineEdit_3->setText(num);
        ui->lineEdit_5->setText(num);
        ui->lineEdit_6->setText(num);

 //       qDebug() << statusList[0]->mapInfo.roadBlockNumber;

        this->repaint();
}

//开始按钮
void ReplayWindow::on_startButton_clicked()
{
    static int time=0;//点击开始的次数，没用

    pause =false;

    timer->start(Time/2);

    ui->startButton->setEnabled(false);
    ui->stopButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);

    time++;


}

//SLOT1
void ReplayWindow::timerStop()
{
    if( ifStatus == true && pause == true )
    {
        ui->startButton->setEnabled(true);
        ui->stopButton_1->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
    }
}

//SLOT3
void ReplayWindow::timerDone()
{
    if(round>roundNum){
        timer->stop();

        return;
    }
    if (!pause){
    round=round+1;
    ui->spinBox->setValue(round);
    if(round==1){
            //全部内容摆放出来，可以放一个渐变效果？
        hero_set_(0,read_hero_x(0,1),read_hero_y(0,1),true);
        hero_set_(1,read_hero_x(1,1),read_hero_y(1,1),true);
        hero_set_(2,read_hero_x(2,1),read_hero_y(2,1),true);
        hero_set_(3,read_hero_x(3,1),read_hero_y(3,1),true);
        hero_set_(4,read_hero_x(4,1),read_hero_y(4,1),true);
        hero_set_(5,read_hero_x(5,1),read_hero_y(5,1),true);
    }
    if(round >1 && round <= roundNum){
        //完成和上一回合之间的动画
        QStateMachine *machine = new QStateMachine;     //新建状态机

        hero_set_(0,read_hero_x(0,round),read_hero_y(0,round),false);
        hero_set_(1,read_hero_x(1,round),read_hero_y(1,round),false);
        hero_set_(2,read_hero_x(2,round),read_hero_y(2,round),false);
        hero_set_(3,read_hero_x(3,round),read_hero_y(3,round),false);
        hero_set_(4,read_hero_x(4,round),read_hero_y(4,round),false);
        hero_set_(5,read_hero_x(5,round),read_hero_y(5,round),false);

        QState *state2 = new QState(machine);

        state2->assignProperty(hero[0],"geometry",hero[0]->geometry());
        state2->assignProperty(hero[1],"geometry",hero[1]->geometry());
        state2->assignProperty(hero[2],"geometry",hero[2]->geometry());
        state2->assignProperty(hero[3],"geometry",hero[3]->geometry());
        state2->assignProperty(hero[4],"geometry",hero[4]->geometry());
        state2->assignProperty(hero[5],"geometry",hero[5]->geometry());

        QState *state1 = new QState(machine);     //状态1

        hero_set_(0,read_hero_x(0,round-1),read_hero_y(0,round-1),true);
        hero_set_(1,read_hero_x(1,round-1),read_hero_y(1,round-1),true);
        hero_set_(2,read_hero_x(2,round-1),read_hero_y(2,round-1),true);
        hero_set_(3,read_hero_x(3,round-1),read_hero_y(3,round-1),true);
        hero_set_(4,read_hero_x(4,round-1),read_hero_y(4,round-1),true);
        hero_set_(5,read_hero_x(5,round-1),read_hero_y(5,round-1),true);

        state1->assignProperty(hero[0],"geometry",hero[0]->geometry());    //绑定button的geomertry属性
        state1->assignProperty(hero[1],"geometry",hero[1]->geometry());
        state1->assignProperty(hero[2],"geometry",hero[2]->geometry());
        state1->assignProperty(hero[3],"geometry",hero[3]->geometry());
        state1->assignProperty(hero[4],"geometry",hero[4]->geometry());
        state1->assignProperty(hero[5],"geometry",hero[5]->geometry());

        machine->setInitialState(state1);

        QPropertyAnimation *ani0=new QPropertyAnimation(hero[0],"geometry");
        ani0->setDuration(Time/2-10);
        ani0->setEasingCurve(QEasingCurve::Linear);   //动画效果
        QPropertyAnimation *ani1=new QPropertyAnimation(hero[1],"geometry");
        ani1->setDuration(Time/2-10);
        ani1->setEasingCurve(QEasingCurve::Linear);
        QPropertyAnimation *ani2=new QPropertyAnimation(hero[2],"geometry");
        ani2->setDuration(Time/2-10);
        ani2->setEasingCurve(QEasingCurve::Linear);
        QPropertyAnimation *ani3=new QPropertyAnimation(hero[3],"geometry");
        ani3->setDuration(Time/2-10);
        ani3->setEasingCurve(QEasingCurve::Linear);
        QPropertyAnimation *ani4=new QPropertyAnimation(hero[4],"geometry");
        ani4->setDuration(Time/2-10);
        ani4->setEasingCurve(QEasingCurve::Linear);
        QPropertyAnimation *ani5=new QPropertyAnimation(hero[5],"geometry");
        ani5->setDuration(Time/2-10);
        ani5->setEasingCurve(QEasingCurve::Linear);

        QAbstractTransition *transition1=state1->addTransition(state2);      //动画触发信号
        transition1->addAnimation(ani0);
        transition1->addAnimation(ani1);
        transition1->addAnimation(ani2);
        transition1->addAnimation(ani3);
        transition1->addAnimation(ani4);
        transition1->addAnimation(ani5);
        machine->start();     //开启状态机
    }
    }
}

void ReplayWindow::closeEvent(QCloseEvent *event)
{

}

//背景设置
void ReplayWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1024,768,QPixmap(":/image/2DGround3.png"));
    if ( picture.count() != 0 )
        picture.clear();
    if (ifStatus){
        painter.drawPixmap(X+W/2-50*W/2400,Y+H/2-50*H/2400,100*W/2400,100*H/2400,QPixmap(":/image/center.png"));
        int x = statusList[0]->mapInfo.AIBases[0].x;
        int y = statusList[0]->mapInfo.AIBases[0].y;
        painter.drawPixmap(transfer_horizontal(x)-100*W/2400,transfer_vertical(y)-100*H/2400,200*W/2400,200*H/2400,QPixmap(":/image/base1.png"));
        QLabel* pic = new QLabel();
        pic->setGeometry(transfer_horizontal(x)-100*W/2400,transfer_vertical(y)-100*H/2400,200*W/2400,200*H/2400);
        picture.append(pic);
        pic = new QLabel();
        x = statusList[0]->mapInfo.AIBases[1].x;
        y = statusList[0]->mapInfo.AIBases[1].y;
        painter.drawPixmap(transfer_horizontal(x)-100*W/2400,transfer_vertical(y)-100*H/2400,200*W/2400,200*H/2400,QPixmap(":/image/base2.png"));
        pic->setGeometry(transfer_horizontal(x)-100*W/2400,transfer_vertical(y)-100*H/2400,200*W/2400,200*H/2400);
        picture.append(pic);

        for ( int i = 0 ; i < statusList[0]->mapInfo.roadBlockNumber ; i++){
            int x = statusList[0]->mapInfo.roadBlock[i].x;
            int y = statusList[0]->mapInfo.roadBlock[i].y;
            painter.drawPixmap(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,100*W/2400,100*H/2400,QPixmap(":/image/stuck.png"));
        }
        for ( int i = 0 ; i < statusList[0]->mapInfo.slowDownAreaNumber ; i++){
            int x = statusList[0]->mapInfo.slowDownArea[i].x;
            int y = statusList[0]->mapInfo.slowDownArea[i].y;
            painter.drawPixmap(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,100*W/2400,100*H/2400,QPixmap(":/image/slow.png"));
        }
        for ( int i = 0 ; i < 3 ; i++ ){
            int x = statusList[0]->mapInfo.AIHeroBirthPlace[0][i].x;
            int y = statusList[0]->mapInfo.AIHeroBirthPlace[0][i].y;
            painter.drawPixmap(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,100*W/2400,100*H/2400,QPixmap(":/image/birthPoint1.png"));
        }
        for ( int i = 0 ; i < 3 ; i++ ){
            int x = statusList[0]->mapInfo.AIHeroBirthPlace[1][i].x;
            int y = statusList[0]->mapInfo.AIHeroBirthPlace[1][i].y;
            painter.drawPixmap(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,100*W/2400,100*H/2400,QPixmap(":/image/birthPoint2.png"));
        }
        for ( int i = 0 ; i < picture.count() ; i++ ){
            picture.at(i)->setMouseTracking(true);
        }
        if ( ui->spinBox->value() != 0 ){
        for ( int i = 0 ; i < 6 ; i++ ){
            if ( statusList[ ui->spinBox->value() - 1 ]->missileArea[i].real ){
                int x = statusList[ui->spinBox->value()-1]->missileArea[i].centerPosition.x;
                int y = statusList[ui->spinBox->value()-1]->missileArea[i].centerPosition.y;
                int r = statusList[ui->spinBox->value()-1]->missileArea[i].radius;
                painter.drawPixmap(transfer_horizontal(x)-r*W/2400,transfer_vertical(y)-r*H/2400,2*r*W/2400,2*r*H/2400,QPixmap(":/image/missilearea.png"));
            }
        }
        for ( int i = 0 ; i < statusList[ui->spinBox->value()-1]->swordInfo.groundNumber ; i++){
            int x = statusList[ui->spinBox->value()-1]->swordInfo.groundSwords[i].x;
            int y = statusList[ui->spinBox->value()-1]->swordInfo.groundSwords[i].y;
            painter.drawPixmap(transfer_horizontal(x)-SWORD_RADIUS*W/2400,transfer_vertical(y)-SWORD_RADIUS*H/2400,2*SWORD_RADIUS*W/2400,2*SWORD_RADIUS*H/2400,QPixmap(":/image/jian.png"));
        }
        }

    }
}




//鼠标的事件
void ReplayWindow::mouseMoveEvent(QMouseEvent *event)
{
    bool b = true;
    if ( ui->spinBox->value() != 0 ){
        for ( int i = 0 ; i < 6 ; i++ ){
            if ( hero[i]->x() < event->x() &&  hero[i]->x() + hero[i]->width() > event->x() &&
                 hero[i]->y() < event->y() && hero[i]->y() + hero[i]->height() > event->y()){
                emit show(i,ui->horizontalSlider->value());
                b = false;
                return;
            }
        }
    }
    for ( int i = 0 ; i < picture.count() ; i++ )
        if ( picture.at(i)->x() < event->x() &&  picture.at(i)->x() + picture.at(i)->width() > event->x() &&
              picture.at(i)->y() < event->y() && picture.at(i)->y() + picture.at(i)->height() > event->y()){
             emit show(i,-1);
             b= false;
             return;
            }
    if ( ui->spinBox->value() != 0 )
    if ( event->x()>X+W/2-50*W/2400 && event->x()<X+W/2+50*W/2400 &&
         event->y()>Y+H/2-50*H/2400 && event->y()<Y+H/2+50*H/2400){
        emit show(10,ui->horizontalSlider->value());
        b=false;
        return;
    }
    if ( b ){
        Label_showInfo->hide();
    }
}

void ReplayWindow::mousePressEvent(QMouseEvent *event)
{

}

void ReplayWindow::mouseReleaseEvent(QMouseEvent *event)
{

}

//前一步
void ReplayWindow::on_pushButton_3_clicked()
{
    if(ui->spinBox->value()==0)
    {
        ui->pushButton_3->setEnabled(false);
    }
    else
    {
        int i = ui->spinBox->value()-1;
        ui->spinBox->setValue(i);
        round--;
        show_onemove_back(i+1,i);
        if ( i == 0 ){
            sleep(Time);
            for ( int j = 0 ; j < 6 ; j++ ){
                hero[j]->hide();
            }
        }
        //donghua
    }
    if(ui->spinBox->value()<2400)
        ui->pushButton_6->setEnabled(true);
}

//后一步
void ReplayWindow::on_pushButton_6_clicked()
{
    if(ui->spinBox->value()==roundNum)
        ui->pushButton_6->setEnabled(false);
    else
    {
        int i = ui->spinBox->value()+1;
        ui->spinBox->setValue(i);
        round++;
        show_onemove_forward(i-1,i);
    }
    if(ui->spinBox->value()>0)
        ui->pushButton_3->setEnabled(true);
}

//实现回放一步的动画
void ReplayWindow::show_onemove_back(int i,int j)
{
    //i-1=j
    QStateMachine *machine_backward = new QStateMachine;     //新建状态机

    hero_set_(0,read_hero_x(0,j),read_hero_y(0,j),false);
    hero_set_(1,read_hero_x(1,j),read_hero_y(1,j),false);
    hero_set_(2,read_hero_x(2,j),read_hero_y(2,j),false);
    hero_set_(3,read_hero_x(3,j),read_hero_y(3,j),false);
    hero_set_(4,read_hero_x(4,j),read_hero_y(4,j),false);
    hero_set_(5,read_hero_x(5,j),read_hero_y(5,j),false);

    QState *state2 = new QState(machine_backward);

    state2->assignProperty(hero[0],"geometry",hero[0]->geometry());
    state2->assignProperty(hero[1],"geometry",hero[1]->geometry());
    state2->assignProperty(hero[2],"geometry",hero[2]->geometry());
    state2->assignProperty(hero[3],"geometry",hero[3]->geometry());
    state2->assignProperty(hero[4],"geometry",hero[4]->geometry());
    state2->assignProperty(hero[5],"geometry",hero[5]->geometry());

    QState *state1 = new QState(machine_backward);     //状态1

    hero_set_(0,read_hero_x(0,i),read_hero_y(0,i),true);
    hero_set_(1,read_hero_x(1,i),read_hero_y(1,i),true);
    hero_set_(2,read_hero_x(2,i),read_hero_y(2,i),true);
    hero_set_(3,read_hero_x(3,i),read_hero_y(3,i),true);
    hero_set_(4,read_hero_x(4,i),read_hero_y(4,i),true);
    hero_set_(5,read_hero_x(5,i),read_hero_y(5,i),true);

    state1->assignProperty(hero[0],"geometry",hero[0]->geometry());    //绑定button的geomertry属性
    state1->assignProperty(hero[1],"geometry",hero[1]->geometry());
    state1->assignProperty(hero[2],"geometry",hero[2]->geometry());
    state1->assignProperty(hero[3],"geometry",hero[3]->geometry());
    state1->assignProperty(hero[4],"geometry",hero[4]->geometry());
    state1->assignProperty(hero[5],"geometry",hero[5]->geometry());

    machine_backward->setInitialState(state1);     //state1设为初始化状态

    QPropertyAnimation *ani0=new QPropertyAnimation(hero[0],"geometry");
    ani0->setDuration(Time/2-10);
    ani0->setEasingCurve(QEasingCurve::Linear);   //动画效果
    QPropertyAnimation *ani1=new QPropertyAnimation(hero[1],"geometry");
    ani1->setDuration(Time/2-10);
    ani1->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani2=new QPropertyAnimation(hero[2],"geometry");
    ani2->setDuration(Time/2-10);
    ani2->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani3=new QPropertyAnimation(hero[3],"geometry");
    ani3->setDuration(Time/2-10);
    ani3->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani4=new QPropertyAnimation(hero[4],"geometry");
    ani4->setDuration(Time/2-10);
    ani4->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani5=new QPropertyAnimation(hero[5],"geometry");
    ani5->setDuration(Time/2-10);
    ani5->setEasingCurve(QEasingCurve::Linear);

    //
    QAbstractTransition *transition2 = state1->addTransition(state2);      //动画触发信号

    transition2->addAnimation(ani0);
    transition2->addAnimation(ani1);
    transition2->addAnimation(ani2);
    transition2->addAnimation(ani3);
    transition2->addAnimation(ani4);
    transition2->addAnimation(ani5);
    machine_backward->start();     //开启状态机
}

//实现前进一步的动画
void ReplayWindow::show_onemove_forward(int i,int j)
{
//i+1=j
    QStateMachine *machine_forward = new QStateMachine;     //新建状态机
    QState *state1 = new QState(machine_forward);     //状态1
    hero_set_(0,read_hero_x(0,j),read_hero_y(0,j),false);
    hero_set_(1,read_hero_x(1,j),read_hero_y(1,j),false);
    hero_set_(2,read_hero_x(2,j),read_hero_y(2,j),false);
    hero_set_(3,read_hero_x(3,j),read_hero_y(3,j),false);
    hero_set_(4,read_hero_x(4,j),read_hero_y(4,j),false);
    hero_set_(5,read_hero_x(5,j),read_hero_y(5,j),false);

    QState *state2 = new QState(machine_forward);
    state2->assignProperty(hero[0],"geometry",hero[0]->geometry());
    state2->assignProperty(hero[1],"geometry",hero[1]->geometry());
    state2->assignProperty(hero[2],"geometry",hero[2]->geometry());
    state2->assignProperty(hero[3],"geometry",hero[3]->geometry());
    state2->assignProperty(hero[4],"geometry",hero[4]->geometry());
    state2->assignProperty(hero[5],"geometry",hero[5]->geometry());

    hero_set_(0,read_hero_x(0,i),read_hero_y(0,i),true);
    hero_set_(1,read_hero_x(1,i),read_hero_y(1,i),true);
    hero_set_(2,read_hero_x(2,i),read_hero_y(2,i),true);
    hero_set_(3,read_hero_x(3,i),read_hero_y(3,i),true);
    hero_set_(4,read_hero_x(4,i),read_hero_y(4,i),true);
    hero_set_(5,read_hero_x(5,i),read_hero_y(5,i),true);

    state1->assignProperty(hero[0],"geometry",hero[0]->geometry());    //绑定button的geomertry属性
    state1->assignProperty(hero[1],"geometry",hero[1]->geometry());
    state1->assignProperty(hero[2],"geometry",hero[2]->geometry());
    state1->assignProperty(hero[3],"geometry",hero[3]->geometry());
    state1->assignProperty(hero[4],"geometry",hero[4]->geometry());
    state1->assignProperty(hero[5],"geometry",hero[5]->geometry());

    machine_forward->setInitialState(state1);

    QPropertyAnimation *ani0=new QPropertyAnimation(hero[0],"geometry");
    ani0->setDuration(Time/2-10);
    ani0->setEasingCurve(QEasingCurve::Linear);   //动画效果
    QPropertyAnimation *ani1=new QPropertyAnimation(hero[1],"geometry");
    ani1->setDuration(Time/2-10);
    ani1->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani2=new QPropertyAnimation(hero[2],"geometry");
    ani2->setDuration(Time/2-10);
    ani2->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani3=new QPropertyAnimation(hero[3],"geometry");
    ani3->setDuration(Time/2-10);
    ani3->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani4=new QPropertyAnimation(hero[4],"geometry");
    ani4->setDuration(Time/2-10);
    ani4->setEasingCurve(QEasingCurve::Linear);
    QPropertyAnimation *ani5=new QPropertyAnimation(hero[5],"geometry");
    ani5->setDuration(Time/2-10);
    ani5->setEasingCurve(QEasingCurve::Linear);

    //
    QAbstractTransition *transition1=state1->addTransition(state2);      //动画触发信号
    transition1->addAnimation(ani0);
    transition1->addAnimation(ani1);
    transition1->addAnimation(ani2);
    transition1->addAnimation(ani3);
    transition1->addAnimation(ani4);
    transition1->addAnimation(ani5);
    machine_forward->start();     //开启状态机
}

void ReplayWindow::hero_set_(int n,double x,double y,bool show)//n取0——5，x,y为坐标
{
    switch (n)
    {
    case 0:
        hero[0]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[0]->setPixmap(QPixmap(":/image/hero1.png"));
        if ( statusList[ui->spinBox->value()-1]->AI1HeroInfo[0].hasSword )
            hero[0]->setPixmap(QPixmap(":/image/hero1s.png"));
        if(show==true)hero[0]->show();
        break;
    case 1:
        hero[1]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[1]->setPixmap(QPixmap(":/image/hero1.png"));
        if ( statusList[ui->spinBox->value()-1]->AI1HeroInfo[1].hasSword )
            hero[1]->setPixmap(QPixmap(":/image/hero1s.png"));
        if(show==true)hero[1]->show();
        break;
    case 2:
        hero[2]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[2]->setPixmap(QPixmap(":/image/hero1.png"));
        if ( statusList[ui->spinBox->value()-1]->AI1HeroInfo[2].hasSword )
            hero[2]->setPixmap(QPixmap(":/image/hero1s.png"));
        if(show==true)hero[2]->show();
        break;
    case 3:
        hero[3]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[3]->setPixmap(QPixmap(":/image/hero2.png"));
        if ( statusList[ui->spinBox->value()-1]->AI2HeroInfo[0].hasSword )
            hero[3]->setPixmap(QPixmap(":/image/hero2s.png"));
        if(show==true)hero[3]->show();
        break;
    case 4:
        hero[4]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[4]->setPixmap(QPixmap(":/image/hero2.png"));
        if ( statusList[ui->spinBox->value()-1]->AI2HeroInfo[1].hasSword )
            hero[4]->setPixmap(QPixmap(":/image/hero2s.png"));
        if(show==true)hero[4]->show();
        break;
    case 5:
        hero[5]->setGeometry(transfer_horizontal(x)-50*W/2400,transfer_vertical(y)-50*H/2400,2*50*W/2400,2*50*H/2400);
        hero[5]->setPixmap(QPixmap(":/image/hero2.png"));
        if ( statusList[ui->spinBox->value()-1]->AI2HeroInfo[2].hasSword )
            hero[5]->setPixmap(QPixmap(":/image/hero2s.png"));
        if(show==true)hero[5]->show();
        break;
    default:break;
    }
}

double ReplayWindow::transfer_horizontal(double x)
{
    return x*W/2400+X+W/2;
}

double ReplayWindow::transfer_vertical(double y)
{
    return -y*H/2400+Y+H/2;
}

//速度滚轮
void ReplayWindow::on_horizontalSlider_2_valueChanged(int value)
{
    Time=value;
}

void ReplayWindow::on_horizontalSlider_2_sliderPressed()
{
    ui->horizontalSlider_2->setAcceptDrops(true);
    if ( timer->isActive() == true){
        isRun = true;
        timer->stop();
    }
}

void ReplayWindow::on_horizontalSlider_2_sliderReleased()
{
    if (isRun){
        isRun = false;
        timer->start(Time);
    }
}

//回合数滚轮
void ReplayWindow::on_horizontalSlider_sliderPressed()
{
    if ( timer->isActive() == true){
        isRun = true;
        timer->stop();
    }
}

void ReplayWindow::on_horizontalSlider_sliderReleased()
{
    if (isRun){
        isRun = false;
        timer->start(Time);
    }
}


double ReplayWindow::read_hero_x(int n,int ROUND)
{
    if ( ROUND != 0 )
        ROUND--;
    if ( n < 3 )
        return statusList[ROUND]->AI1HeroInfo[n].heroPosition.x;
    else
        return statusList[ROUND]->AI2HeroInfo[n-3].heroPosition.x;
}

double ReplayWindow::read_hero_y(int n,int ROUND)
{
    if ( ROUND != 0 )
        ROUND--;
    if ( n < 3 )
        return statusList[ROUND]->AI1HeroInfo[n].heroPosition.y;
    else
        return statusList[ROUND]->AI2HeroInfo[n-3].heroPosition.y;
}

//暂停
void ReplayWindow::on_stopButton_1_clicked()
{
    pause =true;
    timer->stop();
    ui->startButton->setEnabled(true);
    ui->stopButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    if ( ui->spinBox->value() != 0 )
        ui->pushButton_3->setEnabled(true);
    if ( ui->spinBox->value() != roundNum )
        ui->pushButton_6->setEnabled(true);
}


//停止
void ReplayWindow::on_pushButton_2_clicked()
{
    pause =true;
    timer->stop();
    sleep(Time);
    ui->startButton->setEnabled(true);
    ui->stopButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    qDebug() << "TAT";

        //显示第一回合的画面
    hero_set_(0,read_hero_x(0,1),read_hero_y(0,1),true);
    hero_set_(1,read_hero_x(1,1),read_hero_y(1,1),true);
    hero_set_(2,read_hero_x(2,1),read_hero_y(2,1),true);
    hero_set_(3,read_hero_x(3,1),read_hero_y(3,1),true);
    hero_set_(4,read_hero_x(4,1),read_hero_y(4,1),true);
    hero_set_(5,read_hero_x(5,1),read_hero_y(5,1),true);

    ui->spinBox->setValue(0);
    round = 0;
    if ( ui->spinBox->value() != 0 )
        ui->pushButton_3->setEnabled(true);
    if ( ui->spinBox->value() != roundNum )
        ui->pushButton_6->setEnabled(true);
}


void ReplayWindow::Label_show(int i,int n)
{
    QString CurrentUnitHP;
    QString magicCD;
    QString stunCD;
    QString fastWalkCD;
    if ( n != -1 ){
        if ( i < 3 ){
            CurrentUnitHP.setNum(statusList[n-1]->AI1HeroInfo[i].currentHP);
            magicCD.setNum(statusList[n-1]->AI1HeroInfo[i].missileCD);
            stunCD.setNum(statusList[n-1]->AI1HeroInfo[i].stunCD);
            fastWalkCD.setNum(statusList[n-1]->AI1HeroInfo[i].fastWalkCD);
            Label_showInfo->setText(tr("    种类: 英雄 \n\n    名字: %1 \n\n    队伍: %2 \n\n    血量: %3  \n\n    法术CD: %4 \n\n    晕眩CD: %5 \n\n    疾风步CD: %6")
                                    .arg(QString::fromStdWString(pInfo[0].heroName[i]))
                                    .arg(QString::fromStdWString(pInfo[0].teamName))
                                    .arg(CurrentUnitHP)
                                    .arg(magicCD)
                                    .arg(stunCD)
                                    .arg(fastWalkCD));
            Label_showInfo->move(QPoint(hero[i]->x()+hero[i]->width(),hero[i]->y()+hero[i]->height()));
            Label_showInfo->show();
        }
        if ( i > 2 && i < 6){
            CurrentUnitHP.setNum(statusList[n-1]->AI2HeroInfo[i-3].currentHP);
            magicCD.setNum(statusList[n-1]->AI2HeroInfo[i-3].missileCD);
            stunCD.setNum(statusList[n-1]->AI2HeroInfo[i-3].stunCD);
            fastWalkCD.setNum(statusList[n-1]->AI2HeroInfo[i-3].fastWalkCD);
            Label_showInfo->setText(tr("    种类: 英雄 \n\n    名字: %1 \n\n    队伍: %2 \n\n    血量: %3  \n\n    法术CD: %4 \n\n    晕眩CD: %5 \n\n    疾风步CD: %6")
                                    .arg(QString::fromStdWString(pInfo[1].heroName[i-3]))
                                    .arg(QString::fromStdWString(pInfo[1].teamName))
                                    .arg(CurrentUnitHP)
                                    .arg(magicCD)
                                    .arg(stunCD)
                                    .arg(fastWalkCD));
            Label_showInfo->move(QPoint(hero[i]->x()+hero[i]->width(),hero[i]->y()+hero[i]->height()));
            Label_showInfo->show();
        }
        if ( i == 10 ){
            CurrentUnitHP.setNum(statusList[n-1]->swordInfo.CentreSwordCD);
            Label_showInfo->setText(tr("    产生新宝剑等待时间: %1\n\n")
                                    .arg(CurrentUnitHP));
            Label_showInfo->move(QPoint(X+W/2,Y+H/2));
            Label_showInfo->show();
        }
    }
    else{
        if ( i == 0 ){
            int round = ui->horizontalSlider->value();
            if ( round == 0)
                CurrentUnitHP.setNum(0);
            else
                CurrentUnitHP.setNum(statusList[round-1]->swordInfo.AI1SwordNumber);
            Label_showInfo->setText(tr("    Type: Base \n\n    Team: %1 \n\n    Num: %2 ").arg(QString::fromStdWString(pInfo[0].teamName)).arg(CurrentUnitHP));
            Label_showInfo->move(QPoint(picture.at(i)->x()+picture.at(i)->width(),picture.at(i)->y()+picture.at(i)->height()));
            Label_showInfo->show();
        }
        if ( i == 1 ){
            int round = ui->horizontalSlider->value();
            if ( round == 0)
                CurrentUnitHP.setNum(0);
            else
                CurrentUnitHP.setNum(statusList[round-1]->swordInfo.AI2SwordNumber);
            Label_showInfo->setText(tr("    Type: Base \n\n    Team: %1 \n\n    Num: %2 ").arg(QString::fromStdWString(pInfo[1].teamName)).arg(CurrentUnitHP));
            Label_showInfo->move(QPoint(picture.at(i)->x()+picture.at(i)->width(),picture.at(i)->y()+picture.at(i)->height()));
            Label_showInfo->show();
        }
    }
}


Ui::ReplayWindow* ReplayWindow::returnUi()
{
    return ui;
}


void ReplayWindow::GoInto()
{
//    ui->pushButton->setEnabled(false);
    ifStatus = false;
    repaint();
    if ( timer->timerId() != -1 ){
        timer->stop();
        timerison=false;
    }
    for ( int i = 0 ; i < 6 ; i++ ){
        hero[i]->clear();
        hero[i]->setGeometry(0,0,0,0);
        hero[i]->hide();
    }
    ui->startButton->setEnabled(false);
    ui->stopButton_1->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->horizontalSlider->setValue(0);

    ui->lineEdit->setText(tr("队伍名"));
    ui->lineEdit_2->setText(tr("金钱"));
    ui->lineEdit_3->setText(tr("宝剑数"));
    ui->lineEdit_4->setText(tr("队伍名"));
    ui->lineEdit_5->setText(tr("金钱"));
    ui->lineEdit_6->setText(tr("宝剑数"));

    round = 1;
}

void ReplayWindow::on_pushButton_clicked()
{
}

void  ReplayWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->ignore();
}

void ReplayWindow::ChangeRound(int n)
{
    round = n;
    if (ifStatus){
        hero_set_(0,read_hero_x(0,n),read_hero_y(0,n),true);
        hero_set_(1,read_hero_x(1,n),read_hero_y(1,n),true);
        hero_set_(2,read_hero_x(2,n),read_hero_y(2,n),true);
        hero_set_(3,read_hero_x(3,n),read_hero_y(3,n),true);
        hero_set_(4,read_hero_x(4,n),read_hero_y(4,n),true);
        hero_set_(5,read_hero_x(5,n),read_hero_y(5,n),true);
        if ( n != 0 && timer->isActive() == false && !isRun)
            ui->pushButton_3->setEnabled(true);
        else
            ui->pushButton_3->setEnabled(false);
        if ( n == 0 )
            for ( int i = 0 ; i < 6 ; i++ )
                this->hero[i]->hide();
        if ( n != roundNum && timer->isActive() == false && !isRun )
            ui->pushButton_6->setEnabled(true);
        else
            ui->pushButton_6->setEnabled(false);
        QString num;
        num.setNum(statusList[n-1]->AI1gold);
        ui->lineEdit_2->setText(num);
        num.setNum(statusList[n-1]->AI2gold);
        ui->lineEdit_5->setText(num);
        num.setNum(statusList[n-1]->swordInfo.AI1SwordNumber);
        ui->lineEdit_3->setText(num);
        num.setNum(statusList[n-1]->swordInfo.AI2SwordNumber);
        ui->lineEdit_6->setText(num);
        if ( n == 0 ){
           num.setNum(0);
           ui->lineEdit_2->setText(num);
           ui->lineEdit_5->setText(num);
           ui->lineEdit_3->setText(num);
           ui->lineEdit_6->setText(num);
        }
        if ( n == roundNum ){
            ui->startButton->setEnabled(false);
            ui->stopButton_1->setEnabled(false);
            ui->pushButton_2->setEnabled(false);
            ui->pushButton_6->setEnabled(false);
            ui->pushButton_3->setEnabled(true);
        }
        if ( n != roundNum && timer->isActive() == false && !isRun ){
            ui->startButton->setEnabled(true);
        }
        this->repaint();
    }
    else
        ui->spinBox->setValue(0);
}

void ReplayWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
