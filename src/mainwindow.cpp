#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "primaryoptionwidget.h"
#include "washingoptionwidget.h"
#include "dinneroptionwidget.h"
#include "targetoptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialise();
}

void MainWindow::initialise() {
    // Make it borderless
    setWindowFlags(Qt::FramelessWindowHint);

    stackedWidget.reset(new QStackedWidget());

    setCentralWidget(stackedWidget.data());

    addOptionWidgets();

    networkManager.reset(new NetworkManager(true));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addOptionWidgets() {
    qint8 index = 0;

    // Add Primary
    PrimaryOptionWidget* primary = new PrimaryOptionWidget();

    connect(primary, SIGNAL(optionSelected(StaticItems::ButtonOption)), this, SLOT(handleOption(StaticItems::ButtonOption)));

    index = stackedWidget.data()->addWidget(primary);

    viewIndices.insert(TouchWindow::PrimaryWindow, index);

    // Add Washing
    WashingOptionWidget* washing = new WashingOptionWidget();

    connect(washing, SIGNAL(optionSelected(StaticItems::ButtonOption)), this, SLOT(handleOption(StaticItems::ButtonOption)));

    index = stackedWidget.data()->addWidget(washing);

    viewIndices.insert(TouchWindow::WashingWindow, index);

    // Add Dinner
    DinnerOptionWidget* dinner = new DinnerOptionWidget();

    connect(dinner, SIGNAL(optionSelected(StaticItems::ButtonOption)), this, SLOT(handleOption(StaticItems::ButtonOption)));

    index = stackedWidget.data()->addWidget(dinner);

    viewIndices.insert(TouchWindow::DinnerWindow, index);

    // Add Target
    TargetOptions* target = new TargetOptions();

    connect(target, SIGNAL(targetSelected(QString)), this, SLOT(sendNotification(QString)));
    connect(target, SIGNAL(optionSelected(StaticItems::ButtonOption)), this, SLOT(handleOption(StaticItems::ButtonOption)));

    index = stackedWidget.data()->addWidget(target);

    viewIndices.insert(TouchWindow::TargetWindow, index);

}

void MainWindow::handleOption(StaticItems::ButtonOption option) {
    switch(option) {
    case StaticItems::ButtonOption::Close :
        this->close();
        break;
    case StaticItems::ButtonOption::Washing :
        changeView(TouchWindow::WashingWindow);
        break;
    case StaticItems::ButtonOption::Dinner :
        changeView(TouchWindow::DinnerWindow);
        break;
    case StaticItems::ButtonOption::PuttingOnWash :
    case StaticItems::ButtonOption::HangUpWashing :
    case StaticItems::ButtonOption::PickDinner :
    case StaticItems::ButtonOption::CookDinner :
    case StaticItems::ButtonOption::DinnerReady :
        changeView(TouchWindow::TargetWindow);
        break;
    default:
        changeView(TouchWindow::PrimaryWindow);
    }

    lastOption = option;
}

void MainWindow::changeView(TouchWindow window) {
    QMap<TouchWindow, qint8>::const_iterator nextWindow = viewIndices.find(window);
    qint8 index = 0;

    if (nextWindow != viewIndices.end()) {
        index = nextWindow.value();
    }

    stackedWidget.data()->setCurrentIndex(index);
}

void MainWindow::sendNotification(QString selectedTarget) {
    // use the last option thing and the target to send it
    QString message = StaticItems::getMessage(lastOption);

    networkManager->sendNotification(selectedTarget, message);

    // reset to the primary window
    changeView(TouchWindow::PrimaryWindow);
}
