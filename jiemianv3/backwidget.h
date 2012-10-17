#ifndef BACKWIDGET_H
#define BACKWIDGET_H

#include <QWidget>
#include "ui_backwidget.h"

namespace Ui {
class BackWidget;
}

class BackWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit BackWidget(QWidget *parent = 0);
    ~BackWidget();
    
private:
    Ui::BackWidget *ui;
};

#endif // BACKWIDGET_H
