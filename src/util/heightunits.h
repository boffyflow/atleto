// $Id: heightunits.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2010, Parallel Pixels Ltd.

#ifndef HEIGHTUNITS_H
#define HEIGHTUNITS_H

#include <QObject>
#include <QSettings>

#include "lengthunits.h"

class HeightUnits : public LengthUnits
{
   Q_OBJECT;

public:

   HeightUnits();
   ~HeightUnits();
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class HeightString
{
public:

    HeightString();
    ~HeightString();

    // always base values
    void setValue( const double value);
    double value() const { return mValue;};

    // always current values
    void setText( const QString& string);
    QString text( int digits = 1, bool append = true) const;
    QString pace( const double secs, bool append = true) const;
    QString speed( const double secs, bool append = true) const;

private:

    double mValue;
};


#endif // HEIGHTUNITS_H
