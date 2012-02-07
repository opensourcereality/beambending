#include "rectangleform.h"
#include "ui_rectangleform.h"

RectangleForm::RectangleForm(Rectangle *rectangle, double beamLength, QWidget *parent) :
    CrossSectionForm(beamLength, parent),
    ui(new Ui::RectangleForm)
{
    ui->setupUi(this);
    this->rectangle = rectangle;

    ui->width->setValue(rectangle->getWidth());
    ui->height->setValue(rectangle->getHeight());

    setFormConstraints();
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

void RectangleForm::on_height_valueChanged(double arg2)
{
    this->rectangle->setHeight(arg2);
    emit crossSectionUpdated();
}

void RectangleForm::on_width_valueChanged(const QString arg1)
{
    this->rectangle->setWidth(arg1.toDouble());
    emit crossSectionUpdated();
}

void RectangleForm::on_height_valueChanged(const QString arg1)
{
    this->rectangle->setHeight(arg1.toDouble());
    emit crossSectionUpdated();
}

void RectangleForm::setFormConstraints()
{
    ui->height->setRange(getMinConstraint(), getMaxConstraint());
    ui->width->setRange(getMinConstraint(), getMaxConstraint());
}
