#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../crosssection.h"

class Rectangle : public CrossSection
{
public:
    Rectangle(double width, double height);

    double getInertiaAreaMoment();
    double getDiatanceFromNeutralAxis();
    void constructForm(double beamLength, QWidget* parent = 0);

    void setSize(double width, double height);
    void setHeight(double height);
    void setWidth(double width);
    double getHeight()  {return height;}
    double getWidth() {return width;}

private:
    double width;
    double height;

};

#endif // RECTANGLE_H
