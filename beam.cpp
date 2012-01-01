#include "beam.h"

Beam::Beam(double length, CrossSection *crossSection, Material material){
    SetLength(length);
    SetCrossSection(crossSection);
    SetMaterial(material);
}

