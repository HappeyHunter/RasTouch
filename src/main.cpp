#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showFullScreen();

#ifndef QT_DEBUG
    a.setOverrideCursor(Qt::BlankCursor);
#endif

    return a.exec();
}
