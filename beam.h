#ifndef BEAM_H
#define BEAM_H

#include "material.h"
#include "crosssection.h"

class Beam

{
public:
    Beam(double length, CrossSection *crossSection, Material *material);
    void SetMaterial(Material *material);
    Material* GetMaterial() const ;
    void SetCrossSection(CrossSection* crossSection) ;
    CrossSection* GetCrossSection() const ;
    void SetLength(double length) ;
    double GetLength() const ;

private:
    double length;
    CrossSection *crossSection;
    Material *material;

};

#endif // BEAM_H
