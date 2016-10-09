// (c) 2009 Parallel Pixels Ltd.
// $Id: main.cpp 366 2010-06-04 21:16:57Z boffyflow $

#include <QtWidgets/QApplication>
#include "src/gui/mainwindow.h"
#include <QTranslator>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName( "ParallelPixels");
    QCoreApplication::setOrganizationDomain( "parallelpixels.com");
    QCoreApplication::setApplicationName( "Atleto");

    // install Translations
    QSettings settings;
    settings.beginGroup( "Options");
    QString lng = settings.value( "language").toString();
    settings.endGroup();

    QTranslator translator;

    if (lng.compare("de_DE") == 0) {
        translator.load("src/resources/i18n/atleto_de");
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
