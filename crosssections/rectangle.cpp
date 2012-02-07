#include "rectangle.h"
#include "rectangleform.h"
#include "math.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
    this->name = "Rectangle";
}

double Rectangle::getInertiaAreaMoment(){
    // taken from Wolfram demonstration, gives values matching efunda
    cout << "width: " << width << " hight: " << height << endl;
    return (width * height * height * height)/12;
}

double Rectangle::getDiatanceFromNeutralAxis()
{
    return (height / 2);
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
    this->height = height;
}

void Rectangle::constructForm(double beamLength, QWidget *parent)
{
    this->form = new RectangleForm(this, beamLength, parent);
}


