#include "washingoptionwidget.h"
#include "ui_washingoptionwidget.h"

#include "staticitems.h"

WashingOptionWidget::WashingOptionWidget(QWidget *parent) :
    SecondaryOptionWidget(parent),
    ui(new Ui::WashingOptionWidget)
{
    ui->setupUi(this);

    alignButtons();
}

WashingOptionWidget::~WashingOptionWidget()
{
    delete ui;
}

void WashingOptionWidget::alignButtons() {
    ui->gridLayout->setAlignment(ui->puttingOnWashButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->hangUpWashButton, Qt::AlignTop);

    ui->gridLayout->setAlignment(ui->cancelButton, Qt::AlignBottom);
}

void WashingOptionWidget::on_puttingOnWashButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::PuttingOnWash);
}

void WashingOptionWidget::on_hangUpWashButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::HangUpWashing);
}

void WashingOptionWidget::on_cancelButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::Cancel);
}
