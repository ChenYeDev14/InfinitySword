#include <QtGui>

#include "windowsstyle.h"

void Style::polish(QPalette &palette)
{
//    QColor blue(0, 0, 200);
//    QColor veryLightBlue(239, 239, 247);
//    QColor lightBlue(223, 223, 239);
//    QColor darkBlue(95, 95, 191);

//    palette = QPalette(blue);
//    palette.setBrush(QPalette::BrightText, Qt::white);
//    palette.setBrush(QPalette::Base, veryLightBlue);
//    palette.setBrush(QPalette::AlternateBase, lightBlue);
//    palette.setBrush(QPalette::Highlight, darkBlue);
//    palette.setBrush(QPalette::Disabled, QPalette::Highlight,
//                     Qt::darkGray);
}

void Style::polish(QWidget *widget)
{
    if (qobject_cast<QAbstractButton *>(widget))
    widget->setAttribute(Qt::WA_Hover, true);
    if (qobject_cast<QComboBox *>(widget))
    widget->setAttribute(Qt::WA_Hover, true);
}

void Style::unpolish(QWidget *widget)
{
    if (qobject_cast<QAbstractButton *>(widget))
        widget->setAttribute(Qt::WA_Hover, false);
}

int Style::styleHint(StyleHint which, const QStyleOption *option,
                           const QWidget *widget,
                           QStyleHintReturn *returnData) const
{
    switch (which) {
    case SH_DialogButtonLayout:
        return int(QDialogButtonBox::MacLayout);
    case SH_EtchDisabledText:
        return int(true);
    case SH_DialogButtonBox_ButtonsHaveIcons:
        return int(true);
    case SH_UnderlineShortcut:
        return int(false);
    default:
        return QWindowsStyle::styleHint(which, option, widget,
                                        returnData);
    }
}

int Style::pixelMetric(PixelMetric which,
                             const QStyleOption *option,
                             const QWidget *widget) const
{
    switch (which) {
    case PM_ButtonDefaultIndicator:
        return 0;
    case PM_IndicatorWidth:
    case PM_IndicatorHeight:
        return 16;
    case PM_CheckBoxLabelSpacing:
        return 8;
    case PM_DefaultFrameWidth:
        return 2;
    default:
        return QWindowsStyle::pixelMetric(which, option, widget);
    }
}

void Style::drawPrimitive(PrimitiveElement which,
                                const QStyleOption *option,
                                QPainter *painter,
                                const QWidget *widget) const
{
    switch (which) {
    case PE_PanelButtonCommand:
        drawBevel(option, painter);
         //QWindowsStyle::drawPrimitive(which, option, painter, widget);
        break;
    case PE_Frame:
        drawBronzeFrame(option, painter);
        break;
    case PE_FrameDefaultButton:
        break;
    default:
        QWindowsStyle::drawPrimitive(which, option, painter, widget);
    }
}

void Style::drawComplexControl(ComplexControl which,
                                     const QStyleOptionComplex *option,
                                     QPainter *painter,
                                     const QWidget *widget) const
{
    if (which == CC_ComboBox) {
        drawComboBox(SC_ComboBoxArrow, option, painter);

        QRect rect = subControlRect(CC_ComboBox, option,
                                    SC_ComboBoxEditField)
                     .adjusted(-1, 0, +1, 0);
        painter->setPen(QPen(option->palette.mid(), 1.0));
        painter->drawLine(rect.topRight(), rect.bottomRight());
    } else {
        return QWindowsStyle::drawComplexControl(which, option, painter,
                                                 widget);
    }
}

QRect Style::subControlRect(ComplexControl whichControl,
                                  const QStyleOptionComplex *option,
                                  SubControl whichSubControl,
                                  const QWidget *widget) const
{
    if (whichControl == CC_ComboBox) {
        int frameWidth = pixelMetric(PM_DefaultFrameWidth, option,
                                     widget);
        int buttonWidth = 16;

        switch (whichSubControl) {
        case SC_ComboBoxFrame:
            return option->rect;
        case SC_ComboBoxEditField:
            return option->rect.adjusted(0, +frameWidth,
                                         -buttonWidth-frameWidth,0);
        case SC_ComboBoxArrow:
            return visualRect(option->direction, option->rect,
                              QRect(option->rect.right() - buttonWidth,
                                    option->rect.y(),
                                    buttonWidth,
                                    option->rect.height()));
        default:
            return QWindowsStyle::subControlRect(whichControl, option,
                                                 whichSubControl, widget);
        }
    } else {
        return QWindowsStyle::subControlRect(whichControl, option,
                                             whichSubControl, widget);
    }
}

