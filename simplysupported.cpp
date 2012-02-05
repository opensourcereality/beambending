#include "simplysupported.h"

SimplySupportedBendingManipulator::SimplySupportedBendingManipulator(Beam *beam, Load *load)
    : BendingManipulator(beam, load)

{
}

double SimplySupportedBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), I = beam->GetMaterial()->GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();
    return (load->getLoadValue() * x * (l * l * l - (2*x*x*l) + x * x * x))/(24 * I * E);
}

double SimplySupportedBendingManipulator::getSingleDeflection(double x)
{
    double I = beam->GetMaterial()->GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment(), l = beam->GetLength();

    double constant = (load->getLoadValue())/(6 * E * I * l);

    double a = load->getLoadPosition();

    if( x < a )
        return constant *x*(l-a)*(-(a*a) + 2*l*a - (x*x));
    else
        return -constant *a*(l-x)*((a*a) + (x*x) - 2*l*x);
}
