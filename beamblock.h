#ifndef BEAMBLOCK_H
#define BEAMBLOCK_H

#include <QWidget>

#include "crosssectionblock.h"
#include "beam.h"
#include "beamcontroller.h"


class BeamBlock : public QWidget
{
    Q_OBJECT
public:
    explicit BeamBlock(Beam *beam, QWidget *parent = 0);

signals:

public slots:

private:
    CrossSectionBlock *crossSectionBlock;
    BeamController *controller;
};


#endif // BEAMBLOCK_H
