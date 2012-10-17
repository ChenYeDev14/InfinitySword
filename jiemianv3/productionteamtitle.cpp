#include <QtGui>
#include <QFont>
#include "productionteamtitle.h"

ProductionTeamTiltle::ProductionTeamTiltle(QWidget *parent)
    : QWidget(parent)
{
    offset = 0;
    myTimerId = 0;

    QPalette palette = this->palette();
    palette.setColor(QPalette::Foreground,QColor(255,255,255));
    this->setPalette(palette);
    QFont font = this->font();
    font.setFamily("Î¢ÈíÑÅºÚ");
    //font.setPointSize(200);
    this->setFont(font);
}

void ProductionTeamTiltle::setText(const QString &newText)
{
    myText = newText;
    update();
    updateGeometry();
}

QSize ProductionTeamTiltle::sizeHint() const
{
    return fontMetrics().size(0, text());
}

void ProductionTeamTiltle::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    int textWidth = fontMetrics().width(text());
    if (textWidth < 1)
        return;
    int x = -offset;
    while (x < width()) {
        painter.drawText(x, 0, textWidth, height(),
                         Qt::AlignLeft | Qt::AlignVCenter, text());
        x += textWidth;
    }
}

void ProductionTeamTiltle::showEvent(QShowEvent * /* event */)
{
    myTimerId = startTimer(30);
}

void ProductionTeamTiltle::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimerId) {
        ++offset;
        if (offset >= fontMetrics().width(text())/6)
            offset = 0;
        scroll(-1, 0);
    } else {
        QWidget::timerEvent(event);
    }
}

void ProductionTeamTiltle::hideEvent(QHideEvent * /* event */)
{
    killTimer(myTimerId);
    myTimerId = 0;
}

