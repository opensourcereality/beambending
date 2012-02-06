#ifndef STANDARDBENDINGMANIPULATORS_H
#define STANDARDBENDINGMANIPULATORS_H

#include "bendingmanipulator.h"

class StandardBendingManipulators
{
public:
    StandardBendingManipulators(Beam *beam, Load *load);

    BendingManipulator **bendingManipulator;
    int n;

public:

    BendingManipulator *get(int i){ return bendingManipulator[i];}
    int count() { return n; }
};

#endif // STANDARDBENDINGMANIPULATORS_H
