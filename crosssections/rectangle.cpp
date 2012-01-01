#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::getInertiaAreaMoment(){
    return (width * sqr(height) * height)/12;
}
