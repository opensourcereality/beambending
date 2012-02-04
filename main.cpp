#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QVariant>
#include <iostream>

#include "beam.h"
#include "load.h"

#include "crosssections/rectangle.h"

#include "cantilever.h"
#include "shower.h"


#include "mainwindow.h"


using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating a beam, by constructing a material and a cross-section first...
    CrossSection *rectSection = new Rectangle(1,1);
    Material *aluminum = new Material("Aluminum", 1.9);

    Beam *myBeam = new Beam(10, rectSection, aluminum);
    Load *myLoad = new Load(myBeam, 1.5);

    BendingManipulator *myBender = new CantileverBendingManipulator(myBeam, myLoad);   

    MainWindow myWindow;
    myWindow.show();


    return a.exec();
}
