#include "circle.h"
#include "circleform.h"

Circle::Circle(double radius)
{
    this->radius = radius;
    this->name = "Circle";
}

double Circle::getInertiaAreaMoment()
{
    return 5/4 * (3.14) * radius * radius * radius * radius;
}

void Circle::constructForm(QWidget *parent)
{
    this->form = new CircleForm(this, parent);
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}
