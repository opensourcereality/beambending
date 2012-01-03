#ifndef CROSSSECTIONBLOCK_H
#define CROSSSECTIONBLOCK_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QLayout>

#include "crosssection.h"

//forward decleration
class CrossSectionController;
class CrossSectionView;

class CrossSectionBlock : public QWidget
{
    Q_OBJECT
public:
    explicit CrossSectionBlock(CrossSection *crossSection, QWidget *parent = 0);

signals:

public slots:

private:
    CrossSection *crossSection;
    CrossSectionController *controller;
    CrossSectionView *view;

};

class CrossSectionController : public QWidget
{
    Q_OBJECT
public:
    explicit CrossSectionController(CrossSection *crossSection, QWidget *parent = 0);

signals:

public slots:

private:
    CrossSection *crossSection;
    QLabel *label;
    QSpinBox *spinBox;

};


class CrossSectionView: public QWidget
{
    Q_OBJECT
public:
    explicit CrossSectionView(CrossSection *crossSection, QWidget *parent = 0);

signals:

public slots:

private:
    CrossSection *crossSection;

};


#endif // CROSSSECTIONBLOCK_H
