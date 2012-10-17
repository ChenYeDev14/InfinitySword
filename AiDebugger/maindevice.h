#ifndef MAINDEVICE_H
#define MAINDEVICE_H

#include <QWidget>
#include "herodisplay.h"
#include "replaydevice.h"
#include "Status.h"
#include "logic.h"
#include <QLabel>
#include <QtGui>

class maindevice : public QWidget
{
    Q_OBJECT
private:
    heroDisplay AI1Hero[3];
    heroDisplay AI2Hero[3];
    QLabel AI1Info;
    QLabel AI2Info;
    replayDevice gameDisplay;
    DS14::Status state;

protected:


public:
    explicit maindevice(const DS14::Status s, QWidget *parent = 0);
    void setStatus(DS14::Status st) {state = st;}
    void repaint();
    ~maindevice();
    

};

#endif // MAINDEVICE_H
