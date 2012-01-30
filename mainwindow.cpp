#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

#include "crosssections/rectangle.h"

//including physics classes
#include "beam.h"
#include "bendingmanipulator.h"
#include "cantilever.h"
#include "material.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0; i< standardMaterials.count(); i++ )
        ui->material->addItem(standardMaterials.get(i)->GetName());

    //constructing initial beam and bending manipulator
    //creating a beam, by constructing a material and a cross-section first...
    CrossSection *rectSection = new Rectangle(1,1);

    beam = new Beam(100, rectSection, standardMaterials.get(0));

    bendingManipulator = new CantileverBendingManipulator(beam);

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
}

void MainWindow::on_length_valueChanged(double arg1)
{
    beam->SetLength(arg1);
}

void MainWindow::on_material_currentIndexChanged(int index)
{
    //SEGMENTATION FAULT TO BE FIXED!
    //beam->SetMaterial(m);

}

void MainWindow::on_width_valueChanged(double arg1)
{
    Rectangle *rectangle =  new Rectangle(arg1, ui->height->value());
    beam->SetCrossSection(rectangle);
}

void MainWindow::on_height_valueChanged(double arg1)
{
    Rectangle *rectangle =  new Rectangle(ui->width->value(), arg1);
    beam->SetCrossSection(rectangle);
}

void MainWindow::on_uniformLoad_clicked(bool checked)
{
    if(checked)
        bendingManipulator->applyUniformLoad(ui->loadValue->value());
}

void MainWindow::on_singleLoad_clicked(bool checked)
{
    if(checked)
        bendingManipulator->applySingleLoad(ui->loadValue->value());
}
