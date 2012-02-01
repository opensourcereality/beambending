#include "bendingmanipulator.h"
#include <iostream>
using namespace std;

BendingManipulator::BendingManipulator(Beam *beam, Load *load)
{
    this->beam = beam;
<<<<<<< HEAD
    this->load = load;
    cout << "from constructer, beam Length =" << beam->GetLength() << endl;
=======
>>>>>>> origin/master
}


double BendingManipulator::getDeflection(double x)
{
<<<<<<< HEAD
    //cout << "got here :)\n";
    switch(load->getLoadOption()){
    case uniform: cout << "Uniform! \n"; return getUniformDeflection(x);  break;
    case single: cout << "Signle load! \n";return getSingleDeflection(x); break;
=======
    switch(getLoadOption()){
    case uniform: return getUniformDeflection(x);break;
    case single: return getSingleDeflection(x);break;
>>>>>>> origin/master
    }
    return 0;
}

