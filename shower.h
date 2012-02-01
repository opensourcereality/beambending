#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"

class beam;
class BendingManipulator;

class shower : public QWidget
{
    Q_OBJECT
public:

    explicit shower(QWidget *parent = 0, BendingManipulator *bender = 0);

    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:
    BendingManipulator *myBender;
    double intialDrawX, intialDrawY, drawStep, drawResoulution, magnificationFactor, visualBeamLength;

    
};

#endif // SHOWER_H
