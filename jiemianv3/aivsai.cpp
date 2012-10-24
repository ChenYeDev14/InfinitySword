#include "aivsai.h"
#include "ui_aivsai.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QWindowsStyle>
#include <QStyle>
class QTextEdit;



AIvsAI::AIvsAI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AIvsAI)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0, 2400);

    connect(ui->AI1,SIGNAL(clicked()),this,SLOT(AI1()));
    connect(ui->AI2,SIGNAL(clicked()),this,SLOT(AI2()));
    //connect(ui->Start,SIGNAL(clicked()),this,SLOT(StartGame()));
    connect(ui->Map,SIGNAL(clicked()),this,SLOT(Map()));

    battle = new NormalBattle;
    connect(battle,SIGNAL(connect_error(int)),this,SLOT(connectError(int)));
    connect(battle,SIGNAL(init_error(int)),this,SLOT(initError(int)));
    connect(battle,SIGNAL(path_error(int)),this,SLOT(pathError(int)));
    connect(battle,SIGNAL(send_winner(int)),this,SLOT(sendWinner(int)));
    connect(battle,SIGNAL(round(int)),this,SLOT(round(int)));
    connect(battle,SIGNAL(version_error(int)), this, SLOT(versionError(int)));

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);

    ui->Start->setDisabled(false);
    ui->progressBar->setValue(0);
}

AIvsAI::~AIvsAI()
{
    delete ui;
    delete battle;
}

void AIvsAI::AI1()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("载入AI"),
                        "AIFiles/",
                        tr("应用程序 (*.exe)"));
    ui->LineEditAI1->setText(fileName);

}

void AIvsAI::AI2()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("载入AI"),
                "AIFiles/",
                tr("应用程序 (*.exe)"));
    ui->LineEditAI2->setText(fileName);
}


void AIvsAI::Map()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("载入地图"),
                "MapFiles/",
                tr("地图文件 (*.map)"));
    ui->LineEditMap->setText(fileName);
}





void AIvsAI::on_Start_clicked()
{
    ui->Start->setEnabled(false);
    battle->StartNormalBattle(ui->LineEditAI1->text(), ui->LineEditAI2->text(), ui->LineEditMap->text());
}


void AIvsAI::connectError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1连接出错");
            else string = tr("AI2连接出错");
    QMessageBox box;
    box.setWindowTitle(tr("连接错误！"));
    box.setIcon(QMessageBox::Warning);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->end();
}


void AIvsAI::initError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1初始化出错");
            else string = tr("AI2初始化出错");
    QMessageBox box;
    box.setWindowTitle(tr("初始化错误！"));
    box.setIcon(QMessageBox::Warning);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->end();
}

void AIvsAI::pathError(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1路径出错");
            else if ( i == 2 )string = tr("AI2路径出错");
    if ( i == 3 ) string =  tr("地图路径出错");

    QMessageBox box;
    box.setWindowTitle(tr("路径错误！"));
    box.setIcon(QMessageBox::Warning);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->end();
}

void AIvsAI::sendWinner(int i)
{
    QString string;
    if ( i == 1 ) string = tr("AI1获胜");
    else if ( i == 2 ) string = tr("AI2获胜");
    else if (i == 3) string = tr("平局");
    QMessageBox box;
    box.setWindowTitle(tr("比赛结果！"));
    box.setIcon(QMessageBox::Information);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->terminate();
}

void AIvsAI::round(int i)
{
    ui->progressBar->setValue(i);
}


void AIvsAI::versionError(int i)
{
    QString string;
    if (i == 1) string = tr("AI1版本出错");
    else if (i == 2) string = tr("AI2版本出错");
    else string = tr("地图加载失败或版本出错");
    QMessageBox box;
    box.setWindowTitle(tr("版本错误！"));
    box.setIcon(QMessageBox::Warning);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->end();
}
