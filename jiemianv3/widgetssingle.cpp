#include "widgetssingle.h"
#include "ui_widgetssingle.h"

widgetssingle::widgetssingle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetssingle)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);

    ui->aivsai->setDisabled(false);
    ui->levelmode->setDisabled(false);
    ui->mapedit->setDisabled(false);
    ui->playervsai->setDisabled(false);
    ui->replay->setDisabled(false);
    ui->returnpre->setDisabled(false);

    connect(ui->playervsai,SIGNAL(clicked()),this,SLOT(playervsai()));
    connect(ui->levelmode,SIGNAL(clicked()),this,SLOT(levelmode()));
    connect(ui->replay,SIGNAL(clicked()),this,SLOT(replay()));
    connect(ui->mapedit,SIGNAL(clicked()),this,SLOT(mapedit()));

}

void widgetssingle::playervsai(){}

void widgetssingle::levelmode(){}

void widgetssingle::replay(){}

void widgetssingle::mapedit(){}

widgetssingle::~widgetssingle()
{
    delete ui;
}
