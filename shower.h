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

    // setters
    void setIntialDrawingPoint(double x = 100, double y = 100);
    void setDrawResolution(double val = 1000);
    void setMagnificationFactor(double val = 50);

    // getters
    double getIntialDrawingPointX();
    double getIntialDrawingPointY();
    double getDrawResolution();
    double getMagnificationFactor();

    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    BendingManipulator *myBender;
    double initialDrawX, initialDrawY, drawStep, drawResolution, magnificationFactor, visualBeamLength;

    // helping functions
    //void drawLoadIndecator(QPointF tip, QPainter &painter);

    
};

#endif // SHOWER_H
