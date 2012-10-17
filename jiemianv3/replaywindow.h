#ifndef REPLAYWINDOW_H
#define REPLAYWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include "platform/replayfile.h"
#include "platform/Basic.h"
#include "platform/Logic.h"
#include "platform/Status.h"
#include "ui_replaywindow.h"

namespace Ui {
class ReplayWindow;
}

class ReplayWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit ReplayWindow(QWidget *parent = 0);
    ~ReplayWindow();
    Ui::ReplayWindow* returnUi();
    
private slots:

    //void changeTime(int n);

    void ChangeRound(int n);
    void timerStop();

    void timerDone();

    void on_loadButton_clicked();

    void on_startButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_2_sliderPressed();

    void on_horizontalSlider_2_sliderReleased();

    void on_horizontalSlider_sliderPressed();

    void on_horizontalSlider_sliderReleased();

    void on_stopButton_1_clicked();

    void on_pushButton_2_clicked();

    void Label_show( int i ,int n );

    void on_pushButton_clicked();

public slots:
    void GoInto();

private:

    void closeEvent(QCloseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

    void show_onemove_back(int i,int j);
    void show_onemove_forward(int i,int j);
    void hero_set_(int n,double x,double y,bool show);


    double transfer_horizontal(double x);
    double transfer_vertical(double y);

    double read_hero_x(int n,int ROUND);
    double read_hero_y(int n,int ROUND);

    Ui::ReplayWindow *ui;

    QLabel *hero[6];

    QLabel *Label_showInfo;

    QTimer *timer;

    DS14::status *statusList[2400];

    DS14::PlayerInfo pInfo[2];

    QList<QLabel*> picture;

    bool ifStatus,isRun;

    int roundNum;

    void sleep(unsigned int msec);

signals:

    void show( int i ,int n);
};

#endif // REPLAYWINDOW_H
