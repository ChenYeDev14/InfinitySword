#include "mapeditor.h"
#include "ui_mapeditor.h"
#include <QPainter>
#include <QDebug>
#include <cmath>
#include <QPoint>
#include <QPalette>
#include <QMessageBox>
#include <QFileDialog>

using namespace std;

//0:未选定
//1:己方基地
//2:敌方基地
//3:减速地带
//4:禁止通行区域
//5:己方英雄出生点
//6:敌方英雄出生点
//7：刷白


const double X=195.0;
const double Y=78.0;
const double W=540.0;
const double H=540.0;


MapEditor::MapEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapEditor),
    MapType(0),
    hero1Num(0),
    hero2Num(0),
    base1Num(0),
    base2Num(0),
    stuckNum(0),
    slowNum(0),
    xPosition(0),
    yPointion(0),
    isSaved(false)
{
    ui->setupUi(this);

//    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(Radio_1()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(Radio_2()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(Radio_3()));
    connect(ui->radioButton_4,SIGNAL(clicked()),this,SLOT(Radio_4()));
    connect(ui->radioButton_5,SIGNAL(clicked()),this,SLOT(Radio_5()));
    connect(ui->radioButton_6,SIGNAL(clicked()),this,SLOT(Radio_6()));
    connect(ui->radioButton_8,SIGNAL(clicked()),this,SLOT(Radio_7()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Save()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Open()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(newFile()));
    for ( int i = 0 ; i < 3 ; i++ ){
        hero1[i] = new QLabel(this);
        hero1[i]->hide();
        hero2[i] = new QLabel(this);
        hero2[i]->hide();
    }
    base1 = new QLabel(this);
    base1->hide();
    base2 = new QLabel(this);
    base2->hide();
    for ( int i = 0 ; i < 50 ; i++ ){
        stuck[i] = new QLabel(this);
        stuck[i]->hide();
        slow[i] = new QLabel(this);
        slow[i]->hide();
    }
    setAcceptDrops(true);

    curFile = tr("mapSample");
    ui->frame->setFrameStyle(Qt::FramelessWindowHint);
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::green);
    ui->radioButton->setPalette(pe);
    ui->radioButton_2->setPalette(pe);
    ui->radioButton_3->setPalette(pe);
    ui->radioButton_4->setPalette(pe);
    ui->radioButton_5->setPalette(pe);
    ui->radioButton_6->setPalette(pe);
    ui->radioButton_8->setPalette(pe);

    ui->radioButton->setBaseSize(140,20);


    dragID.num = 0;
    dragID.type = 0;
}

MapEditor::~MapEditor()
{
    delete ui;
}

void MapEditor::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawPixmap(0,0,1024,768,QPixmap(":/image/2DGround3.png"));
    paint.drawPixmap(ui->radioButton->x()+ui->frame->x()+140,ui->radioButton->y()+ui->frame->y(),30,30,QPixmap(":/image/base1fb.png"));
    paint.drawPixmap(ui->radioButton_2->x()+ui->frame->x()+140,ui->radioButton_2->y()+ui->frame->y(),30,30,QPixmap(":/image/base2fb.png"));
    paint.drawPixmap(ui->radioButton_3->x()+ui->frame->x()+140,ui->radioButton_3->y()+ui->frame->y(),30,30,QPixmap(":/image/slowfb.png"));
    paint.drawPixmap(ui->radioButton_4->x()+ui->frame->x()+140,ui->radioButton_4->y()+ui->frame->y(),30,30,QPixmap(":/image/stuckfb.png"));
    paint.drawPixmap(ui->radioButton_5->x()+ui->frame->x()+140,ui->radioButton_5->y()+ui->frame->y(),30,30,QPixmap(":/image/birthPointfb.png"));
    paint.drawPixmap(ui->radioButton_6->x()+ui->frame->x()+140,ui->radioButton_6->y()+ui->frame->y(),30,30,QPixmap(":/image/birthPoint2fb.png"));
    paint.drawPixmap(X+W/2-double(50)*W/double(2400),Y+H/2-double(50)*H/double(2400),double(100)*W/double(2400),double(100)*H/double(2400),QPixmap(":/image/center.png"));
}


void MapEditor::Radio_1()
{
    MapType = 1;
}

void MapEditor::Radio_2()
{
    MapType = 2;
}

void MapEditor::Radio_3()
{
    MapType = 3;
}

