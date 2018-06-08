// $Id: temperaturelineedit.h 286 2010-02-19 09:24:49Z  $
// (c) 2008, Parallel Pixels Ltd. 

#ifndef TEMPERATURELINEEDIT_H
#define TEMPERATURELINEEDIT_H

#include <QLineEdit>
#include <QValidator>

#include "src/util/temperatureunits.h"

class TemperatureLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	TemperatureLineEdit( QWidget *parent = 0);
	~TemperatureLineEdit();

	void setValue( const double value) { mValue.setValue( value);};
	double value() { return mValue.value();};
	void displayValue( int digits = 1, bool suffix = true);

private slots:

	void updateTemperature();

private:

	TemperatureString	mValue;
};

class TemperatureValidator : public QValidator
{
	Q_OBJECT

public:

	TemperatureValidator(QObject *parent);
	~TemperatureValidator();

	QValidator::State validate( QString &input, int &pos) const;

private:
};

#endif // TEMPERATURELINEEDIT_H
