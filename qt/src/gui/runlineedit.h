// $Id: runlineedit.h 214 2009-05-28 17:44:45Z robert $
// (c) 2008, Parallel Pixels Ltd. 

#ifndef RUNLINEEDIT_H
#define RUNLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QValidator>
#include <QString>

#include "src/util/rununits.h"

class RunLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	RunLineEdit( QWidget *parent = 0);
	~RunLineEdit();

	void setValue( const double value) { mValue.setValue( value);};
	double value() const { return mValue.value();};
	void displayValue( const int digits = 1, bool suffix = true);

	QString	distance( const int digits = 1) const;
	void setDistance( QString dist);

private slots:

	void updateRun();

private:

	RunDistanceString	mValue;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class RunValidator : public QValidator
{
	Q_OBJECT

public:

	RunValidator(QObject *parent);
	~RunValidator();

	QValidator::State validate( QString &input, int &pos) const;

private:
};

#endif // RunLINEEDIT_H
