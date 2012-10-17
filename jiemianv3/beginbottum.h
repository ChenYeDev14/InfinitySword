#ifndef BEGINBOTTUM_H
#define BEGINBOTTUM_H

#include <QWidget>
#include "ui_beginbottum.h"
#include "browser.h"
#include <QMainWindow>

namespace Ui {
class BeginBottum;
}

class BeginBottum : public QWidget
{
    Q_OBJECT
    
public:
    explicit BeginBottum(QWidget *parent = 0);
    ~BeginBottum();
    Ui::BeginBottum* returnUi();
    
private slots:
    void on_website_clicked();

private:
    Ui::BeginBottum *ui;
    Browser *browser;
};

#endif // BEGINBOTTUM_H
