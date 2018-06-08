// $Id: weightlineedit.h 286 2010-02-19 09:24:49Z  $
// (c) 2008, Parallel Pixels Ltd. 

#ifndef WEIGHTLINEEDIT_H
#define WEIGHTLINEEDIT_H

#include <QLineEdit>
#include <QValidator>

#include "src/util/weightunits.h"

class WeightLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	WeightLineEdit( QWidget *parent = 0);
	~WeightLineEdit();

	void setValue( const double value) { mValue.setValue( value);};
	double value() { return mValue.value();};
	void displayValue( int digits = 1, bool suffix = true);

private slots:

	void updateWeight();

private:

	WeightString	mValue;
};

class WeightValidator : public QValidator
{
	Q_OBJECT

public:

	WeightValidator(QObject *parent);
	~WeightValidator();

	QValidator::State validate( QString &input, int &pos) const;

private:
};

#endif // WEIGHTLINEEDIT_H
