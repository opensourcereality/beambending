#include "load.h"

Load::Load()
{
}

void Load::SetLoadType(LoadType loadType) {
    this->loadType = loadType;
}

LoadType Load::GetLoadType() const {
    return loadType;
}

void Load::SetMagnitude(double magnitude) {
    this->magnitude = magnitude;
}

double Load::GetMagnitude() const {
    return magnitude;
}
