#ifndef MIXEDSUPPORTED_H
#define MIXEDSUPPORTED_H

#include "bendingmanipulator.h"

class MixedSupportedBendingManipulator : public BendingManipulator
{
public:
    MixedSupportedBendingManipulator(Beam *beam, Load *load);
    double getMaxMoment();


private:
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);
    double getUniformMoment(double x);
    double getSingleMoment(double x);

};

#endif // MIXEDSUPPORTED_H
