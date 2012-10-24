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
                        tr("����AI"),
                        "AIFiles/",
                        tr("Ӧ�ó��� (*.exe)"));
    ui->LineEditAI1->setText(fileName);

}

void AIvsAI::AI2()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("����AI"),
                "AIFiles/",
                tr("Ӧ�ó��� (*.exe)"));
    ui->LineEditAI2->setText(fileName);
}


void AIvsAI::Map()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("�����ͼ"),
                "MapFiles/",
                tr("��ͼ�ļ� (*.map)"));
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
    if ( i == 1 ) string = tr("AI1���ӳ���");
            else string = tr("AI2���ӳ���");
    QMessageBox box;
    box.setWindowTitle(tr("���Ӵ���"));
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
    if ( i == 1 ) string = tr("AI1��ʼ������");
            else string = tr("AI2��ʼ������");
    QMessageBox box;
    box.setWindowTitle(tr("��ʼ������"));
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
    if ( i == 1 ) string = tr("AI1·������");
            else if ( i == 2 )string = tr("AI2·������");
    if ( i == 3 ) string =  tr("��ͼ·������");

    QMessageBox box;
    box.setWindowTitle(tr("·������"));
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
    if ( i == 1 ) string = tr("AI1��ʤ");
    else if ( i == 2 ) string = tr("AI2��ʤ");
    else if (i == 3) string = tr("ƽ��");
    QMessageBox box;
    box.setWindowTitle(tr("���������"));
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
    if (i == 1) string = tr("AI1�汾����");
    else if (i == 2) string = tr("AI2�汾����");
    else string = tr("��ͼ����ʧ�ܻ�汾����");
    QMessageBox box;
    box.setWindowTitle(tr("�汾����"));
    box.setIcon(QMessageBox::Warning);
    box.setText(string);
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    ui->Start->setEnabled(true);
    battle->end();
}
