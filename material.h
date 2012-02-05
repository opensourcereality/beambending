#ifndef MATERIAL_H
#define MATERIAL_H
#include <QString>

class Material
{
public:
    Material(QString name, double youngModulus, double yeildStrees, double fractureStress);
    void SetYoungModulus(double youngModulus);
    double GetYoungModulus() const;
    void SetName(QString name);
    QString GetName() const;
    void SetFractureStress(double fractureStress);
    double GetFractureStress() const;
    void SetYeildStrees(double yeildStrees);
    double GetYeildStrees() const;

private:
    QString name;
    double youngModulus;
    double yeildStrees;
    double fractureStress;

};


#endif // MATERIAL_H
