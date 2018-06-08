// $Id: tcximporter.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2006, Parallel Pixels Ltd.

#ifndef TCXIMPORTER_H
#define TCXIMPORTER_H

#include <QObject>

class Run;
class QFileInfo;

const       double  TCX_MIN_SPLIT_DISTANCE = 30.0;

class TcxImporter : public QObject
{
public:

    TcxImporter();

    void run();
    void loadDeviceData( Run *run, QFileInfo &fi);
};

#endif // TCXIMPORTER_H
