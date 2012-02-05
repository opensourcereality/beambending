#ifndef IBEAMFORM_H
#define IBEAMFORM_H

#include "crosssectionform.h"
#include "ibeam.h"

namespace Ui {
    class IBeamForm;
}

class IBeamForm : public CrossSectionForm
{
    Q_OBJECT

public:
    explicit IBeamForm(IBeam *ibeam, double beamLength, QWidget *parent = 0);
    void setFormConstraints();

    ~IBeamForm();

private slots:
    void on_width_valueChanged(double arg1);
    void on_height_valueChanged(double arg1);
    void on_internalWidth_valueChanged(double arg1);
    void on_internalHeight_valueChanged(double arg1);

private:
    Ui::IBeamForm *ui;
    IBeam *ibeam;
};

#endif // IBEAMFORM_H
