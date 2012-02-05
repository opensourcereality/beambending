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
    CrossSectionForm *crossSectionWidget;


    ~MainWindow();


private slots:
    void on_loadValue_valueChanged(double arg1);
    void on_length_valueChanged(double arg1);
    void on_material_currentIndexChanged(int index);
    void on_uniformLoad_clicked(bool checked);
    void on_singleLoad_clicked(bool checked);
    void on_crossSection_currentIndexChanged(int index);
    void updateBendingWidget();
    void on_loadPosition_sliderMoved(int position);
    void on_loadPositionBox_valueChanged(double arg1);
    void onCrossSectionUpdated();

signals:
    void modelUpdated();
    void beamLengthChanged(double beamLength);



private:
    Ui::MainWindow *ui;

    //controllers
    void setCrossSection(int index = 0);
    void setMaterial(int index = 0);
    void setBeamLength(double length);
    void setLoadValue(double loadValue);
    void setLoadPosition(double position);
    void setLoadOptionUniform();
    void setLoadOptionSingle();

};

#endif // MAINWINDOW_H
