#include "circle.h"
#include "circleform.h"

Circle::Circle(double radius)
{
    this->radius = radius;
    this->name = "Circle";
}

double Circle::getInertiaAreaMoment()
{
    return radius;
}

void Circle::constructForm(QWidget *parent)
{
    this->form = new CircleForm(parent);
}

void Circle::setRadius(double radius)
{
    this->radius = radius;
}
