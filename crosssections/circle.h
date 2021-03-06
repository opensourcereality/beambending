#ifndef CIRCLE_H
#define CIRCLE_H

#include "crosssection.h"

class Circle : public CrossSection
{
public:
    Circle(double radius);
    double getInertiaAreaMoment();
    double getDiatanceFromNeutralAxis();
    void constructForm(double beamLength, QWidget* parent = 0);
    void setRadius(double radius);
    double getRadius() { return radius; }

private:
    double radius;
};

#endif // CIRCLE_H
