# $Id: plot.pri 369 2010-09-25 00:02:33Z boffyflow $
# Atleto plot module
SOURCES += src/plot/svgview.cpp \
    src/plot/ploteditor.cpp \
    src/plot/previewplot.cpp \
    src/plot/gnuplotcommand.cpp \
#    src/plot/plotdata.cpp \
    src/plot/grapheditor.cpp \
    src/plot/graphwidget.cpp \
#    src/plot/histogram_item.cpp \
    src/plot/plotpoint.cpp \
    src/plot/plotseries.cpp \
    src/plot/plot.cpp \
    src/plot/plotgraph.cpp
HEADERS += src/plot/svgview.h \
    src/plot/ploteditor.h \
    src/plot/previewplot.h \
    src/plot/gnuplotcommand.h \
#    src/plot/plotdata.h \
    src/plot/grapheditor.h \
    src/plot/graphwidget.h \
#    src/plot/histogram_item.h \
    src/plot/plotpoint.h \
    src/plot/plotseries.h \
    src/plot/plot.h \
    src/plot/plotgraph.h
FORMS += src/plot/ploteditor.ui \
    src/plot/previewplot.ui \
    src/plot/grapheditor.ui \
    src/plot/graphwidget.ui \
    src/plot/plot.ui
