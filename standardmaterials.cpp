#include "standardmaterials.h"

#define PSI 6894.8

StandardMaterials::StandardMaterials()
{
    n = 6;
    //supported Materials -- stresses in N/m^2 or Pa
    material = new Material *[n];
    material[0] = new Material("Rubber", 0.01e9, 1e6, 7e6);
    material[1] = new Material("Nylon", 2e9, 45e6, 75e6);
    material[2] = new Material("Oak wood", 9e9, 40e6, 50e6);
    material[3] = new Material("Aluminum", 69e9, 20e6, 70e6);
    material[4] = new Material("Copper", 110e9, 55e6, 230e6);
    material[5] = new Material("Steel", 200e9, 280e6, 340e6);

}
