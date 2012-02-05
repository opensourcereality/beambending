#include "bendingmanipulator.h"
#include <iostream>
using namespace std;

BendingManipulator::BendingManipulator(Beam *beam, Load *load)
{
    this->beam = beam;

    this->load = load;
    cout << "from constructer, beam Length =" << beam->GetLength() << endl;
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

double BendingManipulator::getMaxMoment()
{
    if(load->isSingleLoad())
        return getMoment(beam->GetLength());
    else
        return getMoment(beam->GetLength() * 0.5);
}

double BendingManipulator::getMaxStress()
{
    double c = beam->GetCrossSection()->getDiatanceFromNeutralAxis();
    double I = beam->GetCrossSection()->getInertiaAreaMoment();

    return (getMaxMoment() * c )/ I;
}

