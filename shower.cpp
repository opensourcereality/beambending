#include "shower.h"
#include <QPainter>

shower::shower(QWidget *parent):
    QWidget(parent)
{
}

void shower::paintEvent(QPaintEvent *event)
{
    QPen pen(Qt::red, 2, Qt::SolidLine);

    QPainter painter(this);

    painter.setPen(pen);
    painter.drawLine(100, 100, 300, 100);

}
