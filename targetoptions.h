#ifndef TARGETOPTIONS_H
#define TARGETOPTIONS_H

#include "secondaryoptionwidget.h"

#include <QVector>

namespace Ui {
class TargetOptions;
}

class TargetOptions : public SecondaryOptionWidget
{
    Q_OBJECT

public:
    explicit TargetOptions(QWidget *parent = 0);
    ~TargetOptions();

private:
    void alignButtons();
    void loadTargets();
    QVector<QString> readNamesFromFile();

signals:
    void targetSelected(QString selectedTarget);

private slots:
    void on_allButton_clicked();

    void on_targetAButton_clicked();

    void on_targetBButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::TargetOptions *ui;
};

#endif // TARGETOPTIONS_H