QIcon Style::standardIconImplementation(StandardPixmap which,
        const QStyleOption *option, const QWidget *widget) const
{
    QImage image = QWindowsStyle::standardPixmap(which, option, widget)
                   .toImage();
    if (image.isNull())
        return QIcon();

    QPalette palette;
    if (option) {
        palette = option->palette;
    } else if (widget) {
        palette = widget->palette();
    }

    QPainter painter(&image);
    painter.setOpacity(0.25);
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter.fillRect(image.rect(), palette.highlight());
    painter.end();

    return QIcon(QPixmap::fromImage(image));
}

void Style::drawBronzeFrame(const QStyleOption *option,
                                  QPainter *painter) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(option->palette.foreground(), 1.0));
    painter->drawRect(option->rect.adjusted(+1, +1, -1, -1));
    painter->restore();
}

void Style::drawBevel(const QStyleOption *option,
                                  QPainter *painter) const
{
    QPixmap picin = QPixmap(":/image/16.png");
    QPixmap picout = QPixmap(":/image/13.png");

    QPixmap pic = (option->state & State_MouseOver) ? picin : picout;
    if(!(option->state & State_Enabled))
        pic = QPixmap(":/image/21.png");


    double penWidth = 1.0;
    if (const QStyleOptionButton *buttonOpt =
            qstyleoption_cast<const QStyleOptionButton *>(option)) {
        if (buttonOpt->features & QStyleOptionButton::DefaultButton)
            penWidth = 2.0;
    }


    QRect rect = option->rect.adjusted(+1, +1, -1, -1);
    if (!rect.isValid())
        return;

//    int diameter = 20;
//    int cx = 100 * diameter / roundRect.width();
//    int cy = 100 * diameter / roundRect.height();

    painter->setOpacity(1);
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(pic);
    painter->drawRect(rect);

    if (option->state & (State_On | State_Sunken)) {
        QColor slightlyOpaqueBlack(0, 0, 0, 63);
        painter->setBrush(slightlyOpaqueBlack);
        painter->drawRect(rect);
    }

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(option->palette.foreground(), penWidth));
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(rect);
    painter->restore();
}

void Style::drawCamboButton(const QStyleOption *option,
                                  QPainter *painter) const
{
    QColor buttonColor = option->palette.button().color();

    double penWidth = 1.0;
    if (const QStyleOptionButton *buttonOpt =
            qstyleoption_cast<const QStyleOptionButton *>(option)) {
        if (buttonOpt->features & QStyleOptionButton::DefaultButton)
            penWidth = 2.0;
    }

    QRect roundRect = option->rect.adjusted(+1, +1, -1, -1);
    if (!roundRect.isValid())
        return;

    int diameter = 12;
    int cx = 100 * diameter / roundRect.width();
    int cy = 100 * diameter / roundRect.height();

    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(buttonColor);
    painter->drawRoundRect(roundRect, cx, cy);

    if (option->state & (State_On | State_Sunken)) {
        QColor slightlyOpaqueBlack(0, 0, 0, 63);
        painter->setBrush(slightlyOpaqueBlack);
        painter->drawRoundRect(roundRect, cx, cy);
    }

    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(option->palette.foreground(), penWidth));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundRect(roundRect, cx, cy);
    painter->restore();
}

void Style::drawComboBox(SubControl which,
        const QStyleOptionComplex *option, QPainter *painter) const
{
    PrimitiveElement arrow = PE_IndicatorArrowDown;
    QRect buttonRect = option->rect;
    buttonRect.setWidth(buttonRect.width());

    QStyleOption buttonOpt(*option);
    QPalette pal(QColor(255,255,255));
    buttonOpt.palette = pal;

    painter->save();
    painter->setClipRect(buttonRect, Qt::IntersectClip);
    if (!(option->activeSubControls & which))
        buttonOpt.state &= ~(State_MouseOver | State_On | State_Sunken);
    drawCamboButton(&buttonOpt, painter);

    QStyleOption arrowOpt(buttonOpt);
    arrowOpt.rect = subControlRect(CC_ComboBox, option, which)
                    .adjusted(+3, +3, -3, -3);
    if (arrowOpt.rect.isValid())
        drawPrimitive(arrow, &arrowOpt, painter);
    painter->restore();
}
