#ifndef BENDINGMANIPULATOR_H
#define BENDINGMANIPULATOR_H

#include "beam.h"

enum LoadOption {uniform, single};


class BendingManipulator
{
public:
    BendingManipulator(Beam *beam);

    //standard load options interfaces
    void applyUniformLoad(double loadValue);
    bool applySingleLoad(double loadValue, double loadPosition = 0.5);

    double getDeflection(double x);
    //virtual double getSlope(double x) = 0;
    //virtual double getMoment(double x) = 0;
    //virtual double getShearForce(double x) = 0;
    //virtual double getStress(double x) = 0;
    Beam *beam;



private:
    double loadValue;
    double loadPosition;
    LoadOption loadOption;

    virtual double getUniformDeflection(double x) = 0;
    virtual double getSingleDeflection(double x) = 0;


protected:
    //setters and getters
    void setLoadOption(LoadOption loadOption);
    LoadOption getLoadOption() const;

    void setLoadValue(double loadValue);
    double getLoadValue() const;

    bool setLoadPosition(double loadPosition);
    double getLoadPosition() const;

    bool isProperLoadPosition(double position);



};

#endif // BENDINGMANIPULATOR_H
