#ifndef BEAM_H
#define BEAM_H

#include "material.h"
#include "crosssection.h"
#include "load.h"


class Beam

{
public:
    Beam();
    double getDeflection(double x);
    double getSlope(double x);
    double getMoment(double x);
    double getShearForce(double x);
    double getStress(double x);


private:
    double length;
    CrossSection crossSection;
    Material material;
    Load load;

};

#endif // BEAM_H
