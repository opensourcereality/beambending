#include "standardmaterials.h"

StandardMaterials::StandardMaterials()
{
    n = 2;
    //supported Materials
    material = new Material *[n];
    material[0] = new Material("Aluminum", 10, 95, 110);
    material[1] = new Material("Copper", 17, 70, 220);
}
