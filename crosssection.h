#ifndef CROSSSECTION_H
#define CROSSSECTION_H

#include <QWidget>
#include "crosssections/crosssectionform.h"

class CrossSection
{


public:    
    virtual double getInertiaAreaMoment() = 0;
    virtual void constructForm(QWidget* parent = 0) = 0;
    QString getName() { return name; }
    CrossSectionForm *getForm(){ return form; }

protected:
    CrossSectionForm *form;
    QString name;
};

#endif // CROSSSECTION_H
