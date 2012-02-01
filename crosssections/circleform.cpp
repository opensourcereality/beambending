#include "circleform.h"
#include "ui_circleform.h"

CircleForm::CircleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CircleForm)
{
    ui->setupUi(this);
}

CircleForm::~CircleForm()
{
    delete ui;
}
