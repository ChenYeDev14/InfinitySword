#ifndef STYLE_H
#define STYLE_H

#include <QWindowsStyle>
#include <QPixmap>

class Style : public QWindowsStyle
{
    Q_OBJECT

public:
    Style() {}

    void polish(QPalette &palette);
    void polish(QWidget *widget);
    void unpolish(QWidget *widget);
    int styleHint(StyleHint which, const QStyleOption *option,
                  const QWidget *widget = 0,
                  QStyleHintReturn *returnData = 0) const;
    int pixelMetric(PixelMetric which, const QStyleOption *option,
                    const QWidget *widget = 0) const;
    void drawPrimitive(PrimitiveElement which,
                       const QStyleOption *option, QPainter *painter,
                       const QWidget *widget = 0) const;
    void drawComplexControl(ComplexControl which,
                                         const QStyleOptionComplex *option,
                                         QPainter *painter,
                                         const QWidget *widget = 0) const;
   QRect subControlRect(ComplexControl whichControl,
                                      const QStyleOptionComplex *option,
                                      SubControl whichSubControl,
                                      const QWidget *widget = 0) const;

public slots:
    QIcon standardIconImplementation(StandardPixmap which,
                                     const QStyleOption *option,
                                     const QWidget *widget = 0) const;

private:
    void drawBronzeFrame(const QStyleOption *option,
                         QPainter *painter) const;
    void drawCamboButton(const QStyleOption *option,
                                      QPainter *painter) const;
    void drawBevel(const QStyleOption *option,
                         QPainter *painter) const;
    void drawComboBox(SubControl which,
            const QStyleOptionComplex *option, QPainter *painter) const;
};


#endif // STYLE_H
