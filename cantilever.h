#ifndef CANTILEVER_H
#define CANTILEVER_H

#include "bendingmanipulator.h"

enum LoadOption {uniform, single};

class CantileverBendingManipulator : public BendingManipulator
{
public:
    CantileverBendingManipulator(Beam *beam);
    double getDeflection(double x);

    //setters and getters
    void setLoadOption(LoadOption loadOption);
    LoadOption getLoadOption() const;
    void setLoadValue(double loadValue);
    double getLoadValue() const;
    void setLoadPosition(double loadPosition);
    double getLoadPosition() const;

private:
    double loadValue;
    double loadPosition;
    LoadOption loadOption;
    double getUniformDeflection(double x);
    double getSingleDeflection(double x);

};

#endif // CANTILEVER_H
