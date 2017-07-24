#ifndef DINNEROPTIONWIDGET_H
#define DINNEROPTIONWIDGET_H

#include "secondaryoptionwidget.h"

namespace Ui {
class DinnerOptionWidget;
}

class DinnerOptionWidget : public SecondaryOptionWidget
{
    Q_OBJECT

public:
    explicit DinnerOptionWidget(QWidget *parent = 0);
    ~DinnerOptionWidget();

private slots:
    void on_pickDinnerButton_clicked();

    void on_cookDinnerButton_clicked();

    void on_dinnerReadyButton_clicked();

    void on_cancelButton_clicked();

private:
    void alignButtons();

private:
    Ui::DinnerOptionWidget *ui;
};

#endif // DINNEROPTIONWIDGET_H
