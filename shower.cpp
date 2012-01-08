#include "shower.h"
#include <QPainter>
#include <iostream>
using namespace std;

shower::shower(QWidget *parent, BendingManipulator *bender):
    QWidget(parent)
{
    myBender = bender;
}

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    //painter.drawLine();

    double beamLength = myBender->beam->GetLength();
    cout << "Beam length =" << beamLength << endl;

    painter.drawLine(100,100,100 + beamLength, 100);


}

//void shower::magic(double x1, double y1, double x2, double y2)
//{
//    QPen pen(Qt::black, 2, Qt::SolidLine);
//    QPainter painter(this);
//    painter.setPen(pen);
//    painter.drawLine(x1, y1, x2, y2);
//}
