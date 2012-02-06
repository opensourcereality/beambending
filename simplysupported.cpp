#include "simplysupported.h"

SimplySupportedBendingManipulator::SimplySupportedBendingManipulator(Beam *beam, Load *load)
    : BendingManipulator(beam, load)

{
}

double SimplySupportedBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), E = beam->GetMaterial()->GetYoungModulus(), I = beam->GetCrossSection()->getInertiaAreaMoment();
    return (load->getLoadValue() * x * (l * l * l - (2*x*x*l) + x * x * x))/(24 * I * E);
}

double SimplySupportedBendingManipulator::getUniformMoment(double x)
{

    return (0.5) * load->getLoadValue() * (beam->GetLength() - x) * x;
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

double SimplySupportedBendingManipulator::getSingleMoment(double x)
{
    double a = load->getLoadPosition(), p = load->getLoadValue();

    if (x < a)
        return p * x * (1 - (a/beam->GetLength()));
    else
        return p * a * (1 - (x/beam->GetLength()));
}

double SimplySupportedBendingManipulator::getMaxMoment()
{

    if(load->isUniformLoad())
        return abs(getMoment(0.5 * beam->GetLength()));
    else
        return abs(getMoment(load->getLoadPosition()));
}



