#include "rectangleform.h"
#include "ui_rectangleform.h"

RectangleForm::RectangleForm(Rectangle *rectangle, QWidget *parent) :
    CrossSectionForm(parent),
    ui(new Ui::RectangleForm)
{
    ui->setupUi(this);
    this->rectangle = rectangle;
}

RectangleForm::~RectangleForm()
{
    delete ui;
}

void RectangleForm::on_width_valueChanged(double arg1)
{
    this->rectangle->setWidth(arg1);
    emit crossSectionUpdated();
}

void RectangleForm::on_height_valueChanged(double arg1)
{
    this->rectangle->setHeight(arg1);
    emit crossSectionUpdated();
}
