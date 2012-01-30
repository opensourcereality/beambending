#include "mainwindow.h"
#include "ui_mainwindow.h"

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
