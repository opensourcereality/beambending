#include "standardcrosssections.h"

#include "crosssections/rectangle.h"
#include "crosssections/circle.h"
#include "crosssections/ibeam.h"

StandardCrossSections::StandardCrossSections()
{
    n = 3;

    //standard cross sections
    crossSection = new CrossSection *[n];
    crossSection[0] = new Rectangle(0.01,0.01);
    crossSection[1] = new Circle(1);
    crossSection[2] = new IBeam(1.5, 1.5, 0.5, 0.5);
}
