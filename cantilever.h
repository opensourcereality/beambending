#ifndef CANTILEVER_H
#define CANTILEVER_H

#include "bendingmanipulator.h"


class CantileverBendingManipulator : public BendingManipulator
{
public:
    CantileverBendingManipulator(Beam *beam);

private:
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);
};

#endif // CANTILEVER_H
