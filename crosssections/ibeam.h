#ifndef IBEAM_H
#define IBEAM_H

#include "crosssection.h"

class IBeam : public CrossSection
{
public:
    IBeam(double width, double height, double internalWidth, double internalHeight);

    double getInertiaAreaMoment();
    double getDiatanceFromNeutralAxis();
    void constructForm(double beamLength, QWidget* parent = 0);


    void SetWidth(double width);
    double GetWidth() const;
    void SetInternalWidth(double internalWidth);
    double GetInternalWidth() const;
    void SetInternalHeight(double internalHeight);
    double GetInternalHeight() const;
    void SetHeight(double height);
    double GetHeight() const;

private:
    double height;
    double internalHeight;
    double internalWidth;
    double width;

};

#endif // IBEAM_H
