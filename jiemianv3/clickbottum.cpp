#include "clickbottum.h"
#include "ui_clickbottum.h"
#include <QPalette>

ClickBottum::ClickBottum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClickBottum)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}

ClickBottum::~ClickBottum()
{
    delete ui;
}
