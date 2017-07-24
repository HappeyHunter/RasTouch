#-------------------------------------------------
#
# Project created by QtCreator 2017-01-26T23:06:59
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RasPiQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/primaryoptionwidget.cpp \
    src/optionwidget.cpp \
    src/staticitems.cpp \
    src/dinneroptionwidget.cpp \
    src/washingoptionwidget.cpp \
    src/targetoptions.cpp \
    src/networkmanager.cpp \
    src/secondaryoptionwidget.cpp

HEADERS  += src/mainwindow.h \
    src/primaryoptionwidget.h \
    src/optionwidget.h \
    src/staticitems.h \
    src/dinneroptionwidget.h \
    src/washingoptionwidget.h \
    src/targetoptions.h \
    src/networkmanager.h \
    src/secondaryoptionwidget.h

FORMS    += src/mainwindow.ui \
    src/primaryoptionwidget.ui \
    src/optionwidget.ui \
    src/dinneroptionwidget.ui \
    src/washingoptionwidget.ui \
    src/targetoptions.ui \
    src/secondaryoptionwidget.ui
