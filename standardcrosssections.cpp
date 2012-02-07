#include "standardcrosssections.h"

#include "crosssections/rectangle.h"
#include "crosssections/circle.h"
#include "crosssections/ibeam.h"

StandardCrossSections::StandardCrossSections()
{
    n = 3;

    //standard cross sections
    crossSection = new CrossSection *[n];
    crossSection[0] = new Rectangle(0.06,0.03);
    crossSection[1] = new Circle(0.06);
    crossSection[2] = new IBeam(0.06, 0.091, 0.00110, 0.08000);
}
