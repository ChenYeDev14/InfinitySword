#ifndef TEAMMENU_H
#define TEAMMENU_H

#include <QWidget>
#include "ui_teammenu.h"

namespace Ui {
class TeamMenu;
}

class TeamMenu : public QWidget
{
    Q_OBJECT
    
public:
    explicit TeamMenu(QWidget *parent = 0);
    ~TeamMenu();
    Ui::TeamMenu* returnUi();

    
private:
    Ui::TeamMenu *ui;
};

#endif // TEAMMENU_H
