#include "bendingmanipulator.h"
#include "cmath"
using namespace std;

BendingManipulator::BendingManipulator(Beam *beam, Load *load)
{
    this->beam = beam;
    this->load = load;

}


double BendingManipulator::getDeflection(double x)
{

    if (load->isUniformLoad())
        return getUniformDeflection(x); 
    else
        return getSingleDeflection(x);

}

double BendingManipulator::getMoment(double x)
{
    if (load->isUniformLoad())
        return getUniformMoment(x);
    else
        return getSingleMoment(x);
}


double BendingManipulator::getMaxStress()
{
    double c = beam->GetCrossSection()->getDiatanceFromNeutralAxis();
    double I = beam->GetCrossSection()->getInertiaAreaMoment();

    return (getMaxMoment() * c )/ I;
}

