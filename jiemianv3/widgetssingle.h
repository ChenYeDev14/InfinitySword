#ifndef WIDGETSSINGLE_H
#define WIDGETSSINGLE_H

#include <QWidget>
#include "aivsai.h"
#include "ui_widgetssingle.h"

class widgetssingle : public QWidget
{
    Q_OBJECT
    
public:
    explicit widgetssingle(QWidget *parent = 0);
    ~widgetssingle();
    Ui::widgetssingle *ui;
    
private slots:
    void playervsai();
    void levelmode();
    void replay();
    void mapedit();

};

#endif // WIDGETSSINGLE_H
