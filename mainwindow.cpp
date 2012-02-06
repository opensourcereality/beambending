#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include "crosssections/rectangle.h"

//including physics classes
#include "beam.h"

#include "bendingmanipulator.h"
#include "cantilever.h"
#include "simplysupported.h"
#include "mixedsupported.h"

#include "shower.h"


MainWindow::MainWindow(QWidget *parent) :
    initialized(false),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //constants
    const double beamLength = 1;

    //initializing the UI
    ui->setupUi(this);

    //initializing the standard materials and cross sections
    for (int i=0; i< standardMaterials.count(); i++ )
        ui->material->addItem(standardMaterials.get(i)->GetName());

    for (int i=0; i< standardCrossSections.count(); i++ ) {
        CrossSection *cs = standardCrossSections.get(i);
        cs->constructForm(beamLength);
        ui->crossSection->addItem(cs->getName());
        QObject::connect(cs->getForm(), SIGNAL(crossSectionUpdated()), this, SLOT(onCrossSectionUpdated()));
        QObject::connect(this, SIGNAL(beamLengthChanged(double)), cs->getForm(), SLOT(onBeamLengthChanged(double)));
    }
    crossSectionWidget = standardCrossSections.get(0)->getForm();


    //initializing the the models
        //constructing initial beam, load and bending manipulator

    beam = new Beam();
    load = new Load(beam);
    standardBendingManipulators = new StandardBendingManipulators(beam, load);

    //initializing the model and UI values

        //beam options
        setBeamLength(beamLength);
        setCrossSection();
        setMaterial();

        //loading options
        setLoadPosition(beam->GetLength());
        setLoadValue(10);
        setLoadOptionUniform();

        //bending manipulator
        setBendingManipulator();


    //initializaing and connecting widgets
    bendingWidget = new shower(this, bendingManipulator);
    ui->beamBending->addWidget(bendingWidget);
    ui->crossSectionLayout->addWidget(crossSectionWidget);
    QObject::connect(this, SIGNAL(modelUpdated()), this, SLOT(updateBendingWidget()));
    QObject::connect(this, SIGNAL(modelUpdated()), this, SLOT(updateStressValues()));
    updateStressValues();

    //variable used to disable invoking of some signals without the complete construction of the MainWindow
    initialized = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadValue_valueChanged(double arg1)
{
    setLoadValue(arg1 * 10);
}

void MainWindow::on_length_valueChanged(double arg1)
{
    setBeamLength(arg1);
}

void MainWindow::on_material_currentIndexChanged(int index)
{
    if(initialized)
        setMaterial(index);
}

void MainWindow::on_uniformLoad_clicked(bool checked)
{
    if(checked) {
        load->setLoadOptionUniform();
        ui->loadPositionBox->setDisabled(true);
        ui->loadPositionLabel->setDisabled(true);
        emit modelUpdated();
    }
}

void MainWindow::on_singleLoad_clicked(bool checked)
{
    if(checked){
        load->setLoadOptionSingle();
        ui->loadPositionBox->setDisabled(false);
        ui->loadPositionLabel->setDisabled(false);
        emit modelUpdated();
    }
}

void MainWindow::on_crossSection_currentIndexChanged(int index)
{
    if(initialized)
        setCrossSection(index);
}

void MainWindow::on_loadPosition_sliderMoved(int position)
{
    setLoadPosition(load->ratio2position(position * 0.01));
}

void MainWindow::on_loadPositionBox_valueChanged(double arg1)
{
    setLoadPosition(arg1);
}

void MainWindow::updateBendingWidget()
{
    bendingWidget->setBendingManipulator(bendingManipulator);
    bendingWidget->update();
}

void MainWindow::onCrossSectionUpdated()
{
    emit modelUpdated();
}

//controllers
void MainWindow::setBeamLength(double length)
{
    if (length != 0) {
        beam->SetLength(length);
        ui->length->setValue(length);
        ui->loadPositionBox->setRange(0, beam->GetLength());
        emit modelUpdated();
        emit beamLengthChanged(beam->GetLength());
    }
}

void MainWindow::setLoadPosition(double position)
{
    if (load->setLoadPosition(position)) {
        ui->loadPositionBox->setValue(load->getLoadPosition());
        emit modelUpdated();
    }
}

void MainWindow::setCrossSection(int index)
{

    //closing the previous cross section
    ui->crossSectionLayout->removeWidget(crossSectionWidget);
    crossSectionWidget->close();

    //loading the new cross section
    beam->SetCrossSection(standardCrossSections.get(index));
    crossSectionWidget = standardCrossSections.get(index)->getForm();
    crossSectionWidget->show();
    crossSectionWidget->setBeamLength(beam->GetLength());
    ui->crossSectionLayout->addWidget(crossSectionWidget, Qt::AlignTop);

    ui->crossSection->setCurrentIndex(index);

    emit modelUpdated();
}

void MainWindow::setLoadValue(double loadValue)
{
    load->setLoadValue(loadValue);
    ui->loadValue->setValue(loadValue/10);
    emit modelUpdated();
}

void MainWindow::setMaterial(int index)
{
    beam->SetMaterial(standardMaterials.get(index));
    ui->material->setCurrentIndex(index);
    emit modelUpdated();
}

void MainWindow::setLoadOptionUniform()
{
    load->setLoadOptionUniform();
    ui->uniformLoad->setChecked(true);
    ui->singleLoad->setChecked(false);
}

void MainWindow::setLoadOptionSingle()
{
    load->setLoadOptionSingle();
    ui->uniformLoad->setChecked(false);
    ui->singleLoad->setChecked(true);
}

void MainWindow::updateStressValues()
{
    double maxStress = bendingManipulator->getMaxStress();

    ui->currentStress->setText(QString::number(maxStress));
    ui->yieldStress->setText(QString::number(beam->GetMaterial()->GetYeildStrees()));
    ui->fractureStress->setText(QString::number(beam->GetMaterial()->GetFractureStress()));

    QPalette red; red.setColor(QPalette::WindowText, Qt::red);
    QPalette green; green.setColor(QPalette::WindowText, Qt::green);


    //giving an alert when exceeding failure stresses
    if (maxStress >= (beam->GetMaterial()->GetFractureStress()) ){
        ui->fractureStressLabel->setPalette(red);
    }
    if(maxStress > (beam->GetMaterial()->GetYeildStrees()) ){
        ui->yieldStressLabel->setPalette(red);
        ui->currentStressLabel->setPalette(red);
    }
    else {
        ui->currentStressLabel->setPalette(green);
        ui->yieldStressLabel->setPalette(green);
        ui->fractureStressLabel->setPalette(green);
    }
}

void MainWindow::setBendingManipulator(int index)
{
    bendingManipulator = standardBendingManipulators->get(index);

    switch (index) {
        case 0:
            ui->cantiliver->setChecked(true);
            bendingManipulator->type = 0;
            break;
        case 1:
            ui->simplySupported->setChecked(true);
            bendingManipulator->type = 1;
            break;
        case 2:
            ui->mixedSupported->setChecked(true);
            bendingManipulator->type = 2;
            break;
    }

    emit modelUpdated();
}



void MainWindow::on_cantiliver_clicked(bool checked)
{
    setBendingManipulator(0);
}

void MainWindow::on_simplySupported_clicked(bool checked)
{
    setBendingManipulator(1);
}

void MainWindow::on_mixedSupported_clicked(bool checked)
{
    setBendingManipulator(2);
}
