// $Id: settings.h 371 2010-12-14 23:25:23Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

class Settings
{
public:
    static QString      value( const QString &setting);
    static void         setValue( const QString &setting, const QString &value);
};

#endif // SETTINGS_H
