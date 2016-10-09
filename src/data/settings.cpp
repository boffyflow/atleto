// $Id: settings.cpp 371 2010-12-14 23:25:23Z boffyflow $
// (c) 2010 Parallel Pixels Ltd.

#include "settings.h"

#include <QtSql>

QString Settings::value( const QString &setting)
{
    QSqlQuery   q( "select current from settings where name=\"" + setting + "\"");

    if( q.next())
        return q.value( 0).toString();

    return "";
}

void Settings::setValue( const QString &setting, const QString &value)
{
    QSqlQuery   q;

    q.prepare( "update settings set current=\"" + value + "\" where name=\"" + setting + "\"");
    q.exec();
}
