#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../crosssection.h"

class Rectangle : public CrossSection
{
public:
    Rectangle(double width, double height);
    double getInertiaAreaMoment();

private:
    double width;
    double height;

};

#endif // RECTANGLE_H
