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

    for (int i=0; i< standardCrossSections.count(); i++ )
        ui->crossSection->addItem(standardCrossSections.get(i)->getName());


    //constructing initial beam and bending manipulator
    //creating a beam, by constructing a material and a cross-section first...
    CrossSection *rectSection = new Rectangle(1,1);
    beam = new Beam(10, rectSection, standardMaterials.get(0));
    bendingManipulator = new CantileverBendingManipulator(beam);
    bendingManipulator->applyUniformLoad(1.5);

    Rectangle *rect = new Rectangle(1,1);
    rectSection->constructForm(this);
    ui->crossSectionLayout->addWidget(rectSection->getForm());


    bendingWidget = new shower(this, bendingManipulator);
    ui->beamBending->addWidget(bendingWidget);

    QObject::connect(this, SIGNAL(modelUpdated()), this, SLOT(updateBendingWidget()));

    initialized = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadValue_valueChanged(double arg1)
{
    if(ui->uniformLoad->isChecked())
        bendingManipulator->applyUniformLoad(arg1);
    else
        bendingManipulator->applySingleLoad(arg1);

    emit modelUpdated();
}

void MainWindow::on_length_valueChanged(double arg1)
{
    beam->SetLength(arg1);
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
        bendingManipulator->applyUniformLoad(ui->loadValue->value());
        emit modelUpdated();
    }
}

void MainWindow::on_singleLoad_clicked(bool checked)
{
    if(checked){
        bendingManipulator->applySingleLoad(ui->loadValue->value());
        emit modelUpdated();
    }
}

void MainWindow::on_crossSection_currentIndexChanged(int index)
{
    if(initialized){
        beam->SetCrossSection(standardCrossSections.get(index));
        //emit modelUpdated();
    }
}

void MainWindow::updateBendingWidget()
{
    bendingWidget->update();
}
