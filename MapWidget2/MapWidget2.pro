#-------------------------------------------------
#
# Project created by QtCreator 2019-07-23T13:21:11
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapWidget2
TEMPLATE = app


SOURCES += main.cpp\
        mapwidget.cpp \
    ../libsgp4/CoordGeodetic.cc \
    ../libsgp4/CoordTopocentric.cc \
    ../libsgp4/DateTime.cc \
    ../libsgp4/DecayedException.cc \
    ../libsgp4/Eci.cc \
    ../libsgp4/Globals.cc \
    ../libsgp4/Observer.cc \
    ../libsgp4/OrbitalElements.cc \
    ../libsgp4/SatelliteException.cc \
    ../libsgp4/SGP4.cc \
    ../libsgp4/SolarPosition.cc \
    ../libsgp4/TimeSpan.cc \
    ../libsgp4/Tle.cc \
    ../libsgp4/TleException.cc \
    ../libsgp4/Util.cc \
    ../libsgp4/Vector.cc

HEADERS  += mapwidget.h \
    ../libsgp4/CoordGeodetic.h \
    ../libsgp4/CoordTopocentric.h \
    ../libsgp4/DateTime.h \
    ../libsgp4/DecayedException.h \
    ../libsgp4/Eci.h \
    ../libsgp4/Globals.h \
    ../libsgp4/Observer.h \
    ../libsgp4/OrbitalElements.h \
    ../libsgp4/SatelliteException.h \
    ../libsgp4/SGP4.h \
    ../libsgp4/SolarPosition.h \
    ../libsgp4/TimeSpan.h \
    ../libsgp4/Tle.h \
    ../libsgp4/TleException.h \
    ../libsgp4/Util.h \
    ../libsgp4/Vector.h \
    rls.h
