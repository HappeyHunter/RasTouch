#ifndef OPTIONWIDGET_H
#define OPTIONWIDGET_H

#include <QWidget>

#include "staticitems.h"

namespace Ui {
class OptionWidget;
}

class OptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionWidget(QWidget *parent = 0);
    ~OptionWidget();

public:


signals:
    void optionSelected(StaticItems::ButtonOption option);

private:
    Ui::OptionWidget *ui;
};

#endif // OPTIONWIDGET_H
