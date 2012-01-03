#include "crosssectionblock.h"


#include <QLayout>

CrossSectionBlock::CrossSectionBlock(CrossSection *crossSection, QWidget *parent) :
    QWidget(parent)
{
    this->crossSection = crossSection;
    view = new CrossSectionView(crossSection, this);
    controller = new CrossSectionController(crossSection, this);

    QVBoxLayout *layout = new QVBoxLayout(parent);
    layout->addWidget(view);
    layout->addWidget(controller);

}

CrossSectionController::CrossSectionController(CrossSection *crossSection, QWidget *parent) :
    QWidget(parent)
{
    this->crossSection = crossSection;

    label = new QLabel(this);
    label->setText("Amjad");
    spinBox = new QSpinBox(this);
    spinBox->setValue(90);
    QHBoxLayout *layout = new QHBoxLayout(this);

    layout->addWidget(label);
    layout->addWidget(spinBox);

    this->setLayout(layout);
}

CrossSectionView::CrossSectionView(CrossSection *crossSection, QWidget *parent) :
    QWidget(parent)
{
}
