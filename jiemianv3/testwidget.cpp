#include "testwidget.h"
#include "ui_testwidget.h"
#include <QPainter>

#include <QCryptographicHash>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include <QFileDialog>

#include <QMessageBox>
#include <QDebug>

const int max_round_num[10] = {75, 15, 45, 180, 0, 0, 0, 0, 0, 0};

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

    level = 0;
    testbattle = new TestBattle();
    connect(testbattle, SIGNAL(connect_error()), this, SLOT(connectError()));
    connect(testbattle, SIGNAL(game_end(int)), this, SLOT(result(int)));
    connect(testbattle, SIGNAL(init_error()), this, SLOT(initError()));
    connect(testbattle, SIGNAL(version_error()), this, SLOT(versionError()));
    connect(testbattle, SIGNAL(check_fail()), this, SLOT(checkFail()));
    connect(testbattle, SIGNAL(round_up(int)), this, SLOT(round(int)));

    but[0] = ui->pushButton_3;
    but[1] = ui->pushButton_4;
    but[2] = ui->pushButton_5;
    but[3] = ui->pushButton_6;
    but[4] = ui->pushButton_7;
    but[5] = ui->pushButton_8;
    but[6] = ui->pushButton_9;
    but[7] = ui->pushButton_10;
    but[8] = ui->pushButton_11;
    but[9] = ui->pushButton_12;
    for (int i=0; i<10; i++)
    {
        if (i < 6) but[i]->setEnabled(false); else but[i]->setEnabled(true);
    }
    for ( int i = 0 ; i < 9 ; i++ ){
        but[i]->move(but[9]->x(),but[9]->y());

    }
    test[0] = ui->test1;
    test[1] = ui->test2;
    test[2] = ui->test3;
    test[3] = ui->test4;
    test[4] = ui->test5;
    test[5] = ui->test6;
    test[6] = ui->test7;
    test[7] = ui->test8;
    test[8] = ui->test9;
    test[9] = ui->test10;

}

TestWidget::~TestWidget()
{
    delete testbattle;
    delete ui;
}

void TestWidget::SetUserName(QString user)
{
   user_name = user;
   testbattle->setUser(user);
}

void TestWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,1024,768,QPixmap(":/image/logIn.png"));
}

Ui::TestWidget* TestWidget::returnUi()
{
    return ui;
}

void TestWidget::upDateScores()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("166.111.223.20");
    db.setDatabaseName("team14");
    db.setUserName("team14");
    db.setPassword("duishi14_2012");
    if (!db.open()) return;
    QString columns = "test_1";
    for (int i=2; i<=10; i++) columns.append(",test_"+QString::number(i));
    columns.append(",nickname");
    QSqlQuery query(db);
    QString exe = "SELECT "+columns+" FROM user WHERE email = '"+user_name+"'";
    qDebug() << exe;
    query.exec(exe);
    if (query.next()) for (int i=0; i<10; i++)
    {
        scores[i] = query.value(i).toInt();
    }
    ui->label_nickname->setText(query.value(10).toString());
    db.close();
    printScore();
}


void TestWidget::printScore()
{
    QString scoreNum;
    for ( int i = 0 ; i < 10 ; i++ ){
        scoreNum.setNum(scores[i]);
        test[i]->setText(scoreNum);
    }
}

void TestWidget::setAllEnable(bool f)
{
    for (int i=9; i>=6; i--) but[i]->setEnabled(f);
    if (f) level = 0;
}

void TestWidget::on_pushButton_12_clicked()  //��һ��
{
    level = 1;
    setAllEnable(false);
    ui->progressBar->setRange(0, max_round_num[0]);
    ui->progressBar->setValue(0);
    testbattle->StartBattle(ui->lineEdit->text(), 1);
}

void TestWidget::on_pushButton_11_clicked() //�ڶ���
{
    level = 2;
    setAllEnable(false);
    ui->progressBar->setRange(0, max_round_num[1]);
    ui->progressBar->setValue(0);
    testbattle->StartBattle(ui->lineEdit->text(), 2);
}

void TestWidget::on_pushButton_10_clicked() //������
{
    level = 3;
    setAllEnable(false);
    ui->progressBar->setRange(0, max_round_num[2]);
    ui->progressBar->setValue(0);
    testbattle->StartBattle(ui->lineEdit->text(), 3);
}


void TestWidget::on_pushButton_9_clicked()  //���Ĺ�
{
    level = 4;
    setAllEnable(false);
    ui->progressBar->setRange(0, max_round_num[3]);
    ui->progressBar->setValue(0);
    testbattle->StartBattle(ui->lineEdit->text(), 4);
}


void TestWidget::connectError()
{
    QMessageBox box;
    box.setWindowTitle(tr("���Ӵ���"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("AI���ӳ���"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    setAllEnable(true);
}


void TestWidget::initError()
{
    QMessageBox box;
    box.setWindowTitle(tr("��ʼ������"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("AI��ʼ������"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    setAllEnable(true);
}

void TestWidget::pathError()
{
    QMessageBox box;
    box.setWindowTitle(tr("·������"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("AI·������"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    setAllEnable(true);
}


void TestWidget::updateTestScore(int new_score)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("166.111.223.20");
    db.setDatabaseName("team14");
    db.setUserName("team14");
    db.setPassword("duishi14_2012");
    if (!db.open())
    {
        QMessageBox box;
        box.setWindowTitle(tr("����"));
        box.setIcon(QMessageBox::Warning);
        box.setText(tr("���ӷ�����ʧ�ܣ�����δ�ϴ��������������ӡ�"));
        box.setStandardButtons(QMessageBox::Ok);
        box.exec();
        return;
    }
    QSqlQuery query(db);
    QString column = "test_" + QString::number(level);
    QString exe = "SELECT "+column+" FROM user WHERE email = '"+user_name+"'";
    query.exec(exe);
    int origin_score;
    if (query.next())
    {
        origin_score = query.value(0).toInt();
        if (origin_score >= new_score) return;
        exe = "UPDATE user SET "+column+" = "+"'"+QString::number(new_score)+"'"+" WHERE email = '"+user_name+"'";
        query.exec(exe);
        scores[level-1] = new_score;
        printScore();
    }
    db.close();
}

void TestWidget::result(int score)
{
    QMessageBox box;
    box.setWindowTitle(tr("�÷�"));
    box.setIcon(QMessageBox::Information);
    box.setText(QString::number(score));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    updateTestScore(score);
    setAllEnable(true);
}

void TestWidget::round(int i)
{
    ui->progressBar->setValue(i);
}


void TestWidget::versionError()
{
    QMessageBox box;
    box.setWindowTitle(tr("�汾����"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("AI�汾����"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    setAllEnable(true);
}

void TestWidget::checkFail()
{
    QMessageBox box;
    box.setWindowTitle(tr("AI�û�����"));
    box.setIcon(QMessageBox::Warning);
    box.setText(tr("AI�û���ƥ�䣬�벻Ҫʹ�����˵�AI"));
    box.setStandardButtons(QMessageBox::Ok);
    box.exec();
    setAllEnable(true);
}

void TestWidget::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("����AI"),
                "AIFiles/",
                tr("Ӧ�ó��� (*.exe)"));
    ui->lineEdit->setText(fileName);
}