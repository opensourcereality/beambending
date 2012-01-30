#ifndef BEAMCONTROLLER_H
#define BEAMCONTROLLER_H

#include <QWidget>

namespace Ui {
    class BeamController;
}

class BeamController : public QWidget
{
    Q_OBJECT

public:
    explicit BeamController(QWidget *parent = 0);
    ~BeamController();

private:
    Ui::BeamController *ui;
};

#endif // BEAMCONTROLLER_H
