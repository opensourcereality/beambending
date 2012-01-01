#ifndef BENDINGMANIPULATOR_H
#define BENDINGMANIPULATOR_H

#include "beam.h"

class BendingManipulator
{
public:
    BendingManipulator(Beam *beam);
    virtual double getDeflection(double x)= 0;
    virtual double getSlope(double x) = 0;
    virtual double getMoment(double x) = 0;
    virtual double getShearForce(double x) = 0;
    virtual double getStress(double x) = 0;
    Beam *beam;


};

#endif // BENDINGMANIPULATOR_H
