#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "E:\InfinitySword\jiemianv3\platform\NormalBattle.h"
#include "maindevice.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_AI_clicked();

    void on_pushButton_Map_clicked();

    void pathError(int);
    void startDebugAI(QString);
    void connectError(int);
    void roundUp(int);
    void winner(int);
    void initError(int);
    void versionError(int);
    void Debug(int);
    void startShowReplay();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_2_clicked();

    void on_horizontalSlider_3_valueChanged(int value);

    void on_pushButton_show_round_minus_clicked();

    void on_pushButton_show_round_plus_clicked();

private:
    Ui::Widget *ui;
    DS14::NormalBattle *battle;
    int debugside;
    maindevice *repWidget;
    DS14::Status *statusList;
    int cur_round;
    int show_round;
};

#endif // WIDGET_H
