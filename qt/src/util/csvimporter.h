// $Id: tcximporter.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef CSVIMPORTER_H
#define CSVIMPORTER_H

#include <QObject>

class Run;
class QFileInfo;

const       double  CSV_MIN_SPLIT_DISTANCE = 30.0;

class CsvImporter : public QObject
{
public:

    CsvImporter();

    void run();
    void loadDeviceData( Run *run, QFileInfo &fi);
};

#endif // CSVIMPORTER_H
