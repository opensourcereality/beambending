#ifndef BENDINGMANIPULATOR_H
#define BENDINGMANIPULATOR_H

#include "beam.h"
#include "load.h"
class BendingManipulator
{
public:
    BendingManipulator(Beam *beam, Load *load);

    double getDeflection(double x);
    //virtual double getSlope(double x) = 0;
    //virtual double getMoment(double x) = 0;
    //virtual double getShearForce(double x) = 0;
    //virtual double getStress(double x) = 0;
    Beam *beam;
    Load *load;



private:
    virtual double getUniformDeflection(double x) = 0;
    virtual double getSingleDeflection(double x) = 0;



};

#endif // BENDINGMANIPULATOR_H
