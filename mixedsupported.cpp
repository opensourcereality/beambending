#include "mixedsupported.h"

MixedSupportedBendingManipulator::MixedSupportedBendingManipulator(Beam *beam, Load *load)
    : BendingManipulator(beam, load)
{
}

double MixedSupportedBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), E = beam->GetMaterial()->GetYoungModulus(), I = beam->GetCrossSection()->getInertiaAreaMoment();
    return (load->getLoadValue() * (3*l - 2*x) * (l-x) * (x*x))/(48.0 * E * I);

}

double MixedSupportedBendingManipulator::getUniformMoment(double x)
{
    return (1/8.0) * load->getLoadValue() * (x - beam->GetLength()) * (4*x - beam->GetLength());
}

double MixedSupportedBendingManipulator::getSingleDeflection(double x)
{
    double I = beam->GetMaterial()->GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment(), l = beam->GetLength();

    double a = load->getLoadPosition(), p = load->getLoadValue();

    double constant = p/(12* E * I * l * l * l);

    if( x < a )
        return constant*(x*x)*(a-l)*((3*l-x)*(a*a) +(2*l*a*(x-3*l)) + (2*l*l*x));
    else
        return constant*(a*a)*(l-x)*( 3*l*x*(x-(2*l)) + a*(2*l*l + (2*x*l) - (x*x)) );
}

double MixedSupportedBendingManipulator::getSingleMoment(double x)
{
    double I = beam->GetMaterial()->GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment(), l = beam->GetLength();

    double a = load->getLoadPosition(), p = load->getLoadValue();

    double constant = p/(2*l*l*l);

    if ( x < a )
        return constant * (l-a) * ((l-x)*a*a - (2*l*a*(l-x) + (2*l*l*x)));
    else
        return constant * (a*a) * (3*l-a) * (l-x);

}

double MixedSupportedBendingManipulator::getMaxMoment()
{
    if(load->isUniformLoad())
        return abs(getMoment(0));
    else {
        double a = load->getLoadPosition(), l = beam->GetLength();
        if ( a < (0.5858*l) )
            return abs(getMoment(0));
        else
            return abs(getMoment(a));
    }
}

