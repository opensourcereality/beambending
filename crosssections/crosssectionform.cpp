#include "crosssectionform.h"
#include "ui_crosssectionform.h"

CrossSectionForm::CrossSectionForm(double beamLength, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrossSectionForm)
{
    ui->setupUi(this);
    this->beamLength = beamLength;
}

CrossSectionForm::~CrossSectionForm()
{
    delete ui;
}

void CrossSectionForm::onBeamLengthChanged(double beamLength)
{
    this->setBeamLength(beamLength);
    this->setFormConstraints();
}
