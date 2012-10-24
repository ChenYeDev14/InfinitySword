#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPushButton>
#include "ui_testwidget.h"
#include<QtSql/qsqldatabase.h>
#include<QtSql/qsqlerror.h>
#include<QtSql/qsqlquery.h>
#include "platform/TestBattle.h"

using namespace DS14;
namespace Ui {
class TestWidget;
}

class TestBattle;

class TestWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit TestWidget(QWidget *parent = 0);
    ~TestWidget();
    QPushButton* but[10];
    Ui::TestWidget* returnUi();
    void SetUserName(QString user);
    void upDateScores();
    void printScore();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

    void connectError();
    void pathError();
    void initError();
    void round(int);
    void versionError();
    void result(int);
    void checkFail();

    void on_pushButton_2_clicked();

private:
    TestBattle *testbattle;
    Ui::TestWidget *ui;
    void paintEvent(QPaintEvent *);
    QString user_name;
    QSqlDatabase db;
    int scores[10];
    int level;
    QLabel * test[10];
    //TestBattle *testbattle;
    void setAllEnable(bool f);
    void updateTestScore(int score);
};

#endif // TESTWIDGET_H
