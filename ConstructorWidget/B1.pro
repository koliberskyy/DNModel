#-------------------------------------------------
#
# Project created by QtCreator 2019-02-16T17:44:50
#
#-------------------------------------------------

QT       += core gui
QT      +=opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = B1
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    BackEnd/Figure/Sphere/sphere.cpp \
    BackEnd/Figure/Cylinder/cylinder.cpp \
    BackEnd/Figure/Plast/plast.cpp \
    BackEnd/Figure/figure.cpp \
    BackEnd/DataBase/database.cpp \
    BackEnd/backend.cpp \
    FrontEnd/CreatorBlock/creatorblock.cpp \
    FrontEnd/CreatorBlock/CreatorWgt/creatorwgt.cpp \
    FrontEnd/SliderBlock/sliderblock.cpp

HEADERS  += mainwidget.h \
    BackEnd/Figure/Sphere/sphere.h \
    BackEnd/Figure/Cylinder/cylinder.h \
    BackEnd/Figure/Plast/plast.h \
    BackEnd/Figure/figure.h \
    BackEnd/DataBase/database.h \
    BackEnd/backend.h \
    FrontEnd/CreatorBlock/creatorblock.h \
    FrontEnd/CreatorBlock/CreatorWgt/creatorwgt.h \
    FrontEnd/SliderBlock/sliderblock.h

