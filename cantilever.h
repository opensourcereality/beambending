#ifndef CANTILEVER_H
#define CANTILEVER_H

#include "bendingmanipulator.h"


class CantileverBendingManipulator : public BendingManipulator
{
public:
    CantileverBendingManipulator(Beam *beam, Load *load);
    double getMaxMoment();


private:
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);
    double getUniformMoment(double x);
    double getSingleMoment(double x);

};

#endif // CANTILEVER_H
