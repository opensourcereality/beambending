#include "standardmaterials.h"

StandardMaterials::StandardMaterials()
{
    n = 2;
    //supported Materials
    material = new Material *[n];
    material[0] = new Material("Aluminum", 1.9);
    material[1] = new Material("Cadium", 2);
}
