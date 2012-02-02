#ifndef CIRCLE_H
#define CIRCLE_H

#include "crosssection.h"

class Circle : public CrossSection
{
public:
    Circle(double radius);
    double getInertiaAreaMoment();
    void constructForm(QWidget* parent = 0);
    void setRadius(double radius);
    double getRadius() { return radius; }

private:
    double radius;
};

#endif // CIRCLE_H
