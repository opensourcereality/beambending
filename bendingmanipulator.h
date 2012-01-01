#ifndef BENDINGMANIPULATOR_H
#define BENDINGMANIPULATOR_H

class BendingManipulator
{
public:
    BendingManipulator(Beam *beam);
    double getDeflection(double x)= 0;
    double getSlope(double x) = 0;
    double getMoment(double x) = 0;
    double getShearForce(double x) = 0;
    double getStress(double x) = 0;

private:
    Beam *beam;

};

#endif // BENDINGMANIPULATOR_H
