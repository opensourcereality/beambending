#include "circleform.h"
#include "ui_circleform.h"

CircleForm::CircleForm(Circle *circle, double beamLength, QWidget *parent) :
    CrossSectionForm(beamLength, parent),
    ui(new Ui::CircleForm)
{
    ui->setupUi(this);
    this->circle = circle;
    ui->doubleSpinBox->setValue(this->circle->getRadius());
    ui->doubleSpinBox->setRange(getMinConstraint(), getMaxConstraint());
}

CircleForm::~CircleForm()
{
    delete ui;
}

void CircleForm::on_doubleSpinBox_valueChanged(double arg1)
{
    if (arg1)
    this->circle->setRadius(arg1);
    emit crossSectionUpdated();
}

void CircleForm::setFormConstraints()
{
    ui->doubleSpinBox->setRange(getMinConstraint(), getMaxConstraint());
}
