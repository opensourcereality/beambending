#include "cantilever.h"
#include "qmath.h"
#include <iostream>
using namespace std;

CantileverBendingManipulator::CantileverBendingManipulator(Beam *beam, Load *load) :
    BendingManipulator(beam, load)
{
}

double CantileverBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), E = beam->GetMaterial()->GetYoungModulus(), I = beam->GetCrossSection()->getInertiaAreaMoment();

    cout << "max def = " << - (load->getLoadValue()* l*l*l*l)/(8*E*I) << "P: " << load->getLoadValue() << "l: " << beam->GetLength() << "E: " << beam->GetMaterial()->GetYoungModulus() << "I: " << beam->GetCrossSection()->getInertiaAreaMoment() << endl ;
    return (load->getLoadValue() * x  *x * (6 * l * l - (4*x*l) + x * x))/(24.0 * I * E);
}

double CantileverBendingManipulator::getUniformMoment(double x)
{
    return 0.5 * load->getLoadValue() * (beam->GetLength() - x) * (beam->GetLength() - x);
}

double CantileverBendingManipulator::getSingleDeflection(double x)
{
    double I = beam->GetMaterial()->GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();

    double constant = (load->getLoadValue())/(6 * E * I);

    double loadPosition = load->getLoadPosition();

    if( x < loadPosition )
        return constant *(x*x)*(3*loadPosition - x);
    else
        return constant *(loadPosition * loadPosition)*(3*x - loadPosition);

}

double CantileverBendingManipulator::getSingleMoment(double x)
{
    double a = load->getLoadPosition();

    if(x < a)
        return load->getLoadValue() * a * (1 - (x/a));
    else
        return 0;
}

double CantileverBendingManipulator::getMaxMoment()
{
    return abs(getMoment(0));
}
