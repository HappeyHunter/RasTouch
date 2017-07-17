#include "targetoptions.h"
#include "ui_targetoptions.h"

#include "staticitems.h"

#include <QFile>
#include <QTextStream>

TargetOptions::TargetOptions(QWidget *parent) :
    SecondaryOptionWidget(parent),
    ui(new Ui::TargetOptions)
{
    ui->setupUi(this);

    alignButtons();

    loadTargets();
}

TargetOptions::~TargetOptions()
{
    delete ui;
}

void TargetOptions::alignButtons() {
    ui->gridLayout->setAlignment(ui->allButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->targetAButton, Qt::AlignTop);
    ui->gridLayout->setAlignment(ui->targetBButton, Qt::AlignTop);
}

void TargetOptions::on_allButton_clicked()
{
    emit targetSelected("All");
}

void TargetOptions::on_targetAButton_clicked()
{
    emit targetSelected(ui->targetAButton->text());
}

void TargetOptions::on_targetBButton_clicked()
{
    emit targetSelected(ui->targetBButton->text());
}

void TargetOptions::on_cancelButton_clicked()
{
    emit optionSelected(StaticItems::ButtonOption::Cancel);
}

void TargetOptions::loadTargets() {
    QVector<QString> names = readNamesFromFile();

    if(names.size() > 0) {
        ui->targetAButton->setText(names.at(0));

        if(names.size() > 1) {
            ui->targetBButton->setText(names.at(1));
        } else {
            ui->targetBButton->setVisible(false);
        }
    } else {
        ui->targetAButton->setVisible(false);
        ui->targetBButton->setVisible(false);
    }

}

QVector<QString> TargetOptions::readNamesFromFile() {
    QVector<QString> names;
    QFile identityFile(StaticItems::NAMES_FILE);

    if(identityFile.exists() && identityFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream input(&identityFile);
        QString identityLine;

        while(!input.atEnd()) {
            identityLine = input.readLine();

            if(identityLine.length() > 0) {
                identityLine.truncate(30); // That's big enough as it is
                names.push_back(identityLine);
            }
        }

        identityFile.close();
    }

    return names;
}
