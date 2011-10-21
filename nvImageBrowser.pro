###################################
# Project file for nvImageBrowser #
# Created 2011-10-20              #
###################################

QT  += core gui

TARGET = nvImageBrowser
TEMPLATE = app

DESTDIR = build/
OBJECTS_DIR = objects/
MOC_DIR = objects/
RCC_DIR = objects/
UI_DIR = objects/

SOURCES += \
    sources/main.cpp \
    sources/appcontroler.cpp \
    sources/appsettings.cpp

RESOURCES += \
    resources.qrc

HEADERS += \
    sources/appcontroler.h \
    sources/appsettings.h






