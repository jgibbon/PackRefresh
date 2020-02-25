
PROJECT = harbour-packrefresh
TARGET = packrefreshhelper
QT += core
CONFIG += console
#CONFIG += sailfishapp

target.path = /usr/share/$$PROJECT/helper

SOURCES += \
    packrefresh-helper.cpp \
    task.cpp

INSTALLS += target

HEADERS += \
    task.h
