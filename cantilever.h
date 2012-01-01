#ifndef CANTILEVER_H
#define CANTILEVER_H

#include "bendingmanipulator.h"

enum LoadOption {uniform, single};

class CantileverBendingManipulator : public BendingManipulator
{
public:
    CantileverBendingManipulator(Beam *beam);
    double getDeflection(double x);

    //load options interfaces
    void applyUniformLoad(double loadValue);
    bool applySingleLoad(double loadValue, double loadPosition);

private:
    double loadValue;
    double loadPosition;
    LoadOption loadOption;

    //utilities
    bool isProperLoadPosition(double position);
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);

    //private setters and getters
    void setLoadOption(LoadOption loadOption);
    LoadOption getLoadOption() const;

    void setLoadValue(double loadValue);
    double getLoadValue() const;

    bool setLoadPosition(double loadPosition);
    double getLoadPosition() const;

};

#endif // CANTILEVER_H
