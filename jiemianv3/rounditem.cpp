#include "RoundItem.h"

#include <QtGui/QtGui>

RoundRectItem::RoundRectItem(const QRectF &bounds, const QColor &color,
                             QGraphicsItem *parent)
    : QGraphicsObject(parent), fillRect(false), bounds(bounds)
{
    gradient.setStart(bounds.topLeft());
    gradient.setFinalStop(bounds.bottomRight());
    gradient.setColorAt(0, color);
    gradient.setColorAt(1, color.dark(200));
    setCacheMode(ItemCoordinateCache);
}

QPixmap RoundRectItem::pixmap() const
{
    return pix;
}
void RoundRectItem::setPixmap(const QPixmap &pixmap)
{
    pix = pixmap;
    update();
}

QRectF RoundRectItem::boundingRect() const
{
    return bounds.adjusted(0, 0, 2, 2);
}

void RoundRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(0, 0, 0, 64));
    painter->drawRoundRect(bounds.translated(2, 2));
    if (fillRect)
        painter->setBrush(QApplication::palette().brush(QPalette::Window));
    else
        painter->setBrush(gradient);
    painter->setPen(QPen(Qt::black, 1));
    painter->drawRoundRect(bounds);
    if (!pix.isNull()) {
        painter->scale(1.95, 1.95);
        painter->drawPixmap(-pix.width() / 2, -pix.height() / 2, pix);
    }
}

bool RoundRectItem::fill() const
{
    return fillRect;
}
void RoundRectItem::setFill(bool fill)
{
    fillRect = fill;
    update();
}
