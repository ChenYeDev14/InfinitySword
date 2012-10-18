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
    ui->pushButton->setText(tr("��ʼ��ս"));
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
    if (ui->pushButton->text() == tr("��ʼ��ս"))
    {
        debugside = ui->comboBox->currentIndex() + 1;
        ui->pushButton->setText(tr("��ͣ��ս"));
        ui->checkBox_auto->setCheckState(Qt::Checked);
        ui->horizontalSlider->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
        if (debugside == 1)
            battle->StartNormalBattle("\\\debug", ui->lineEdit_AI->text(), ui->lineEdit_Map->text());
        else battle->StartNormalBattle(ui->lineEdit_AI->text(), "\\\debug", ui->lineEdit_Map->text());

    }
    else if (ui->pushButton->text() == tr("��ͣ��ս"))
    {

        ui->pushButton->setText(tr("������ս"));
        battle->stopBattle();
        ui->horizontalSlider->setEnabled(true);
    }
    else if (ui->pushButton->text() == tr("������ս"))
    {

        ui->pushButton->setText(tr("��ͣ��ս"));
        battle->continueBattle();
        ui->horizontalSlider->setEnabled(false);
    }

}

void Widget::pathError(int x)
{
    if (x) QMessageBox::warning(this, tr("·������"), tr("��սAI·������"));
    else QMessageBox::warning(this, tr("·������"), tr("��ͼ·������"));
    ui->pushButton->setText(tr("��ʼ��ս"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::startDebugAI(QString name)
{
    QMessageBox::information(this, tr("ע��"), QString(tr("�����е��԰�AI��aimain_debugger.cpp�������������¿��")).append(name).append(tr("Ȼ�󵥻�ȷ��")));
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
    warm.append(QString::number(side)).append(tr("���Ӵ���"));
    if (side == debugside) warm.append(tr("����ȷ������AI������������ȷ������Կ���"));
    QMessageBox::warning(this, tr("AI���Ӵ���"), warm);
    ui->pushButton->setText(tr("��ʼ��ս"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::versionError(int side)
{
    if (side == 3)
    {
        QMessageBox::warning(this, tr("�汾����"), tr("��ͼ�汾����"));
    }
    else
    {
        QString warm("AI");
        warm.append(QString::number(side)).append(tr("�汾������ȷ�����������µ�ƽ̨����AIʹ�������µ�Basic.h"));
        QMessageBox::warning(this, tr("AI�汾����"), warm);
    }
    ui->pushButton->setText(tr("��ʼ��ս"));
    ui->progressBar->setValue(0);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
}

void Widget::on_pushButton_AI_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("����AI"),
                        "AIFiles/",
                        tr("AI����(*.exe)"));
    ui->lineEdit_AI->setText(fileName);
}

void Widget::on_pushButton_Map_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                        this,
                        tr("�����ͼ"),
                        "MapFiles/",
                        tr("��ͼ�ļ�(*.map)"));
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
    if ( side == 1 ) string = tr("AI1��ʤ");
    else if ( side == 2 ) string = tr("AI2��ʤ");
    else if (side == 3) string = tr("ƽ��");
    QMessageBox::information(this, QString(tr("���")), string);
    ui->pushButton->setText(tr("��ʼ��ս"));
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
    if ( side == 1 ) string = tr("AI1��ʼ������");
            else string = tr("AI2��ʼ������");
    QMessageBox::warning(this, QString(tr("��ʼ������")), string);
    ui->pushButton->setText(tr("��ʼ��ս"));
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
    ui->pushButton->setText(tr("��ʼ��ս"));
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
