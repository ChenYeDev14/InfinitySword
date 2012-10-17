#include "beginbottum.h"
#include "ui_beginbottum.h"
#include <QMainWindow>

BeginBottum::BeginBottum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeginBottum)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);

    ui->startsingle->setDisabled(false);
    ui->webfight->setDisabled(true);
    ui->website->setDisabled(false);
    ui->team->setDisabled(false);
    ui->exitmain->setDisabled(false);

    browser = new Browser();
}

BeginBottum::~BeginBottum()
{
    delete ui;
    delete browser;
}

Ui::BeginBottum* BeginBottum::returnUi()
{
    return ui;
}

void BeginBottum::on_website_clicked()
{
    browser->showMaximized();
}
