// $Id: units.h 370 2010-12-14 23:23:50Z boffyflow $
// (c) 2007, Parallel Pixels Ltd. 

#ifndef UNITS_H
#define UNITS_H

#include <QObject>
#include <QStringList>
#include <QMap>
#include <QSettings>

typedef  QMap<QString,double>    UnitMap;

class Units : public QObject
{
	Q_OBJECT;

	public:

	   Units();
	   ~Units();

	   virtual double convert( const double value, const QString& from, const QString& to) const = 0;

//       virtual void  save() = 0;
//       virtual void  restore() = 0;

	   double   currentToBase( const double value) const;
	   double   baseToCurrent( const double value) const;

	   UnitMap  unitMap() const { return mUnitmap;};

	   QString  current() const { return mCurrent;};
	   QString  base() const { return mBase;};

	   void     setCurrent( const QString& current) { mCurrent = current;};
	   void     setBase( const QString& base) { mBase = base;};

	   QString  utype() const { return mName;};
	   void     setUType( const QString& name) { mName = name;};

	protected:

	   UnitMap        mUnitmap;

	private:

	   QString        mCurrent;
	   QString        mBase;
	   QString        mName;
};

#endif

