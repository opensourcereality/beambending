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
    ui->internalHeight->setRange(getMinConstraint(), getMaxConstraint());
    ui->internalWidth->setRange(getMinConstraint(), getMaxConstraint());
}

void IBeamForm::on_width_valueChanged(double arg1)
{
    this->ibeam->SetWidth(arg1);
    //setFormConstraints();
    emit crossSectionUpdated();
}

void IBeamForm::on_height_valueChanged(double arg1)
{
    this->ibeam->SetHeight(arg1);
    //setFormConstraints();
    emit crossSectionUpdated();
}

void IBeamForm::on_internalWidth_valueChanged(double arg1)
{
    this->ibeam->SetInternalWidth(arg1);
    emit crossSectionUpdated();
}

void IBeamForm::on_internalHeight_valueChanged(double arg1)
{
    this->ibeam->SetInternalHeight(arg1);
    emit crossSectionUpdated();
}
