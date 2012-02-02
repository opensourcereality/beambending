#include "rectangle.h"
#include "rectangleform.h"
#include "math.h"

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
    this->name = "Rectangle";
}

double Rectangle::getInertiaAreaMoment(){
    return (width * height * height * height)/12;
}

void Rectangle::setSize(double width, double height)
{
    this->width = width;
    this->height = height;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

void Rectangle::setHeight(double height)
{
    this->width = height;
}

void Rectangle::constructForm(QWidget *parent)
{
    this->form = new RectangleForm(this, parent);
}
