#include "standardmaterials.h"

#define PSI 6894.8

StandardMaterials::StandardMaterials()
{
    n = 2;
    //supported Materials //stresses in N/m^2
    material = new Material *[n];
    material[0] = new Material("Aluminum", 69e9, 95e6, 110e6);
    material[1] = new Material("Copper", 17e6 * PSI, 70e6, 220e6);
}
