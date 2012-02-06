#ifndef CROSSSECTIONFORM_H
#define CROSSSECTIONFORM_H

#include <QWidget>

namespace Ui {
    class CrossSectionForm;
}

class CrossSectionForm : public QWidget
{
    Q_OBJECT

public:
    explicit CrossSectionForm(double beamLength, QWidget *parent = 0);
    double getMaxConstraint() { return beamLength/4; }
    double getMinConstraint() { return 0.0000001; }
    void setBeamLength(double beamLength) {this->beamLength = beamLength;}
    virtual void setFormConstraints() = 0;
    ~CrossSectionForm();

signals:
    void crossSectionUpdated();

public slots:
    void onBeamLengthChanged(double beamLength);

protected:
    double beamLength;

private:
    Ui::CrossSectionForm *ui;
};

#endif // CROSSSECTIONFORM_H
