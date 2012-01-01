#include "material.h"

Material::Material()
{
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
