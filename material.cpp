#include "material.h"

Material::Material(QString name, double youngModulus)
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

void Material::SetName(QString name)
{
    this->name = name;
}

