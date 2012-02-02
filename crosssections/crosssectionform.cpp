#include "crosssectionform.h"
#include "ui_crosssectionform.h"

CrossSectionForm::CrossSectionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrossSectionForm)
{
    ui->setupUi(this);
}

CrossSectionForm::~CrossSectionForm()
{
    delete ui;
}
