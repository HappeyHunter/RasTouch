#ifndef PRIMARYOPTIONWIDGET_H
#define PRIMARYOPTIONWIDGET_H

#include "optionwidget.h"

namespace Ui {
class PrimaryOptionWidget;
}

class PrimaryOptionWidget : public OptionWidget
{
    Q_OBJECT

public:
    explicit PrimaryOptionWidget(QWidget *parent = 0);
    ~PrimaryOptionWidget();

private:
    void alignButtons();

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void on_washingButton_clicked();

    void on_dinnerButton_clicked();

private:
    Ui::PrimaryOptionWidget *ui;
};

#endif // PRIMARYOPTIONWIDGET_H
