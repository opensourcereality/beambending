#ifndef STANDARDCROSSSECTIONS_H
#define STANDARDCROSSSECTIONS_H

#include "crosssection.h"

class StandardCrossSections
{
public:
    StandardCrossSections();

    CrossSection **crossSection;
    int n;

public:

    CrossSection *get(int i){ return crossSection[i];}
    int count() { return n; }

};

#endif // STANDARDCROSSSECTIONS_H
