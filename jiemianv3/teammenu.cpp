#include "teammenu.h"
#include "ui_teammenu.h"
#include <QPalette>

TeamMenu::TeamMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeamMenu)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
}

TeamMenu::~TeamMenu()
{
    delete ui;
}

Ui::TeamMenu* TeamMenu::returnUi()
{
    return ui;
}
