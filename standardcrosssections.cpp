#include "standardcrosssections.h"

#include "crosssections/rectangle.h"
#include "crosssections/circle.h"

StandardCrossSections::StandardCrossSections()
{
    n = 2;

    //standard cross sections
    crossSection = new CrossSection *[n];
    crossSection[0] = new Rectangle(1,1);
    crossSection[1] = new Circle(1);
}
