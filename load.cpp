#include "load.h"


Load::Load(Beam *beam)
{
    this->beam = beam;
}

Load::Load(Beam *beam, double loadValue)
{
    this->beam = beam;
    applyUniformLoad(loadValue);
}


Load::Load(Beam *beam, double loadValue, double loadPosition)
{
    this->beam = beam;
    applySingleLoad(loadValue, loadPosition);
}

bool Load::applySingleLoad(double loadValue, double loadPosition)
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

void Load::applyUniformLoad(double loadValue)
{
    setLoadOption(uniform);
    setLoadValue(loadValue);
}

void Load::setLoadOption(LoadOption loadOption) {

    if((loadOption != single) || (loadOption != uniform))
        return;

    this->loadOption = loadOption;
}

LoadOption Load::getLoadOption() const {
    return loadOption;
}

void Load::setLoadValue(double loadValue) {
    this->loadValue = loadValue;
}

double Load::getLoadValue() const {
    return loadValue;
}

bool Load::setLoadPosition(double loadPosition) {
    if(isProperLoadPosition(loadPosition)) {
        this->loadPosition = loadPosition;
        return true;
    }
    else
        return false;

}

double Load::getLoadPosition() const {
    return loadPosition;
}


bool Load::isProperLoadPosition(double position)
{
    if( (position < 0) || (position> beam->GetLength()) )
        return false;
    else
        return true;
}
