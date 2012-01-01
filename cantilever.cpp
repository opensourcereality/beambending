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

bool CantileverBendingManipulator::setLoadPosition(double loadPosition) {
    if(isProperLoadPosition(loadPosition)) {
        this->loadPosition = loadPosition;
        return true;
    }
    else
        return false;

}

double CantileverBendingManipulator::getLoadPosition() const {
    return loadPosition;
}

void CantileverBendingManipulator::applyUniformLoad(double loadValue)
{
    setLoadOption(uniform);
    setLoadValue(loadValue);
}

bool CantileverBendingManipulator::applySingleLoad(double loadValue, double loadPosition)
{
    if(isProperLoadPosition(loadPosition)){
        setLoadOption(single);
        setLoadValue(loadValue);
        setLoadPosition(loadPosition);
        return true;
    }
    else
        return false;

}

bool CantileverBendingManipulator::isProperLoadPosition(double position)
{
    if( (position < 0) || (position> beam->GetLength()) )
        return false;
    else
        return true;
}