void MapEditor::Radio_4()
{
    MapType = 4;
}

void MapEditor::Radio_5()
{
    MapType = 5;
}

void MapEditor::Radio_6()
{
    MapType = 6;
}

void MapEditor::Radio_7()
{
    MapType = 7;
}



void MapEditor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
        return;
    Xy answer = findPic(event->x(),event->y());
    if (answer.type != 0){
        if ( MapType == 7 ){
            switch (answer.type){
            case (1):{
                base1->hide();
                base1Num--;
                break;
            }
            case (2):{
                base2->hide();
                base2Num--;
                break;
            }
            case (3):{
                slow[answer.num]->hide();
                slowNum--;
                break;
            }
            case (4):{
                stuck[answer.num]->hide();
                stuckNum--;
                break;
            }
            case (5):{
                hero1[answer.num]->hide();
                hero1Num--;
                break;
            }
            case (6):{
                hero2[answer.num]->hide();
                hero2Num--;
                break;
            }
            }
        }
        else{
            QPixmap image;
            QPoint point;
            dragID = answer;
            switch (answer.type){
            case (1):{
                image = *base1->pixmap();
                point = QPoint(base1->x(),base1->y());
                base1->hide();
                break;
            }
            case (2):{
                image = *base2->pixmap();
                point = QPoint(base2->x(),base2->y());
                base2->hide();
                break;
            }
            case (3):{
                image = *slow[answer.num]->pixmap();
                point = QPoint(slow[answer.num]->x(),slow[answer.num]->y());
                slow[answer.num]->hide();
                break;
            }
            case (4):{
                image = *stuck[answer.num]->pixmap();
                point = QPoint(stuck[answer.num]->x(),stuck[answer.num]->y());
                stuck[answer.num]->hide();
                break;
            }
            case (5):{
                image = *hero1[answer.num]->pixmap();
                point = QPoint(hero1[answer.num]->x(),hero1[answer.num]->y());
                hero1[answer.num]->hide();
                break;
            }
            case (6):{
                image = *hero2[answer.num]->pixmap();
                point = QPoint(hero2[answer.num]->x(),hero2[answer.num]->y());
                hero2[answer.num]->hide();
                break;
            }
            }
            QByteArray data;
            QDataStream stream(&data, QIODevice::WriteOnly);
            stream << image << point;

            QDrag* drag = new QDrag(this);
            QMimeData* mimeData = new QMimeData;
            mimeData->setData("application/x-dragitemdata", data);
            drag->setMimeData(mimeData);
            drag->setPixmap(image);
            drag->setHotSpot(event->pos()-point);
            xPosition = event->x() - point.x();
            yPointion = event->y() - point.y();
            if ( 0 == drag->exec(Qt::MoveAction) ){
                switch (answer.type){
                case (1):{
                    base1->show();
                    break;
                }
                case (2):{
                    base2->show();
                    break;
                }
                case (3):{
                    slow[answer.num]->show();
                    break;
                }
                case (4):{
                    stuck[answer.num]->show();
                    break;
                }
                case (5):{
                    hero1[answer.num]->show();
                    break;
                }
                case (6):{
                    hero2[answer.num]->show();
                    break;
                }
                }
            }

        }
        return;
    }
    int radius = double(50)*W/double(2400);
    if ( MapType == 1 || MapType == 2 )
        radius = double(100)*W/double(2400);
    if ( coulddrop(event->x(),event->y(),radius) == false)
        return;
    switch ( MapType ){
    case (1):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - BASE_RADIUS*W/double(2400) && base1Num == 0 ){
            base1->setGeometry(event->x()-BASE_RADIUS*W/double(2400),event->y()-BASE_RADIUS*H/double(2400),BASE_RADIUS*2*W/double(2400),BASE_RADIUS*2*H/double(2400));
            base1->setPixmap(QPixmap(":/image/base1.png"));
            base1->show();
            base1Num++;
        }
        break;
    }
    case (2):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - BASE_RADIUS*W/double(2400) && base2Num == 0 ){
            base2->setGeometry(event->x()-BASE_RADIUS*W/double(2400),event->y()-BASE_RADIUS*H/double(2400),BASE_RADIUS*2*W/double(2400),BASE_RADIUS*2*H/double(2400));
            base2->setPixmap(QPixmap(":/image/base2.png"));
            base2->show();
            base2Num++;
        }
        break;
    }
    case (3):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) && slowNum < double(50) ){
            int i = 0 ;
            while ( slow[i]->isHidden() == false) i++;
            slow[i]->setGeometry(event->x()-double(50)*W/double(2400),event->y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            slow[i]->setPixmap(QPixmap(":/image/slow.png"));
            slow[i]->show();
            slowNum++;

        }
        break;
    }
    case (4):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) && stuckNum < double(50) ){
            int i = 0 ;
            while ( stuck[i]->isHidden() == false) i++;
            stuck[i]->setGeometry(event->x()-double(50)*W/double(2400),event->y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            stuck[i]->setPixmap(QPixmap(":/image/stuck.png"));
            stuck[i]->show();
            stuckNum++;
        }
        break;
    }
    case (5):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) && hero1Num < 3 ){
            int i = 0 ;
            while ( hero1[i]->isHidden() == false) i++;
            hero1[i]->setGeometry(event->x()-double(50)*W/double(2400),event->y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            hero1[i]->setPixmap(QPixmap(":/image/birthPoint1.png"));
            hero1[i]->show();
            hero1Num++;
        }
        break;
    }
    case (6):{
        if ( Round(event->x(),event->y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) && hero2Num < 3 ){
            int i = 0 ;
            while ( hero2[i]->isHidden() == false) i++;
            hero2[i]->setGeometry(event->x()-double(50)*W/double(2400),event->y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            hero2[i]->setPixmap(QPixmap(":/image/birthPoint2.png"));
            hero2[i]->show();
            hero2Num++;
        }
        break;
    }
    }
}


