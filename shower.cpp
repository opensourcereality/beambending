#include "shower.h"
#include <QPainter>
#include <QBrush>
#include <QPointF>
#include <QPolygonF>
#include <iostream>
using namespace std;

shower::shower(QWidget *parent, BendingManipulator *bender):
    QWidget(parent)
{
    this->myBender = bender;
    this->setFixedSize(700,350);

    // Setting visual parameteres
    setIntialDrawingPoint(100,100);
    setDrawResolution(1000);
    setMagnificationFactor(50);
}

// setters
void shower::setIntialDrawingPoint(double x, double y)
{
    initialDrawX = x;
    initialDrawY = y;
}
void shower::setDrawResolution(double val)
{
    drawResolution = (val > 10 ? val : 1000);
}
void shower::setMagnificationFactor(double val)
{
    magnificationFactor = (val > 0 ? val : 50);
}

// getters
double shower::getIntialDrawingPointX()
{
    return initialDrawX;
}
double shower::getIntialDrawingPointY()
{
    return initialDrawY;
}
double shower::getDrawResolution()
{
    return drawResolution;
}
double shower::getMagnificationFactor()
{
    return magnificationFactor;
}

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);
    QPainter painter(this);

    painter.setPen(pen);
    double x1 = initialDrawX, y1 = initialDrawY, x2 = 0, y2 = 0, beamLength = myBender->beam->GetLength();

    visualBeamLength = 500;
    drawStep = beamLength / drawResolution;


    // intial level line
    QBrush brush(Qt::black);
    painter.setBrush(brush);
    pen.setStyle(Qt::DashLine);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(initialDrawX, initialDrawY, (initialDrawX+visualBeamLength), initialDrawY);

    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::red);
    painter.setPen(pen);

    for (double i = 0; i < beamLength ; i += drawStep)
    {
        // we want to draw the beam 100 steps by drawing 1/100 of the beam every time using i the formula should change if i changes
        cout << "test " << myBender->getDeflection(i) << " i = " << i << endl;
        x2 = initialDrawX + (i*((visualBeamLength)/(drawResolution * drawStep)));
        y2 = initialDrawY + (myBender->getDeflection(i)/60);

        painter.drawLine(x1, y1, x2, y2);

        cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = "  << x2 << " y2 = " << y2 << " i: " << i << endl;

        x1 = x2;
        y1 = y2;
    }

    // drawing suspension area (rectangle)
    brush.setColor(Qt::black);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(90, 90, 10, 20);


    // Load position Indecator
    if (myBender->load->isSingleLoad())
    {
        brush.setColor(Qt::blue);
        pen.setColor(Qt::blue);
        painter.setBrush(brush);
        painter.setPen(pen);
        double loadPos = myBender->load->getLoadPosition();
        QPointF tip;
        qreal tipX =  initialDrawX + (loadPos*((visualBeamLength)/(drawResolution * drawStep)));
        qreal tipY = initialDrawY + (myBender->getDeflection(loadPos)/60);
        tip.setX(tipX);
        tip.setY(tipY);
        QPolygonF trianglePoints;
        trianglePoints << QPointF(tip.x()-8,tip.y()-20) << tip << QPointF(tip.x()+8,tip.y()-20);
        painter.drawConvexPolygon(trianglePoints);

        cout << "test bendingIn3d branch :) :)" << endl;
    }

}
