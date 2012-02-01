#include "shower.h"
#include <QPainter>
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

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);
    QPainter painter(this);

    painter.setPen(pen);
    double x1 = intialDrawX, y1 = intialDrawY, x2 = 0, y2 = 0, beamLength = myBender->beam->GetLength();

    visualBeamLength = beamLength * magnificationFactor;
    drawStep = 1 / (drawResolution / beamLength);

    for (double i = 0; i < beamLength ; i += drawStep)
    {
        // we want to draw the beam 100 steps by drawing 1/100 of the beam every time using i the formula should change if i changes

        cout << "test " << myBender->getDeflection(i) << " i = " << i << endl;
        x2 = intialDrawX + (i*((visualBeamLength)/beamLength));
        y2 = intialDrawY + (myBender->getDeflection(i)/60);
        painter.drawLine(x1, y1, x2, y2);

        cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = "  << x2 << " y2 = " << y2 << " i: " << i << endl;

        x1 = x2;
        y1 = y2;

    }
}