double MapEditor::Round(int x,int y,int xx,int yy)
{
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}

Xy MapEditor::findPic(int x, int y)
{
    Xy answer;
    answer.type = 0;
    answer.num = 0;
    if ( base1->isHidden() == false && Round(x,y,base1->x()+base1->width()/2,base1->y()+base1->height()/2) < double(100)*W/double(2400) ){
        answer.type = 1;
        return answer;
    }
    if ( base2->isHidden() == false && Round(x,y,base2->x()+base2->width()/2,base2->y()+base1->height()/2) < double(100)*W/double(2400) ){
        answer.type = 2;
        return answer;
    }
    for ( int i = 0 ; i < 50 ; i++ ){
        if ( slow[i]->isHidden() == false && Round(x,y,slow[i]->x()+slow[i]->width()/2,slow[i]->y()+slow[i]->height()/2) < double(50)*W/double(2400) ){
            answer.type = 3;
            answer.num = i;
            return answer;
       }
    }
    for ( int i = 0 ; i < 50 ; i++ ){
        if ( stuck[i]->isHidden() == false && Round(x,y,stuck[i]->x()+stuck[i]->width()/2,stuck[i]->y()+stuck[i]->height()/2) < double(50)*W/double(2400) ){
            answer.type = 4;
            answer.num = i;
            return answer;
       }
    }
    for ( int i = 0 ; i < 3 ; i++ ){
        if ( hero1[i]->isHidden() == false && Round(x,y,hero1[i]->x()+hero1[i]->width()/2,hero1[i]->y()+hero1[i]->height()/2) < double(50)*W/double(2400) ){
            answer.type = 5;
            answer.num = i;
            return answer;
       }
    }
    for ( int i = 0 ; i < 3 ; i++ ){
        if ( hero2[i]->isHidden() == false && Round(x,y,hero2[i]->x()+hero2[i]->width()/2,hero2[i]->y()+hero2[i]->height()/2) < double(50)*W/double(2400) ){
            answer.type = 6;
            answer.num = i;
            return answer;
       }
    }
    return answer;
}

