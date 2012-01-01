#ifndef BEAM_H
#define BEAM_H

#include "material.h"
#include "crosssection.h"

class Beam

{
public:
    Beam(double length, CrossSection crossSection, Material material);

private:
    double length;
    CrossSection crossSection;
    Material material;

};

#endif // BEAM_H
