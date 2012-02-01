#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bendingmanipulator.h"
#include "beam.h"
#include "load.h"
#include "standardmaterials.h"
#include "standardcrosssections.h"
#include "shower.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Beam *beam;
    Load *load;
    BendingManipulator *bendingManipulator;
    StandardMaterials standardMaterials;
    StandardCrossSections standardCrossSections;
    bool initialized;
    shower *bendingWidget;
    QWidget *crossSectionWidget;


    ~MainWindow();


private slots:
    void on_loadValue_valueChanged(double arg1);
    void on_length_valueChanged(double arg1);
    void on_material_currentIndexChanged(int index);
    void on_uniformLoad_clicked(bool checked);
    void on_singleLoad_clicked(bool checked);
    void on_crossSection_currentIndexChanged(int index);
    void updateBendingWidget();

signals:
    void modelUpdated();



private:
    Ui::MainWindow *ui;
    void setCrossSection(int index);




};

#endif // MAINWINDOW_H
