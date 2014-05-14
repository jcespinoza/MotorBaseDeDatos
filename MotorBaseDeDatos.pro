#-------------------------------------------------
#
# Project created by QtCreator 2014-05-04T10:08:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotorBaseDeDatos
TEMPLATE = app


SOURCES += main.cpp\
        mwindow.cpp \
        defcampo.cpp\
    controlador.cpp \
    bloquemaestro.cpp \
    bloqueestandar.cpp

HEADERS  += mwindow.h \
    defcampo.h \
    deftabla.h \
    controlador.h \
    bloquemaestro.h \
    bloqueestandar.h

FORMS    += mwindow.ui
