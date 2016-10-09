# -------------------------------------------------
# Project created by QtCreator 2009-04-20T16:18:33
# -------------------------------------------------
# (c) 2009 Parallel Pixels Ltd.
# $Id: atleto.pro 370 2010-12-14 23:23:50Z boffyflow $

# Path for QWT installation

QT +=   sql \
        svg \
        xml

TARGET = atleto
TEMPLATE = app
SOURCES += src/main.cpp

include(src/data/data.pri)
include(src/gui/gui.pri)
include(src/util/util.pri)
include(src/plot/plot.pri)

RESOURCES += src/resources/icons.qrc
TRANSLATIONS = src/resources/i18n/atleto_de.ts
