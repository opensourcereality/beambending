#ifndef CROSSSECTION_H
#define CROSSSECTION_H

class CrossSection
{
public:
    CrossSection();
    virtual double getInertiaAreaMoment() = 0;
};

#endif // CROSSSECTION_H
