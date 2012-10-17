#ifndef HERODISPLAY_H
#define HERODISPLAY_H

#include <QWidget>
#include "Basic.h"
#include <iostream>

class QPushButton;
class QLabel;
using namespace DS14;
class heroDisplay : public QWidget
{
    Q_OBJECT
private:
    int heroIndex;
    HeroInfo heroInfo;
    QPushButton *detail_button;
    QLabel *detail_label;
public:
    explicit heroDisplay(QWidget *parent = 0);
    ~heroDisplay();
    void setHeroInfo(DS14::HeroInfo HI);
    void setHeroIndex(int HI);
    void setDetailPosition(QPoint p);
    void paintEvent(QPaintEvent *e);
    
signals:
    
public slots:

private slots:
    void detail_clicked();
};

#endif // HERODISPLAY_H
