#include "cantilever.h"
#include "qmath.h"

CantileverBendingManipulator::CantileverBendingManipulator(Beam *beam) :
    BendingManipulator(beam)
{
}

double CantileverBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), I = beam->GetMaterial().GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();
    return -(getLoadValue() * x * x * (6 * l - (4*x*l) + x * x))/(24 * I * E);
}

double CantileverBendingManipulator::getSingleDeflection(double x)
{
    double I = beam->GetMaterial().GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();

    double constant = (-getLoadValue())/(6 * E * I);

    double loadPosition = getLoadPosition();

    if( x < loadPosition )
        return constant *(x*x)*(3*loadPosition - x);
    else
        return constant *(loadPosition * loadPosition)*(3*x - loadPosition);

}



