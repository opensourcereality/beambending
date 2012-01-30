#include "beamcontroller.h"
#include "ui_beamcontroller.h"

BeamController::BeamController(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeamController)
{
    ui->setupUi(this);
}

BeamController::~BeamController()
{
    delete ui;
}