bool MapEditor::coulddrop(int x, int y, int radius)
{
    if ( base1->isHidden() == false && Round(x,y,base1->x()+base1->width()/2,base1->y()+base1->height()/2) < double(100)*W/double(2400) + radius ){
        return false;
    }
    if ( base2->isHidden() == false && Round(x,y,base2->x()+base2->width()/2,base2->y()+base1->height()/2) < double(100)*W/double(2400) + radius){
        return false;
    }
    for ( int i = 0 ; i < double(50) ; i++ ){
        if ( slow[i]->isHidden() == false && Round(x,y,slow[i]->x()+slow[i]->width()/2,slow[i]->y()+slow[i]->height()/2) < double(50)*W/double(2400) + radius)
            return false;
    }
    for ( int i = 0 ; i < double(50) ; i++ ){
        if ( stuck[i]->isHidden() == false && Round(x,y,stuck[i]->x()+stuck[i]->width()/2,stuck[i]->y()+stuck[i]->height()/2) < double(50)*W/double(2400) + radius)
            return false;
    }
    for ( int i = 0 ; i < 3 ; i++ ){
        if ( hero1[i]->isHidden() == false && Round(x,y,hero1[i]->x()+hero1[i]->width()/2,hero1[i]->y()+hero1[i]->height()/2) < double(50)*W/double(2400) + radius)
            return false;
    }
    for ( int i = 0 ; i < 3 ; i++ ){
        if ( hero2[i]->isHidden() == false && Round(x,y,hero2[i]->x()+hero2[i]->width()/2,hero2[i]->y()+hero2[i]->height()/2) < double(50)*W/double(2400) + radius)
            return false;
    }
    if ( Round(x,y,X+W/2,Y+H/2) < radius + double(50)*W/double(2400) )
        return false;
    return true;
}


void MapEditor::dragMoveEvent(QDragMoveEvent *dragEvent)
{
    dragEvent->setDropAction(Qt::MoveAction);
    dragEvent->accept();
}

void MapEditor::dragEnterEvent(QDragEnterEvent *dragEvent)
{
    QCursor my(QPixmap(":/image/cursor3.png"),52,52);
    setCursor(my);
    if (dragEvent->mimeData()->hasFormat("application/x-dragitemdata"))
        dragEvent->accept();
    else
        dragEvent->ignore();
}

void MapEditor::dragLeaveEvent(QDragLeaveEvent *dragEvent)
{
    dragEvent->accept();
}

