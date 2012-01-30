#include "rectangle.h"
#include "math.h"

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::getInertiaAreaMoment(){
    return (width * height * height * height)/12;
}

void Rectangle::setSize(double width, double height)
{
    this->width = width;
    this->height = height;
}
