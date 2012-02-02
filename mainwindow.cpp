#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include "crosssections/rectangle.h"

//including physics classes
#include "beam.h"
#include "bendingmanipulator.h"
#include "cantilever.h"
#include "material.h"

#include "shower.h"

#include "crosssections/rectangle.h"

MainWindow::MainWindow(QWidget *parent) :
    initialized(false),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0; i< standardMaterials.count(); i++ )
        ui->material->addItem(standardMaterials.get(i)->GetName());

    for (int i=0; i< standardCrossSections.count(); i++ ) {
        CrossSection *cs = standardCrossSections.get(i);
        cs->constructForm();
        ui->crossSection->addItem(cs->getName());
        QObject::connect(cs->getForm(), SIGNAL(crossSectionUpdated()), this, SLOT(update()));
    }
    crossSectionWidget = standardCrossSections.get(0)->getForm();


    //constructing initial beam and bending manipulator
    //creating a beam, by constructing a material and a cross-section first...

    beam = new Beam(10, standardCrossSections.get(0), standardMaterials.get(0));
    load = new Load(beam, 1.5, 5);

    ui->length->setValue(10);

    bendingManipulator = new CantileverBendingManipulator(beam, load);

    ui->loadValue->setValue(1.5);


    bendingWidget = new shower(this, bendingManipulator);
    ui->beamBending->addWidget(bendingWidget);
    ui->crossSectionLayout->addWidget(crossSectionWidget, Qt::AlignTop);

    QObject::connect(this, SIGNAL(modelUpdated()), this, SLOT(updateBendingWidget()));

    //validations
    ui->loadPositionBox->setRange(0, beam->GetLength());

    initialized = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadValue_valueChanged(double arg1)
{
    if(ui->uniformLoad->isChecked())
        load->applyUniformLoad(arg1);
    else
        load->applySingleLoad(arg1, ui->loadPosition->value() * 0.01 * beam->GetLength());

    emit modelUpdated();
}

void MainWindow::on_length_valueChanged(double arg1)
{
    beam->SetLength(arg1);
    ui->loadPositionBox->setRange(0, beam->GetLength());
    emit modelUpdated();
}

void MainWindow::on_material_currentIndexChanged(int index)
{
    if(initialized)
        beam->SetMaterial(standardMaterials.get(index));
    emit modelUpdated();
}

void MainWindow::on_uniformLoad_clicked(bool checked)
{
    if(checked) {
        load->applyUniformLoad(ui->loadValue->value());
        ui->loadPosition->setDisabled(true);
        emit modelUpdated();
    }
}

void MainWindow::on_singleLoad_clicked(bool checked)
{
    if(checked){
        load->applySingleLoad(ui->loadValue->value(), ui->loadPosition->value() * 0.01 * beam->GetLength());
        ui->loadPosition->setDisabled(false);
        emit modelUpdated();
    }
}

void MainWindow::on_crossSection_currentIndexChanged(int index)
{
    if(initialized)
        setCrossSection(index);

}

void MainWindow::updateBendingWidget()
{
    bendingWidget->update();
}

void MainWindow::setCrossSection(int index)
{

    ui->crossSectionLayout->removeWidget(crossSectionWidget);
    crossSectionWidget->close();

    beam->SetCrossSection(standardCrossSections.get(index));
    crossSectionWidget = standardCrossSections.get(index)->getForm();

    crossSectionWidget->show();
    ui->crossSectionLayout->addWidget(crossSectionWidget, Qt::AlignTop);

    //crossSectionWidget->setHidden(true);
    //this->update();
    emit modelUpdated();
}

void MainWindow::on_loadPosition_sliderMoved(int position)
{
    load->setLoadPosition(position * 0.01 * beam->GetLength());
    ui->loadPositionBox->setValue(position * 0.01 * beam->GetLength());

    emit modelUpdated();
}

void MainWindow::on_loadPositionBox_valueChanged(double arg1)
{
    load->setLoadPosition(arg1);
    ui->loadPosition->setValue(arg1 / beam->GetLength() * 100);

    emit modelUpdated();


}
