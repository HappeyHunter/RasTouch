#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMap>

#include "networkmanager.h"
#include "staticitems.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    enum TouchWindow {
        PrimaryWindow,
        WashingWindow,
        DinnerWindow,
        TargetWindow
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void initialise();
    void addOptionWidgets();
    void changeView(TouchWindow window);
    void addCloseFunction();

private slots:
    void handleOption(StaticItems::ButtonOption option);
    void sendNotification(QString selectedTarget);

private:
    Ui::MainWindow *ui;
    QScopedPointer<QStackedWidget> stackedWidget;
    QMap<TouchWindow, qint8> viewIndices;
    StaticItems::ButtonOption lastOption;
    QScopedPointer<NetworkManager> networkManager;
};

#endif // MAINWINDOW_H