void MapEditor::dropEvent(QDropEvent *dragEvent)
{
    if (dragEvent->mimeData()->hasFormat("application/x-dragitemdata"))
    {
        QByteArray data = dragEvent->mimeData()->data("application/x-dragitemdata");
        QDataStream stream(data);
        QPixmap image;
        QPoint point;
        stream >> image >> point;

        point = dragEvent->pos();
        point.setX(point.x()-xPosition);
        point.setY(point.y()-yPointion);

        Xy answer = dragID;
        switch (answer.type){
        case (1):{
            point.setX(point.x() + double(100) * W / double(2400));
            point.setY(point.y() + double(100) * W / double(2400));
            if ( coulddrop(point.x(),point.y(),double(100)*W/double(2400)) && ( Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(100)*W/double(2400) ))
                base1->setGeometry(point.x()-double(100)*W/double(2400),point.y()-double(100)*W/double(2400),200*W/double(2400),200*W/double(2400));
            base1->show();
            break;
        }
        case (2):{
            point.setX(point.x() + double(100) * W / 2400);
            point.setY(point.y() + double(100) * W / 2400);
            if ( coulddrop(point.x(),point.y(),double(100)*W/double(2400)) && Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(100)*W/double(2400) )
                base2->setGeometry(point.x()-double(100)*W/double(2400),point.y()-double(100)*W/double(2400),200*W/double(2400),200*W/double(2400));
            base2->show();
            break;
        }
        case (3):{
            point.setX(point.x() + double(50) * W / 2400);
            point.setY(point.y() + double(50) * W / 2400);
            if ( coulddrop(point.x(),point.y(),double(50)*W/double(2400)) && Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) )
                slow[answer.num]->setGeometry(point.x()-double(50)*W/double(2400),point.y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            slow[answer.num]->show();
            break;
        }
        case (4):{
            point.setX(point.x() + double(50) * W / 2400);
            point.setY(point.y() + double(50) * W / 2400);
            if ( coulddrop(point.x(),point.y(),double(50)*W/double(2400)) && Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) )
                stuck[answer.num]->setGeometry(point.x()-double(50)*W/double(2400),point.y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            stuck[answer.num]->show();
            break;
        }
        case (5):{
            point.setX(point.x() + double(50) * W / 2400);
            point.setY(point.y() + double(50) * W / 2400);
            if ( coulddrop(point.x(),point.y(),double(50)*W/double(2400)) && Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) )
                hero1[answer.num]->setGeometry(point.x()-double(50)*W/double(2400),point.y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            hero1[answer.num]->show();
            break;
        }
        case (6):{
            point.setX(point.x() + double(50) * W / 2400);
            point.setY(point.y() + double(50) * W / 2400);
            if ( coulddrop(point.x(),point.y(),double(50)*W/double(2400)) && Round(point.x(),point.y(),X+W/2,Y+W/2) < W/2 - double(50)*W/double(2400) )
                hero2[answer.num]->setGeometry(point.x()-double(50)*W/double(2400),point.y()-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            hero2[answer.num]->show();
            break;
        }
        }

        dragEvent->setDropAction(Qt::MoveAction);
        dragEvent->accept();
    }
}

bool MapEditor::couldSave()
{
    bool could = true;
    if ( base1Num != 1 )
        could = false;
    if ( base2Num != 1 )
        could = false;
    if ( hero1Num != 3 )
        could = false;
    if ( hero2Num != 3 )
        could = false;
    return could;
}


Ui::MapEditor* MapEditor::returnUi()
{
    return ui;
}

void MapEditor::SetMapInfo()
{
        Coordinate center;
        center.x = base1->x()+(double)base1->width()/2.0;
        center.y = base1->y()+(double)base1->height()/2.0;
        mInfo.AIBases[0] = DeviceToLogic(center);
        center.x = base2->x()+(double)base2->width()/2.0;
        center.y = base2->y()+(double)base2->height()/2.0;
        mInfo.AIBases[1] = DeviceToLogic(center);
        for ( int i = 0 ; i < 3 ; i++ ){
            center.x = hero1[i]->x()+(double)hero1[i]->width()/2.0;
            center.y = hero1[i]->y()+(double)hero1[i]->height()/2.0;
            mInfo.AIHeroBirthPlace[0][i] = DeviceToLogic(center);
        }
        for ( int i = 0 ; i < 3 ; i++ ){
            center.x = hero2[i]->x()+(double)hero2[i]->width()/2.0;
            center.y = hero2[i]->y()+(double)hero2[i]->height()/2.0;
            mInfo.AIHeroBirthPlace[1][i] = DeviceToLogic(center);
        }
        mInfo.roadBlockNumber = this->stuckNum;
        mInfo.slowDownAreaNumber = this->slowNum;
        int n = 0;
        for ( int i = 0 ; i < 50 ; i++ ){
            if ( slow[i]->isHidden() == false ){
                center.x = slow[i]->x()+(double)slow[i]->width()/2.0;
                center.y = slow[i]->y()+(double)slow[i]->height()/2.0;
                mInfo.slowDownArea[n] = DeviceToLogic(center);
                n++;
            }
        }
        n = 0;
        for ( int i = 0 ; i < 50 ; i++ ){
            if ( stuck[i]->isHidden() == false ){
                center.x = stuck[i]->x()+(double)stuck[i]->width()/2.0;
                center.y = stuck[i]->y()+(double)stuck[i]->height()/2.0;
                mInfo.roadBlock[n] = DeviceToLogic(center);
                n++;
            }
        }
        QFile outFile;
        outFile.setFileName(curFile);
        outFile.open(QIODevice::WriteOnly);
        outFile.write((char*)&VERSION_BASIC, sizeof(int));
        outFile.write((char*)&mInfo, sizeof(mInfo));
        outFile.close();
        isSaved = true;
}

void MapEditor::OpenFile()
{
    QFile inFile;
    inFile.setFileName(curFile);
    if (!inFile.open(QIODevice::ReadOnly))
    {
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("文件打开失败！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
    int version;
    inFile.read((char*)&version, sizeof(int));
    if (version == VERSION_BASIC){
        inFile.read((char*)&mInfo, sizeof(mInfo));
        inFile.close();
        Init();
        base1->setGeometry(mInfo.AIBases[0].x*W/double(2400)+X+W/2-double(100)*W/double(2400),Y+W/2-mInfo.AIBases[0].y*W/double(2400)-double(100)*W/double(2400),200*W/double(2400),200*H/double(2400));
        base1->setPixmap(QPixmap(":/image/base1.png"));
        base1->show();
        base1Num = 1;
        base2->setGeometry(mInfo.AIBases[1].x*W/double(2400)+X+W/2-double(100)*W/double(2400),Y+W/2-mInfo.AIBases[1].y*W/double(2400)-double(100)*W/double(2400),200*W/double(2400),200*H/double(2400));
        base2->setPixmap(QPixmap(":/image/base2.png"));
        base2->show();
        base2Num = 1;
        for ( int i = 0 ; i < 3 ; i++ ){
            hero1[i]->setGeometry(mInfo.AIHeroBirthPlace[0][i].x*W/double(2400)+X+W/2-double(50)*W/double(2400),Y+W/2-mInfo.AIHeroBirthPlace[0][i].y*W/double(2400)-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*H/double(2400));
            hero1[i]->setPixmap(QPixmap(":/image/birthPoint1.png"));
            hero1[i]->show();
        }
        hero1Num = 3;
        for ( int i = 0 ; i < 3 ; i++ ){
            hero2[i]->setGeometry(mInfo.AIHeroBirthPlace[1][i].x*W/double(2400)+X+W/2-double(50)*W/double(2400),Y+W/2-mInfo.AIHeroBirthPlace[1][i].y*W/double(2400)-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*H/double(2400));
            hero2[i]->setPixmap(QPixmap(":/image/birthPoint2.png"));
            hero2[i]->show();
        }
        hero2Num = 3;
        stuckNum = mInfo.roadBlockNumber;
        for ( int i = 0 ; i < stuckNum ; i++ ){
            stuck[i]->setGeometry(mInfo.roadBlock[i].x*W/double(2400)+X+W/2-double(50)*W/double(2400),-mInfo.roadBlock[i].y*W/double(2400)+Y+H/2-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            stuck[i]->setPixmap(QPixmap(":/image/stuck.png"));
            stuck[i]->show();
        }
        slowNum = mInfo.slowDownAreaNumber;
        for ( int i = 0 ; i < slowNum ; i++ ){
            slow[i]->setGeometry(mInfo.slowDownArea[i].x*W/double(2400)+X+W/2-double(50)*W/double(2400),-mInfo.slowDownArea[i].y*W/double(2400)+Y+H/2-double(50)*W/double(2400),double(100)*W/double(2400),double(100)*W/double(2400));
            slow[i]->setPixmap(QPixmap(":/image/slow.png"));
            slow[i]->show();
        }
        isSaved = true;
        SetMapInfo();
    }
    else{
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("版本号错误！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
}

void MapEditor::Init()
{
    hero1Num = 0;
    hero2Num = 0;
    stuckNum = 0;
    slowNum = 0;
    base1Num = 0;
    base2Num = 0;
    for ( int i = 0 ; i < 3 ; i++ ){
        hero1[i]->hide();
        hero2[i]->hide();
    }
    for ( int i = 0 ; i < 50 ; i++ ){
        slow[i]->hide();
        stuck[i]->hide();
    }
    base1->hide();
    base2->hide();
}

Coordinate MapEditor::DeviceToLogic(Coordinate deviceCo) //陈晔done 10/15
{
    double cx = X + W/2;
    double cy = Y + H/2;
    Coordinate logicCo;
    logicCo.x = ((deviceCo.x - cx) * (double)MAP_RADIUS * double(2) / W);
    logicCo.y = ((cy - deviceCo.y) * (double)MAP_RADIUS * double(2) / H);
    return logicCo;
}

void MapEditor::Save()
{
    if ( couldSave() ){
    if ( isSaved == false )
        curFile = QFileDialog::getSaveFileName(this, tr("Save"), "MapFiles/", tr("FILES (*.map)"));

    if ( curFile != ""){
        SetMapInfo();
    }
    else{
        curFile = tr("mapSample");
    }
    }
    else{
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("地图元素不足！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
}

void MapEditor::Open()
{
    if ( isSaveOrNot() ){
        curFile = QFileDialog::getOpenFileName(this, tr("Open File"), "MapFiles/", tr("FILES (*.map)"));
        if ( curFile != "")
            OpenFile();
        else
           curFile =tr("mapSample");
    }
}

void MapEditor::on_pushButton_6_clicked()
{
    Init();
}

void MapEditor::newFile()//新建文件功能
{

    if (isSaveOrNot()){
    Init();
    curFile = tr("mapSample");
    setWindowTitle(curFile);
    isSaved = false;
    }
}

bool MapEditor::isSaveOrNot()//判断当前文件是否经过更改
{
    if ( base1Num == 0 && base2Num == 0 && stuckNum == 0 && slowNum == 0 && hero1Num == 0 && hero2Num == 0 )
        return true;
    int flag=0;
    QFile inFile;
    inFile.setFileName(curFile);
    if ( !inFile.open(QIODevice::ReadOnly) )
        flag =1;
    else
    {
        int version;
        inFile.read((char*)&version, sizeof(int));
        if ( version != VERSION_BASIC )
            flag = 1;
        inFile.read((char*)&mInfo, sizeof(mInfo));
        inFile.close();
        Coordinate center;
        center.x = base1->x()+(double)base1->width()/2.0;
        center.y = base1->y()+(double)base1->height()/2.0;
        if ( DeviceToLogic(center).x != mInfo.AIBases[0].x
             || DeviceToLogic(center).y != mInfo.AIBases[0].y){
            flag = 1;
        }
        center.x = base2->x()+(double)base2->width()/2.0;
        center.y = base2->y()+(double)base2->height()/2.0;
        if ( DeviceToLogic(center).x != mInfo.AIBases[1].x
             || DeviceToLogic(center).y != mInfo.AIBases[1].y)
            flag = 1;
        for ( int i = 0 ; i < 3 ; i++ ){
            center.x = hero1[i]->x()+(double)hero1[i]->width()/2.0;
            center.y = hero1[i]->y()+(double)hero1[i]->height()/2.0;
            if ( DeviceToLogic(center).x != mInfo.AIHeroBirthPlace[0][i].x
                 || DeviceToLogic(center).y != mInfo.AIHeroBirthPlace[0][i].y ){
                flag = 1;
            }
            center.x = hero2[i]->x()+(double)hero2[i]->width()/2.0;
            center.y = hero2[i]->y()+(double)hero2[i]->height()/2.0;
            if ( DeviceToLogic(center).x != mInfo.AIHeroBirthPlace[1][i].x
                 || DeviceToLogic(center).x != mInfo.AIHeroBirthPlace[1][i].x)
                flag = 1;
        }
        if ( hero1Num!=3 )
            flag = 1;
        if ( hero2Num!=3 )
            flag = 1;
        if ( base1Num != 1 )
            flag = 1;
        if ( base2Num != 1 )
            flag = 1;
        if ( slowNum != mInfo.slowDownAreaNumber )
            flag = 1;
        if ( stuckNum != mInfo.roadBlockNumber )
            flag = 1;
        int num1 = 0 ,num2 = 0;
        if ( flag == 0 )
        for ( int i = 0 ; i < 50 ; i++ ){
            center.x = slow[i]->x()+(double)slow[i]->width()/2.0;
            center.y = slow[i]->y()+(double)slow[i]->height()/2.0;
            if ( slow[i]->isHidden() == false ){
                if ( DeviceToLogic(center).x != mInfo.slowDownArea[num1].x
                     || DeviceToLogic(center).y != mInfo.slowDownArea[num1].y )
                    flag = 1;
                    break;
            }
            else
                num1++;
            center.x = stuck[i]->x()+(double)stuck[i]->width()/2.0;
            center.y = stuck[i]->y()+(double)stuck[i]->height()/2.0;
            if ( stuck[i]->isHidden() == false ){
                if ( DeviceToLogic(center).x != mInfo.roadBlock[num2].x
                     || DeviceToLogic(center).y != mInfo.roadBlock[num2].y )
                    flag = 1;
                    break;
            }
            else
                num2++;
        }

    }
    if( flag == 1 || isSaved == false )
    {
        QMessageBox box;
        box.setWindowTitle(tr("提示"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("是否保存当前地图文件?"));
        box.addButton(QMessageBox::No);
        box.addButton(QMessageBox::Yes);

        if(box.exec()==QMessageBox::Yes){
            if ( couldSave() )
                Save();
            else {
                QMessageBox box;
                box.setWindowTitle(tr("提示"));
                box.setIcon(QMessageBox::Warning);
                box.setText(tr("地图元素不足"));
                box.setStandardButtons(QMessageBox::Ok);
                box.exec();
                return false;
            }
        }
    }
    return true;
}

void MapEditor::on_pushButton_4_clicked()
{
    if ( couldSave() ){
    curFile = QFileDialog::getSaveFileName(this, tr("Save"), "MapFiles/", tr("FILES (*.map)"));
    if ( curFile != "")
        SetMapInfo();
    else
        curFile = tr("mapSample");
    }
    else{
        QMessageBox box;
        box.setWindowTitle(tr("错误！"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("地图元素不足！"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
}
