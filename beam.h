#ifndef BEAM_H
#define BEAM_H

#include "material.h"
#include "crosssection.h"

class Beam

{
public:
    Beam(double length, CrossSection *crossSection, Material material);

    void SetMaterial(Material material) {
        this->material = material;
    }

    Material GetMaterial() const {
        return material;
    }

    void SetCrossSection(CrossSection* crossSection) {
        this->crossSection = crossSection;
    }

    CrossSection* GetCrossSection() const {
        return crossSection;
    }

    void SetLength(double length) {
        this->length = length;
    }

    double GetLength() const {
        return length;
    }

private:
    double length;
    CrossSection *crossSection;
    Material material;

};

#endif // BEAM_H
