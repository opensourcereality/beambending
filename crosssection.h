#ifndef CROSSSECTION_H
#define CROSSSECTION_H

#include <QWidget>

class CrossSection
{
public:
    CrossSection();
    virtual double getInertiaAreaMoment() = 0;
    virtual void constructForm(QWidget* parent = 0) = 0;
    QWidget *getForm(){ return form; }

protected:
    QWidget *form;
};

#endif // CROSSSECTION_H
