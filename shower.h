#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"

class beam;
class BendingManipulator;

class shower : public QWidget
{
    Q_OBJECT
public:
    explicit shower(QWidget *parent = 0, BendingManipulator *bender = 0);
    //void magic(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    BendingManipulator *myBender;


    
};

#endif // SHOWER_H
