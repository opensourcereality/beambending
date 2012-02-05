#include "material.h"

Material::Material(QString name, double youngModulus, double yeildStrees, double fractureStress)
{
    this->name = name;
    this->youngModulus = youngModulus;
}

void Material::SetYoungModulus(double youngModulus) {
    this->youngModulus = youngModulus;
}

double Material::GetYoungModulus() const {
    return youngModulus;
}

QString Material::GetName() const
{
    return name;
}

void Material::SetFractureStress(double fractureStress) {
    this->fractureStress = fractureStress;
}

double Material::GetFractureStress() const {
    return fractureStress;
}

void Material::SetYeildStrees(double yeildStrees) {
    this->yeildStrees = yeildStrees;
}

double Material::GetYeildStrees() const {
    return yeildStrees;
}

void Material::SetName(QString name)
{
    this->name = name;
}

