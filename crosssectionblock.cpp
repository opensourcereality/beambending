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
    this->setLayout(layout);

}

CrossSectionController::CrossSectionController(CrossSection *crossSection, QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(30, 60);
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);

}

CrossSectionView::CrossSectionView(CrossSection *crossSection, QWidget *parent) :
    QWidget(parent)
{
    setPalette(QPalette(QColor(100, 100, 8)));
    setAutoFillBackground(true);
    setFixedSize(30,30);
}
