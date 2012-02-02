#include "circleform.h"
#include "ui_circleform.h"

CircleForm::CircleForm(Circle *circle, QWidget *parent) :
    CrossSectionForm(parent),
    ui(new Ui::CircleForm)
{
    ui->setupUi(this);
    this->circle = circle;
}

CircleForm::~CircleForm()
{
    delete ui;
}

void CircleForm::on_doubleSpinBox_valueChanged(double arg1)
{
    this->circle->setRadius(arg1);
    emit crossSectionUpdated();
}
