#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QLabel>
#include <QList>
#include "platform/Status.h"
#include "ui_mapeditor.h"
#include "qlabel_real.h"

using namespace std;
using namespace DS14;

namespace Ui {
class MapEditor;
}

struct Xy{
    int type;
    int num;
};

class MapEditor : public QWidget
{
    Q_OBJECT
    
public:
    explicit MapEditor(QWidget *parent = 0);
    ~MapEditor();
    Ui::MapEditor* returnUi();
    void SetMapInfo();
    void OpenFile();
    void Init();

    
private:
    Ui::MapEditor *ui;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *dragEvent);
    void dragLeaveEvent(QDragLeaveEvent *dragEvent);
    void dragMoveEvent(QDragMoveEvent *dragEvent);
    void dropEvent(QDropEvent *dragEvent);
    bool isSaveOrNot();

    Coordinate DeviceToLogic(Coordinate deviceCo);
    double Round(int x,int y,int xx,int yy);
    bool coulddrop(int x,int y,int radius);
    Xy findPic(int x,int y);
    bool couldSave();

    int MapType;
    QLabel_Real *hero1[3],*hero2[3],*base1,*base2,*stuck[50],*slow[50];
    int hero1Num,hero2Num,base1Num,base2Num,stuckNum,slowNum;
    Xy dragID;
    int xPosition,yPointion;
    StatusMapInfo mInfo;
    QString curFile;
    bool isSaved;


private slots:
    void Radio_1();
    void Radio_2();
    void Radio_3();
    void Radio_4();
    void Radio_5();
    void Radio_6();
    void Radio_7();
    void Save();
    void Open();
    void newFile();

    void on_pushButton_6_clicked();
    void on_pushButton_4_clicked();
};

#endif // MAPEDITOR_H
