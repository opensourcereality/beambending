#ifndef LOAD_H
#define LOAD_H

#include "beam.h"

enum LoadOption {uniform, single};

class Load
{

private:
    Beam *beam;
    double loadValue;
    double loadPosition;
    LoadOption loadOption;

public:
    Load(Beam *beam);
    Load(Beam *beam, double loadValue);
    Load(Beam *beam, double loadValue, double loadPosition);
    //standard load options interfaces
    void applyUniformLoad(double loadValue);
    bool applySingleLoad(double loadValue, double loadPosition);

    //setters and getters
    void setLoadOption(LoadOption loadOption);
    LoadOption getLoadOption() const;

    void setLoadValue(double loadValue);
    double getLoadValue() const;

    bool setLoadPosition(double loadPosition);
    double getLoadPosition() const;

    bool isProperLoadPosition(double position);

};

#endif // LOAD_H
