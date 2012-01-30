#ifndef STANDARDMATERIALS_H
#define STANDARDMATERIALS_H

#include "material.h"

class StandardMaterials
{
public:
    StandardMaterials();


    Material **material;
    int n;

public:

    Material *get(int i){ return material[i];}
    int count() { return n; }

};

#endif // STANDARDMATERIALS_H
