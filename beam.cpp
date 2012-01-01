#include "beam.h"

Beam::Beam()
{    

}

double Beam::getDeflection(){
    switch (load.type) {
        case uniform: getUniformDeflection();
        break;
        case single: getSingleDeflection();
        break;
    }
}
