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
    intialDrawX = x;
    intialDrawY = y;
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
    return intialDrawX;
}
double shower::getIntialDrawingPointY()
{
    return intialDrawY;
}
double shower::getDrawResolution()
{
    return drawResolution;
}
double shower::getMagnificationFactor()
{
    return magnificationFactor;
}

// helping functions
//void shower::drawLoadIndecator(QPointF tip, QPainter &painter)
//{
//    // drawing the arrwo indicating single load

//    QPolygonF trianglePoints;
//    trianglePoints << QPointF(tip.x()-2,tip.y()-4) << tip << QPointF(tip.x()+2,tip.y()-4);
//    painter.drawConvexPolygon(trianglePoints);

//}

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);
    QPainter painter(this);

    painter.setPen(pen);
    double x1 = intialDrawX, y1 = intialDrawY, x2 = 0, y2 = 0, beamLength = myBender->beam->GetLength();

    visualBeamLength = 500;
    drawStep = beamLength / drawResolution;

    //double loadPos = myBender->load->getLoadPosition();

    for (double i = 0; i < beamLength ; i += drawStep)
    {
        // we want to draw the beam 100 steps by drawing 1/100 of the beam every time using i the formula should change if i changes
//        if (i = loadPos)
//        {
//            //drawLoadIndecator(QPointF(x1, y1), painter);
//        }
        cout << "test " << myBender->getDeflection(i) << " i = " << i << endl;
        x2 = intialDrawX + (i*((visualBeamLength)/(drawResolution * drawStep)));
        y2 = intialDrawY + (myBender->getDeflection(i)/60);

        //painter.drawLine(x1, y1, x2, y2);

        cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = "  << x2 << " y2 = " << y2 << " i: " << i << endl;

        x1 = x2;
        y1 = y2;
    }

    // drawing suspension area (rectangle)
    QBrush brush(Qt::black);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(90, 90, 10, 20);




    cout << "Load position: " << myBender->load->getLoadPosition() << endl;
}
