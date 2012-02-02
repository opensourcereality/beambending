#ifndef RECTANGLEFORM_H
#define RECTANGLEFORM_H

#include <QWidget>

#include "rectangle.h"
#include "crosssectionform.h"

namespace Ui {
    class RectangleForm;
}

class RectangleForm : public CrossSectionForm
{
    Q_OBJECT

public:
    explicit RectangleForm(Rectangle *rectangle, QWidget *parent = 0);
    ~RectangleForm();

private slots:
    void on_width_valueChanged(double arg1);
    void on_height_valueChanged(double arg1);

private:
    Ui::RectangleForm *ui;
    Rectangle *rectangle;
};

#endif // RECTANGLEFORM_H
