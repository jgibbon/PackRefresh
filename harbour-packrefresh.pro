TARGET = harbour-packrefresh

DEPLOYMENT_PATH = /usr/share/$${TARGET}

#translations.files = translations
#translations.path = $${DEPLOYMENT_PATH}

CONFIG += sailfishapp

TEMPLATE = subdirs
SUBDIRS = src/packrefresh-helper src

SOURCES += src/harbour-packrefresh.cpp

OTHER_FILES += rpm/harbour-packrefresh.spec \
    #qml/cover/CoverPage.qml \
    #qml/harbour-packrefresh.qml \
    #qml/pages/FirstPage.qml \
    #qml/pages/SecondPage.qml \
    #rpm/harbour-packrefresh.changes.run.in \
    #translations/*.ts \
    harbour-packrefresh.desktop

#INSTALLS += translations

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/harbour-packrefresh-de.ts

# only include these files for translation:
#lupdate_only {
#    SOURCES = qml/*.qml \
#              qml/pages/*.qml
#}

script.files = helper/*
script.path = /usr/share/harbour-packrefresh/helper

icon86.files += icons/86x86/harbour-packrefresh.png
icon86.path = /usr/share/icons/hicolor/86x86/apps

icon108.files += icons/108x108/harbour-packrefresh.png
icon108.path = /usr/share/icons/hicolor/108x108/apps

icon128.files += icons/128x128/harbour-packrefresh.png
icon128.path = /usr/share/icons/hicolor/128x128/apps

icon256.files += icons/256x256/harbour-packrefresh.png
icon256.path = /usr/share/icons/hicolor/256x256/apps


INSTALLS += icon86 icon108 icon128 icon256 script

DISTFILES += \
    rpm/harbour-packrefresh.changes
