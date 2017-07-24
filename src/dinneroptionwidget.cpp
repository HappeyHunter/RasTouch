#include "dinneroptionwidget.h"
#include "ui_dinneroptionwidget.h"

#include "staticitems.h"

DinnerOptionWidget::DinnerOptionWidget(QWidget *parent) :
    SecondaryOptionWidget(parent),
    ui(new Ui::DinnerOptionWidget)
{
    ui->setupUi(this);

    alignButtons();
}

void DinnerOptionWidget::alignButtons() {
    ui->gridLayout->setAlignment(ui->pickDinnerButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->cookDinnerButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->dinnerReadyButton, Qt::AlignTop);

    ui->gridLayout->setAlignment(ui->cancelButton, Qt::AlignBottom);
}

DinnerOptionWidget::~DinnerOptionWidget()
{
    delete ui;
}

void DinnerOptionWidget::on_pickDinnerButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::PickDinner);
}

void DinnerOptionWidget::on_cookDinnerButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::CookDinner);
}

void DinnerOptionWidget::on_dinnerReadyButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::DinnerReady);
}

void DinnerOptionWidget::on_cancelButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::Cancel);
}
