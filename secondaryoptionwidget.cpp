#include "secondaryoptionwidget.h"
#include "ui_secondaryoptionwidget.h"

#include <QPropertyAnimation>

SecondaryOptionWidget::SecondaryOptionWidget(QWidget *parent) :
    OptionWidget(parent),
    ui(new Ui::SecondaryOptionWidget)
{
    ui->setupUi(this);
}

SecondaryOptionWidget::~SecondaryOptionWidget()
{
    delete ui;
}

void SecondaryOptionWidget::showEvent(QShowEvent *event) {
    QRect offsetPosition = geometry();

    offsetPosition.moveLeft(geometry().width());

    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(625);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setStartValue(offsetPosition);
    animation->setEndValue(geometry());

    animation->start();

    //OptionWidget::showEvent(event);
}
