#ifndef AIVSAI_H
#define AIVSAI_H

#include <QWidget>
#include "ui_aivsai.h"
#include "platform/NormalBattle.h"

using namespace DS14;
class AIvsAI : public QWidget
{
    Q_OBJECT
    
public:
    explicit AIvsAI(QWidget *parent = 0);
    ~AIvsAI();
    Ui::AIvsAI *ui;
    
private slots:
    void AI1();
    void AI2();
    void on_Start_clicked();
    void Map();

    void connectError(int);
    void initError(int);
    void pathError(int);
    void sendWinner(int);
    void round(int);
    void versionError(int);

private:
    NormalBattle * battle;
};

#endif // AIVSAI_H
