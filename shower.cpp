#include "shower.h"
#include <QPainter>
#include <iostream>
using namespace std;

shower::shower(QWidget *parent, BendingManipulator *bender):
    QWidget(parent)
{
    this->myBender = bender;
}

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);

    //painter.drawLine();

    double x1 = 100, y1 = 100, x2 = 0, y2 = 0, beamLength = myBender->beam->GetLength();
    cout << "Beam length =" << beamLength << endl;

    for (double i = 0; i < 10 ; i += 0.1)
    {
        // we want to draw the beam 100 steps by drawing 1/100 of the beam every time using i the formula should change if i changes
        cout << "test " << myBender->getDeflection(i) << " i = " << i << endl;
        x2 = 100 + ((beamLength*10)/(100-(i*10)));
        y2 = 100 + (myBender->getDeflection(i)/60);

        painter.drawLine(x1, y1, x2, y2);

        cout << "x1 = " << x1 << " y1 = " << y1 << " x2 = "  << x2 << " y2 = " << y2 << endl;

        x1 = x2;
        y1 = y2;


    }




}

//void shower::magic(double x1, double y1, double x2, double y2)
//{
//    QPen pen(Qt::black, 2, Qt::SolidLine);
//    QPainter painter(this);
//    painter.setPen(pen);
//    painter.drawLine(x1, y1, x2, y2);
//}
