#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bendingmanipulator.h"
#include "beam.h"
#include "standardmaterials.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Beam *beam;
    BendingManipulator *bendingManipulator;
    StandardMaterials standardMaterials;
    ~MainWindow();


private slots:
    void on_loadValue_valueChanged(double arg1);
    void on_length_valueChanged(double arg1);
    void on_material_currentIndexChanged(int index);
    void on_uniformLoad_clicked(bool checked);
    void on_singleLoad_clicked(bool checked);



private:
    Ui::MainWindow *ui;




};

#endif // MAINWINDOW_H
