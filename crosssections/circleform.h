#ifndef CIRCLEFORM_H
#define CIRCLEFORM_H

#include <QWidget>

namespace Ui {
    class CircleForm;
}

class CircleForm : public QWidget
{
    Q_OBJECT

public:
    explicit CircleForm(QWidget *parent = 0);
    ~CircleForm();

private:
    Ui::CircleForm *ui;
};

#endif // CIRCLEFORM_H
