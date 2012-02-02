#include <QtGui/QApplication>
#include <QtOpenGL/QGLShader>
#include <QtOpenGL/QGLShaderProgram>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLFormat>
#include <QDesktopWidget>
#include <QPushButton>
#include <QVariant>
#include <iostream>

#include "beam.h"
#include "load.h"

#include "crosssections/rectangle.h"

#include "cantilever.h"
#include "shower.h"
#include "binding3d.h"


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


//    for (double i = 0; i < 10 ; i += 0.01)
//    {
//        cout << "test " << myBender->getDeflection(i) << endl;
//    }

    double result = myBender->getDeflection(9);

    QVariant var(result);
    cout << "result is:" << result << endl;

    //shower beamShower(0, myBender);

    //beamShower.show();


    MainWindow myWindow;
    myWindow.show();

//    if (!QGLFormat::hasOpenGL()) {
//    std::cerr << "This system has no OpenGL support" << std::endl;
//    return 1;
//    }
//    binding3d my3dShower;
//    my3dShower.setWindowTitle(QObject::tr("Bending in 3D mode"));
//    my3dShower.resize(600, 600);
//    my3dShower.show();



    return a.exec();
}
