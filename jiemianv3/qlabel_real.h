#ifndef QLABEL_REAL_H
#define QLABEL_REAL_H

#include <QLabel>
#include <QPointF>
#include <QWidget>

class QLabel_Real : public QLabel
{
    Q_OBJECT
public:
    explicit QLabel_Real(QWidget *parent = 0);
    void setGeometry(double x, double y, double w, double h);
    double x() const;
    double y() const;
    double height() const;
    double width() const;
    
signals:
    
public slots:

private:
    QPointF* pointF;
    QPointF* pointFhw;
    
};

#endif // QLABEL_REAL_H
