#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QVariant>

#include "beam.h"
#include "crosssections/rectangle.h"
#include "cantilever.h"

#include "crosssectionblock.h"

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
    myBender->applyUniformLoad(20);

    double result = myBender->getDeflection(9);

    QVariant var(result);

    QPushButton button(var.toString());
    button.show();

//    CrossSectionController *controller = new CrossSectionController(rectSection);
//    controller->show();


    return a.exec();
}
