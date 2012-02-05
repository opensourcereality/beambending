#ifndef CIRCLEFORM_H
#define CIRCLEFORM_H

#include "crosssection.h"
#include "circle.h"

namespace Ui {
    class CircleForm;
}

class CircleForm : public CrossSectionForm
{
    Q_OBJECT

public:
    explicit CircleForm(Circle *circle, double beamLength, QWidget *parent = 0);
    void setFormConstraints();

    ~CircleForm();

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::CircleForm *ui;
    Circle *circle;

};

#endif // CIRCLEFORM_H
