#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T16:43:29
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
CONFIG   += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DNModel
TEMPLATE = app

LIBS += -lglu32 -lopengl32

SOURCES += main.cpp\
        mainwindow.cpp \
    ConstructorWidget/BackEnd/DataBase/database.cpp \
    ConstructorWidget/BackEnd/Figure/Cylinder/cylinder.cpp \
    ConstructorWidget/BackEnd/Figure/Plast/plast.cpp \
    ConstructorWidget/BackEnd/Figure/Sphere/sphere.cpp \
    ConstructorWidget/BackEnd/Figure/figure.cpp \
    ConstructorWidget/BackEnd/backend.cpp \
    ConstructorWidget/FrontEnd/CreatorBlock/CreatorWgt/creatorwgt.cpp \
    ConstructorWidget/FrontEnd/CreatorBlock/creatorblock.cpp \
    ConstructorWidget/FrontEnd/SliderBlock/sliderblock.cpp \
    ConstructorWidget/mainwidget.cpp \
    libsgp4/CoordGeodetic.cc \
    libsgp4/CoordTopocentric.cc \
    libsgp4/DateTime.cc \
    libsgp4/DecayedException.cc \
    libsgp4/Eci.cc \
    libsgp4/Globals.cc \
    libsgp4/Observer.cc \
    libsgp4/OrbitalElements.cc \
    libsgp4/SatelliteException.cc \
    libsgp4/SGP4.cc \
    libsgp4/SolarPosition.cc \
    libsgp4/TimeSpan.cc \
    libsgp4/Tle.cc \
    libsgp4/TleException.cc \
    libsgp4/Util.cc \
    libsgp4/Vector.cc \
    Timer/timer.cpp \
    MapControlUnit/mapcontrolunit.cpp \
    MapWidget2/mapwidget.cpp \
    graphsscene.cpp

HEADERS  += mainwindow.h \
    ConstructorWidget/BackEnd/DataBase/database.h \
    ConstructorWidget/BackEnd/Figure/Cylinder/cylinder.h \
    ConstructorWidget/BackEnd/Figure/Plast/plast.h \
    ConstructorWidget/BackEnd/Figure/Sphere/sphere.h \
    ConstructorWidget/BackEnd/Figure/figure.h \
    ConstructorWidget/BackEnd/backend.h \
    ConstructorWidget/FrontEnd/CreatorBlock/CreatorWgt/creatorwgt.h \
    ConstructorWidget/FrontEnd/CreatorBlock/creatorblock.h \
    ConstructorWidget/FrontEnd/SliderBlock/sliderblock.h \
    ConstructorWidget/mainwidget.h \
    libsgp4/CoordGeodetic.h \
    libsgp4/CoordTopocentric.h \
    libsgp4/DateTime.h \
    libsgp4/DecayedException.h \
    libsgp4/Eci.h \
    libsgp4/Globals.h \
    libsgp4/Observer.h \
    libsgp4/OrbitalElements.h \
    libsgp4/SatelliteException.h \
    libsgp4/SGP4.h \
    libsgp4/SolarPosition.h \
    libsgp4/TimeSpan.h \
    libsgp4/Tle.h \
    libsgp4/TleException.h \
    libsgp4/Util.h \
    libsgp4/Vector.h \
    Timer/timer.h \
    MapControlUnit/mapcontrolunit.h \
    MapWidget2/mapwidget.h \
    MapWidget2/rls.h \
    graphsscene.h
QMAKE_LIBS_OPENGL =  -lglut -lGLU
