#include "beam.h"

Beam::Beam(double length, CrossSection *crossSection, Material *material){
    SetLength(length);
    SetCrossSection(crossSection);
    SetMaterial(material);
}

void Beam::SetMaterial(Material* material) {
    this->material = material;
}

Material* Beam::GetMaterial() const {
    return material;
}

void Beam::SetCrossSection(CrossSection* crossSection) {
    this->crossSection = crossSection;
}

CrossSection* Beam::GetCrossSection() const {
    return crossSection;
}

void Beam::SetLength(double length) {
    this->length = length;
}

double Beam::GetLength() const {
    return length;
}
