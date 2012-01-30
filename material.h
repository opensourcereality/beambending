#ifndef MATERIAL_H
#define MATERIAL_H
#include <QString>

class Material
{
public:
    Material(QString name, double youngModulus);
    void SetYoungModulus(double youngModulus);
    double GetYoungModulus() const;
    void SetName(QString name);
    QString GetName() const;

private:
    QString name;
    double youngModulus;

};


#endif // MATERIAL_H
