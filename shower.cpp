#include "shower.h"
#include <QPainter>

shower::shower(QWidget *parent):
    QWidget(parent)
{
}

void shower::paintEvent(QPaintEvent *event, double x1, double y1, double x2, double y2)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    painter.drawLine(x1, y1,x2 , y2);

}
