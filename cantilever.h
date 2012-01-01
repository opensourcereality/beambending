#ifndef CANTILEVER_H
#define CANTILEVER_H

#include "bendingmanipulator.h"

class CantileverBendingManipulator : public BendingManipulator
{
public:
    CantileverBendingManipulator(Beam *beam);
};

#endif // CANTILEVER_H
