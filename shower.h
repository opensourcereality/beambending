#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"
#include "beam.h"

class shower : public QWidget
{
    Q_OBJECT
public:
    explicit shower(bendingmanipulator *bender ,QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(beam *bentBeam,bendingmanipulator *bender, QPaintEvent *event);
    
};

#endif // SHOWER_H
