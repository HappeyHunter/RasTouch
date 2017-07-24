#include "primaryoptionwidget.h"
#include "ui_primaryoptionwidget.h"

#include <QPropertyAnimation>
#include <QMouseEvent>

#include "staticitems.h"


PrimaryOptionWidget::PrimaryOptionWidget(QWidget *parent) :
    OptionWidget(parent),
    ui(new Ui::PrimaryOptionWidget)
{
    ui->setupUi(this);

    alignButtons();
}

PrimaryOptionWidget::~PrimaryOptionWidget()
{
    delete ui;
}

void PrimaryOptionWidget::alignButtons() {
    ui->gridLayout->setAlignment(ui->washingButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->dinnerButton, Qt::AlignTop);
}

void PrimaryOptionWidget::on_washingButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::Washing);
}

void PrimaryOptionWidget::on_dinnerButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::Dinner);
}

void PrimaryOptionWidget::showEvent(QShowEvent *event) {
    QRect offsetPosition = geometry();

    offsetPosition.moveRight(0);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(625);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setStartValue(offsetPosition);
    animation->setEndValue(geometry());

    animation->start();

    //OptionWidget::showEvent(event);
}

void PrimaryOptionWidget::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::RightButton) {
        emit optionSelected(StaticItems::ButtonOption::Close);
    }
}
