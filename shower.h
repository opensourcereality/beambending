#ifndef SHOWER_H
#define SHOWER_H

#include <QWidget>
#include "bendingmanipulator.h"

class shower : public QWidget
{
    Q_OBJECT
public:
    explicit shower(bendingmanipulator *bender ,QWidget *parent = 0);
    
signals:
    
public slots:

protected:
    void paintEvent(bendingmanipulator *bender, QPaintEvent *event);
    
};

#endif // SHOWER_H
