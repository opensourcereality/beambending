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
    shower.cpp \
    standardmaterials.cpp \
    crosssections/rectangleform.cpp \
    standardcrosssections.cpp \
    load.cpp


HEADERS  += mainwindow.h \
    beam.h \
    material.h \
    crosssection.h \
    crosssections/rectangle.h \
    bendingmanipulator.h \
    cantilever.h \
    shower.h \
    standardmaterials.h \
    crosssections/rectangleform.h \
    standardcrosssections.h \
    load.h

FORMS    += mainwindow.ui \
    crosssections/rectangleform.ui



















