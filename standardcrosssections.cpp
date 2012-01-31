#include "standardcrosssections.h"

#include "crosssections/rectangle.h"

StandardCrossSections::StandardCrossSections()
{
    n = 1;

    //standard cross sections
    crossSection = new CrossSection *[n];
    material[0] = new Rectangle(1,1);
}
