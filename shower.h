#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"
#include "beam.h"
class beam;
class BendingManipulator;

class shower : public QWidget
{
    Q_OBJECT
public:
    explicit shower(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event, double x1=0, double y1=0, double x2=0, double y2=0);
    
signals:
    
public slots:


    
};

#endif // SHOWER_H
