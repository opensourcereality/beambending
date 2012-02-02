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
    explicit CrossSectionForm(QWidget *parent = 0);
    ~CrossSectionForm();
signals:
    void crossSectionUpdated();

private:
    Ui::CrossSectionForm *ui;
};

#endif // CROSSSECTIONFORM_H
