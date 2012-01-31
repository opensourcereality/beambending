#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QVariant>
#include <iostream>

#include "beam.h"
#include "crosssections/rectangle.h"
#include "cantilever.h"
#include "shower.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating a beam, by constructing a material and a cross-section first...
    CrossSection *rectSection = new Rectangle(1,1);
    Material aluminum;
    aluminum.SetName("Aluminum");
    aluminum.SetYoungModulus(ALUMINUM);

    Beam *myBeam = new Beam(10, rectSection, aluminum);

    BendingManipulator *myBender = new CantileverBendingManipulator(myBeam);

    //let's apply a load and bend the beam!
    myBender->applyUniformLoad(0.2);
//    for (double i = 0; i < 10 ; i += 0.01)
//    {
//        cout << "test " << myBender->getDeflection(i) << endl;
//    }
    double result = myBender->getDeflection(9);

    QVariant var(result);
    cout << "result is:" << result << endl;
    QPushButton button(var.toString());
    button.show();

    shower beamShower(0, myBender);

    beamShower.show();

    return a.exec();
}
