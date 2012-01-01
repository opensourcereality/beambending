#include <QtGui/QApplication>
#include "mainwindow.h"


#include "beam.h"
#include "crosssections/rectangle.h"
#include "cantilever.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //creating a beam, by constructing a material and a cross-section first...
    CrossSection *rectSection = new Rectangle(1,1);
    Material aluminum;
    aluminum.SetName("Aluminum");
    aluminum.SetYoungModulus(ALUMINUM);

    Beam *myBeam = new Beam(10, rectSection, aluminum);

    //CantileverBendingManipulator(myBeam);

    return a.exec();
}
