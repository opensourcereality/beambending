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

    if (load->isUniformLoad()){
        cout << "Uniform";
        return getUniformDeflection(x);
    }
    else {
        cout << "Single!";
        return getSingleDeflection(x);
    }

}

