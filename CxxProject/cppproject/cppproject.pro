#-------------------------------------------------
#
# Project created by QtCreator 2018-04-11T18:53:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cppproject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    secwindow.cpp \
    person.cpp \
    ansatt.cpp \
    kunde.cpp \
    hotell.cpp \
    animal.cpp \
    cat.cpp \
    dog.cpp \
    checkinwindow.cpp \
    checkoutwindow.cpp \
    db.cpp \
    textbox.cpp \
    user.cpp \
    userexistswindow.cpp \
    searchcustomerwindow.cpp \
    animalprofilwindow.cpp \
    catordog.cpp \
    initdb.cpp

HEADERS += \
        mainwindow.h \
    secwindow.h \
    person.h \
    ansatt.h \
    kunde.h \
    hotell.h \
    animal.h \
    cat.h \
    dog.h \
    checkinwindow.h \
    checkoutwindow.h \
    db.h \
    textbox.h \
    user.h \
    userexistswindow.h \
    searchcustomerwindow.h \
    animalprofilwindow.h \
    catordog.h \
    initdb.h

FORMS += \
        mainwindow.ui \
    secwindow.ui \
    checkinwindow.ui \
    checkoutwindow.ui \
    textbox.ui \
    user.ui \
    userexistswindow.ui \
    searchcustomerwindow.ui \
    animalprofilwindow.ui \
    catordog.ui
