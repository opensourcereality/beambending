#ifndef CROSSSECTION_H
#define CROSSSECTION_H

#include <QWidget>


class CrossSection
{
public:
    CrossSection();
    virtual double getInertiaAreaMoment() = 0;
    virtual void constructForm(QWidget* parent = 0) = 0;
    QString getName() { return name; }
    QWidget *getForm(){ return form; }

protected:
    QWidget *form;
    QString name;
};

#endif // CROSSSECTION_H
