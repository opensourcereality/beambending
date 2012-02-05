#ifndef SIMPLYSUPPORTED_H
#define SIMPLYSUPPORTED_H

#include "bendingmanipulator.h"

class SimplySupportedBendingManipulator : public BendingManipulator
{
public:
    SimplySupportedBendingManipulator(Beam *beam, Load *load);

private:
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);
    double getUniformMoment(double x);
    double getSingleMoment(double x);
};

#endif // SIMPLYSUPPORTED_H
