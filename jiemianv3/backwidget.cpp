#include "backwidget.h"
#include "ui_backwidget.h"
#include <QPalette>

BackWidget::BackWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BackWidget)
{
    ui->setupUi(this);

 //   showFullScreen();
    ui->widget->resize(this->width(),this->height());

    //²åÈëÍ¼Æ¬
    ui->widget->setAutoFillBackground(true);
    QPalette Qpal = ui->widget->palette();\
    Qpal.setBrush(QPalette::Window,
                     QBrush(QPixmap(":/image/MainWindow2.png").scaled(
                                 ui->widget->size(),
                                 Qt::IgnoreAspectRatio,
                                 Qt::SmoothTransformation)));
    ui->widget->setPalette(Qpal);
}

BackWidget::~BackWidget()
{
    delete ui;
}

