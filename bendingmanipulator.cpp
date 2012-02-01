#include "bendingmanipulator.h"
#include <iostream>
using namespace std;

BendingManipulator::BendingManipulator(Beam *beam, Load *load)
{
    this->beam = beam;
    this->load = load;
    cout << "from constructer, beam Length =" << beam->GetLength() << endl;
}


double BendingManipulator::getDeflection(double x)
{
    //cout << "got here :)\n";
    switch(load->getLoadOption()){
    case uniform: cout << "Uniform! \n"; return getUniformDeflection(x);  break;
    case single: cout << "Signle load! \n";return getSingleDeflection(x); break;
    }
    return 0;
}

