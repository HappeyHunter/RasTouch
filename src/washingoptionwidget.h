#ifndef WASHINGOPTIONWIDGET_H
#define WASHINGOPTIONWIDGET_H

#include "secondaryoptionwidget.h"

namespace Ui {
class WashingOptionWidget;
}

class WashingOptionWidget : public SecondaryOptionWidget
{
    Q_OBJECT

public:
    explicit WashingOptionWidget(QWidget *parent = 0);
    ~WashingOptionWidget();

private slots:
    void on_puttingOnWashButton_clicked();

    void on_hangUpWashButton_clicked();

    void on_cancelButton_clicked();

private:
    void alignButtons();

private:
    Ui::WashingOptionWidget *ui;
};

#endif // WASHINGOPTIONWIDGET_H
