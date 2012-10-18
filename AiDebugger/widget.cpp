#include "widget.h"
#include "ui_widget.h"
#include <QTextCodec>
#include <QMessageBox>
#include <QFileDialog>
#include <math.h>
#include <windows.h>


using namespace DS14;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    cur_round = 0;

    ui->setupUi(this);
    ui->pushButton->setText(tr("开始对战"));
    ui->comboBox->setEditable(false);
    ui->comboBox->addItem("Side1");
    ui->comboBox->addItem("Side2");
    ui->progressBar->setRange(0, 2400);
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setRange(0, 2400);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider_2->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->checkBox_auto->setCheckState(Qt::Checked);
    battle = new NormalBattle;
    battle->setSleepTime(400 / log(ui->horizontalSlider_2->value()));
    connect(battle, SIGNAL(path_error(int)), this, SLOT(pathError(int)));
    connect(battle, SIGNAL(ready_for_connect(QString)), this, SLOT(startDebugAI(QString)));
    connect(battle, SIGNAL(connect_error(int)), this, SLOT(connectError(int)));
    connect(battle, SIGNAL(round(int)), this, SLOT(roundUp(int)));
    connect(battle, SIGNAL(send_winner(int)), this, SLOT(winner(int)));
    connect(battle, SIGNAL(init_error(int)), this, SLOT(initError(int)));
   // connect(battle, SIGNAL(debugsignal(int)), this, SLOT(Debug(int)));
    connect(battle, SIGNAL(debug_battle_logic_prepared()), this, SLOT(startShowReplay()));
    connect(battle, SIGNAL(version_error(int)), this, SLOT(versionError(int)));

    repWidget = NULL;

    statusList = new Status[GAME_ROUNDS+1];
    this->showMaximized();
}

Widget::~Widget()
{
    delete repWidget;
    delete ui;
    delete battle;
    delete [] statusList;
}

void Widget::on_pushButton_clicked()
{
    if (ui->pushButton->text() == tr("开始对战"))
    {
        debugside = ui->comboBox->currentIndex() + 1;
        ui->pushButton->setText(tr("暂停对战"));
        ui->checkBox_auto->setCheckState(Qt::Checked);
        ui->horizontalSlider->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        if (debugside == 1)
            battle->StartNormalBattle("\\\debug", ui->lineEdit_AI->text(), ui->lineEdit_Map->text());
        else battle->StartNormalBattle(ui->lineEdit_AI->text(), "\\\debug", ui->lineEdit_Map->text());

    }
    else if (ui->pushButton->text() == tr("暂停对战"))
    {

        ui->pushButton->setText(tr("继续对战"));
        battle->stopBattle();
        ui->horizontalSlider->setEnabled(true);
    }
    else if (ui->pushButton->text() == tr("继续对战"))
    {

        ui->pushButton->setText(tr("暂停对战"));
        battle->continueBattle();
        ui->horizontalSlider->setEnabled(false);
    }

}

void Widget::pathError(int x)
{
    if (x) QMessageBox::warning(this, tr("路径错误"), tr("对战AI路径错误"));
    else QMessageBox::warning(this, tr("路径错误"), tr("地图路径错误"));
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::startDebugAI(QString name)
{
    QMessageBox::information(this, tr("注意"), QString(tr("请运行调试版AI（aimain_debugger.cpp），并输入以下口令：")).append(name).append(tr("然后单击确定")));
    battle->ready_connect();
}

void Widget::startShowReplay()
{
    if (repWidget == NULL)
    {
        logic *l = battle->getLogic();
        statusList[0] = l->getStatus();
        repWidget = new maindevice(statusList[0], this);
        ui->verticalLayout->addWidget(repWidget);
    }
    ui->label_round->setText(QString::number(0));
    cur_round = 0;
}

void Widget::connectError(int side)
{
    QString warm("AI");
    warm.append(QString::number(side)).append(tr("连接错误"));
    if (side == debugside) warm.append(tr("，请确定调试AI正常运行且正确输入调试口令"));
    QMessageBox::warning(this, tr("AI连接错误"), warm);
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::versionError(int side)
{
    if (side == 3)
    {
        QMessageBox::warning(this, tr("版本错误"), tr("地图版本错误"));
    }
    else
    {
        QString warm("AI");
        warm.append(QString::number(side)).append(tr("版本错误，请确认下载了最新的平台，且AI使用了最新的Basic.h"));
        QMessageBox::warning(this, tr("AI版本错误"), warm);
    }
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::on_pushButton_AI_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("载入AI"),
                        "AIFiles/",
                        tr("AI程序(*.exe)"));
    ui->lineEdit_AI->setText(fileName);
}

void Widget::on_pushButton_Map_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("载入地图"),
                        "MapFiles/",
                        tr("地图文件(*.map)"));
    ui->lineEdit_Map->setText(fileName);
}

void Widget::roundUp(int round)
{
    cur_round = round;
    ui->progressBar->setValue(round);
    logic *l = battle->getLogic();
    statusList[round] = l->getStatus();
    if (ui->checkBox_auto->checkState() == Qt::Checked)
    {
        ui->horizontalSlider_3->setValue(round);
        show_round = round;

    }
    ui->label_round->setText(QString::number(round));
}

void Widget::winner(int side)
{
    QString string;
    if ( side == 1 ) string = tr("AI1获胜");
    else if ( side == 2 ) string = tr("AI2获胜");
    else if (side == 3) string = tr("平局");
    QMessageBox::information(this, QString(tr("结果")), string);
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::on_horizontalSlider_sliderMoved(int position)
{
    if (position)
    {
        ui->pushButton_2->setEnabled(false);
        battle->change_to_debug_mode();
    }
    else
    {
        ui->pushButton_2->setEnabled(true);
        battle->change_to_run_mode();
    }
}

void Widget::on_horizontalSlider_2_valueChanged(int value)
{
    battle->setSleepTime(400 / log(value));
}

void Widget::initError(int side)
{
    QString string;
    if ( side == 1 ) string = tr("AI1初始化出错");
            else string = tr("AI2初始化出错");
    QMessageBox::warning(this, QString(tr("初始化错误")), string);
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::Debug(int x)
{
    QString a;
    a.setNum(x);
    QMessageBox::warning(this, QString(tr("Debug")), a);
}

void Widget::on_pushButton_2_clicked()
{
    battle->end();
    ui->pushButton->setText(tr("开始对战"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}


void Widget::on_horizontalSlider_3_valueChanged(int value)
{
    if (value > cur_round)
    {
        ui->horizontalSlider_3->setValue(show_round);
        return;
    }
    if (value == show_round) return;
    show_round = value;
    repWidget->setStatus(statusList[show_round]);
    repWidget->repaint();
    ui->label_show_round->setText(QString::number(show_round));
}

void Widget::on_pushButton_show_round_minus_clicked()
{
    if (ui->horizontalSlider_3->value() == 0) return;
    ui->horizontalSlider_3->setValue(ui->horizontalSlider_3->value()-1);
}

void Widget::on_pushButton_show_round_plus_clicked()
{
    ui->horizontalSlider_3->setValue(ui->horizontalSlider_3->value()+1);
}
