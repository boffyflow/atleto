// $Id: unitstring.h 214 2009-05-28 17:44:45Z robert $
// (c) 2007, Parallel Pixels Ltd.

#ifndef UNITSTRING_H
#define UNITSTRING_H

#include <QObject>
#include <QString>

class UnitString : public QObject
{
	Q_OBJECT

public:

    UnitString( const QString &str);
    ~UnitString();

	double		value() { return mValue;};
	QString		unit() { return mUnit;};

private:
    
	double		mValue;
	QString		mUnit;
};

#endif // UNITSTRING_H
