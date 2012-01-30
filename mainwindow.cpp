#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "crosssections/rectangle.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    double youngModulus[] = {
        1.9, //aluminum
        2,  //cadium
    };

    beam->GetMaterial().SetYoungModulus(youngModulus[index]);

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
