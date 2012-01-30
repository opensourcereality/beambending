#include "beamblock.h"


BeamBlock::BeamBlock(Beam *beam, QWidget *parent) :
    QWidget(parent)
{
    crossSectionBlock = new CrossSectionBlock(beam->GetCrossSection(), this);
    controller = new BeamController(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(crossSectionBlock);
    layout->addWidget(controller);
    //this->setLayout(layout);

}
