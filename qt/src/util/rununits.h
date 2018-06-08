// $Id: rununits.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd. 

#ifndef RUNUNITS_H
#define RUNUNITS_H

#include <QObject>
#include <QSettings>

#include "lengthunits.h"

static const QString RUN_SETTINGS_DISTANCE = "plugins.run.distance.units";

class RunUnits : public LengthUnits
{
   Q_OBJECT;

public:

   RunUnits();
   ~RunUnits();
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class RunDistanceString
{
public:

    RunDistanceString();
    RunDistanceString( const double value);
    ~RunDistanceString();

    // always base values
    void setValue( const double value);
    double value() const { return mValue;};

    // always current values
    double  curValue() const;
    double  paceValue( const double secs) const;
    void setText( const QString& string);
    QString text( int digits = 1, bool append = true) const;
    QString pace( const double secs, bool append = true) const;
    QString speed( const double secs, bool append = true) const;

private:

    double mValue;
};


#endif // RUNUNITS_H
