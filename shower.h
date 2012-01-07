#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"
#include "beam.h"
class beam;
class BendingManipulator;

class shower : public QWidget
{
    Q_OBJECT
public:
    explicit shower(QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(QPaintEvent *event);
    
};

#endif // SHOWER_H
