#include "standardmaterials.h"

StandardMaterials::StandardMaterials()
{
    n = 2;
    //supported Materials
    material = new Material *[n];
    material[0] = new Material("Aluminum", 10, 95/(6894.8/10e6), 110/(6894.8/10e6));
    material[1] = new Material("Copper", 17, 70/(6894.8/10e6), 220/(6894.8/10e6));
}
