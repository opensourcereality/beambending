#include "bendingmanipulator.h"
#include <iostream>
using namespace std;

BendingManipulator::BendingManipulator(Beam *beam)
{
    this->beam = beam;
}

void BendingManipulator::applyUniformLoad(double loadValue)
{
    setLoadOption(uniform);
    setLoadValue(loadValue);
}

double BendingManipulator::getDeflection(double x)
{
    switch(getLoadOption()){
    case uniform: return getUniformDeflection(x);break;
    case single: return getSingleDeflection(x);break;
    }
    return 0;
}

bool BendingManipulator::applySingleLoad(double loadValue, double loadPosition)
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


void BendingManipulator::setLoadOption(LoadOption loadOption) {

    if((loadOption != single) || (loadOption != uniform))
        return;

    this->loadOption = loadOption;
}

LoadOption BendingManipulator::getLoadOption() const {
    return loadOption;
}

void BendingManipulator::setLoadValue(double loadValue) {
    this->loadValue = loadValue;
}

double BendingManipulator::getLoadValue() const {
    return loadValue;
}

bool BendingManipulator::setLoadPosition(double loadPosition) {
    if(isProperLoadPosition(loadPosition)) {
        this->loadPosition = loadPosition;
        return true;
    }
    else
        return false;

}

double BendingManipulator::getLoadPosition() const {
    return loadPosition;
}


bool BendingManipulator::isProperLoadPosition(double position)
{
    if( (position < 0) || (position> beam->GetLength()) )
        return false;
    else
        return true;
}
