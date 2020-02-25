TEMPLATE = app

TARGET = harbour-packrefresh
CONFIG += sailfishapp
PKGCONFIG += \
    nemonotifications-qt5


QT += core
QT += dbus

#QT += declarative

SOURCES += harbour-packrefresh.cpp #\
#    settings.cpp \
#    osread.cpp

#HEADERS += \
#    settings.h \
#    osread.h

CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

OTHER_FILES +=
