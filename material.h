#ifndef MATERIAL_H
#define MATERIAL_H
#include <QString>


#define ALUMINUM 10.0
#define CADIUM 4.6

class Material
{
public:
    Material();    

private:
    QString name;
    double youngModulus;

};

#endif // MATERIAL_H
