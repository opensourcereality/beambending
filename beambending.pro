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
    load.cpp \
    crosssections/circle.cpp \
    crosssections/circleform.cpp \
    crosssections/crosssectionform.cpp \
    simplysupported.cpp \
    crosssections/ibeam.cpp \
    crosssections/ibeamform.cpp \
    mixedsupported.cpp \
    standardbendingmanipulators.cpp


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
    load.h \
    crosssections/circle.h \
    crosssections/circleform.h \
    crosssections/crosssectionform.h \
    simplysupported.h \
    crosssections/ibeam.h \
    crosssections/ibeamform.h \
    mixedsupported.h \
    standardbendingmanipulators.h

FORMS    += mainwindow.ui \
    crosssections/rectangleform.ui \
    crosssections/circleform.ui \
    crosssections/crosssectionform.ui \
    crosssections/ibeamform.ui

RESOURCES += \
    application.qrc
