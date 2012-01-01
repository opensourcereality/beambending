#include "cantilever.h"
#include "qmath.h"

CantileverBendingManipulator::CantileverBendingManipulator(Beam *beam) :
    BendingManipulator(beam)
{
}

double CantileverBendingManipulator::getDeflection(double x)
{
    switch(loadOption){
    case uniform: return getUniformDeflection(x);
    case single: return getSingleDeflection(x);
    }

}

double CantileverBendingManipulator::getUniformDeflection(double x)
{
    double l = beam->GetLength(), I = beam->GetMaterial().GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();
    return -(loadValue * x * x * (6 * l - (4*x*l) + x * x))/(24 * I * E);
}

double CantileverBendingManipulator::getSingleDeflection(double x)
{
    double I = beam->GetMaterial().GetYoungModulus(), E = beam->GetCrossSection()->getInertiaAreaMoment();

    double constant = (-loadValue)/(6 * E * I);

    if( x < loadPosition )
        return constant *(x*x)*(3*loadPosition - x);
    else
        return constant *(loadPosition * loadPosition)*(3*x - loadPosition);

}

void CantileverBendingManipulator::setLoadOption(LoadOption loadOption) {

    if((loadOption != single) || (loadOption != uniform))
        return;

    this->loadOption = loadOption;
}

LoadOption CantileverBendingManipulator::getLoadOption() const {
    return loadOption;
}

void CantileverBendingManipulator::setLoadValue(double loadValue) {
    this->loadValue = loadValue;
}

double CantileverBendingManipulator::getLoadValue() const {
    return loadValue;
}

void CantileverBendingManipulator::setLoadPosition(double loadPosition) {
    this->loadPosition = loadPosition;
}

double CantileverBendingManipulator::getLoadPosition() const {
    return loadPosition;
}


