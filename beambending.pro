#-------------------------------------------------
#
# Project created by QtCreator 2011-12-27T18:40:48
#
#-------------------------------------------------

QT       += core gui

TARGET = beambending
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    beam.cpp \
    material.cpp \
    crosssection.cpp \
    crosssections/rectangle.cpp \
    bendingmanipulator.cpp \
    cantilever.cpp \
    crosssectionblock.cpp \
    beamblock.cpp \
    beamcontroller.cpp \
    shower.cpp


HEADERS  += mainwindow.h \
    beam.h \
    material.h \
    crosssection.h \
    crosssections/rectangle.h \
    bendingmanipulator.h \
    cantilever.h \
    crosssectionblock.h \
    beamblock.h \
    beamcontroller.h \
    shower.h

FORMS    += mainwindow.ui \
    beamcontroller.ui

