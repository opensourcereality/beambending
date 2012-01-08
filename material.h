#ifndef MATERIAL_H
#define MATERIAL_H
#include <QString>


#define ALUMINUM 1.9
#define CADIUM 2

class Material
{
public:
    Material();
    void SetYoungModulus(double youngModulus);
    double GetYoungModulus() const;
    void SetName(QString name);
    QString GetName() const;

private:
    QString name;
    double youngModulus;

};

#endif // MATERIAL_H
