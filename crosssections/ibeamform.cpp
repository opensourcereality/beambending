#include "ibeamform.h"
#include "ui_ibeamform.h"

IBeamForm::IBeamForm(IBeam *ibeam, double beamLength, QWidget *parent) :
    CrossSectionForm(beamLength, parent),
    ui(new Ui::IBeamForm)
{
    ui->setupUi(this);
    this->ibeam = ibeam;

    ui->width->setValue(ibeam->GetWidth());
    ui->height->setValue(ibeam->GetHeight());
    ui->internalHeight->setValue(ibeam->GetInternalHeight());
    ui->internalWidth->setValue(ibeam->GetInternalWidth());

    setFormConstraints();

}

IBeamForm::~IBeamForm()
{
    delete ui;
}

void IBeamForm::setFormConstraints()
{
    ui->width->setRange(getMinConstraint(), getMaxConstraint());
    ui->height->setRange(getMinConstraint(), getMaxConstraint());
    ui->internalHeight->setRange(getMinConstraint(), ui->height->value()-0.5);
    ui->internalWidth->setRange(getMinConstraint(), ui->width->value()-0.5);
}

void IBeamForm::on_width_valueChanged(double arg1)
{
    ui->width->setValue(arg1);
    setFormConstraints();
    emit crossSectionUpdated();
}

void IBeamForm::on_height_valueChanged(double arg1)
{
    ui->height->setValue(arg1);
    setFormConstraints();
    emit crossSectionUpdated();
}

void IBeamForm::on_internalWidth_valueChanged(double arg1)
{
    ui->internalWidth->setValue(arg1);
    emit crossSectionUpdated();
}

void IBeamForm::on_internalHeight_valueChanged(double arg1)
{
    ui->internalHeight->setValue(arg1);
    emit crossSectionUpdated();
}
