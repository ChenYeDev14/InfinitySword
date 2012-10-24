#include "qlabel_real.h"

QLabel_Real::QLabel_Real(QWidget *parent) :
    QLabel(parent)
{
    pointF = new QPointF(0,0);
    pointFhw = new QPointF(0,0);
}


void QLabel_Real::setGeometry(double x, double y, double w, double h)
{
    this->QLabel::setGeometry(x,y,w,h);
    pointF->setX(x);
    pointF->setY(y);
    pointFhw->setX(w);
    pointFhw->setY(h);
}

double QLabel_Real::x() const
{
    return pointF->x();
}

double QLabel_Real::y() const
{
    return pointF->y();
}

double QLabel_Real::width() const
{
    return pointFhw->x();
}

double QLabel_Real::height() const
{
    return pointFhw->y();
}
