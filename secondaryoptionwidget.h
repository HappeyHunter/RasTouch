#ifndef SECONDARYOPTIONWIDGET_H
#define SECONDARYOPTIONWIDGET_H

#include "optionwidget.h"

namespace Ui {
class SecondaryOptionWidget;
}

class SecondaryOptionWidget : public OptionWidget
{
    Q_OBJECT

public:
    explicit SecondaryOptionWidget(QWidget *parent = 0);
    ~SecondaryOptionWidget();

protected:
    virtual void showEvent(QShowEvent *event);

private:
    Ui::SecondaryOptionWidget *ui;
};

#endif // SECONDARYOPTIONWIDGET_H
