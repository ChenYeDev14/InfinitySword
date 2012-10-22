#ifndef HERODISPLAY_H
#define HERODISPLAY_H

#include <QWidget>
#include "platform/Basic.h"
#include <iostream>

class heroDisplay : public QWidget
{
    Q_OBJECT
private:
    bool selected;
    int heroIndex;
    DS14::HeroInfo heroInfo;
public:
    explicit heroDisplay(QWidget *parent = 0);
    void setHeroInfo(DS14::HeroInfo HI);
    void setSelected(bool wether);
    void setHeroIndex(int HI);
    void paintEvent(QPaintEvent *e);
    //void paint();
    
signals:
    
public slots:
    
};

#endif // HERODISPLAY_H
