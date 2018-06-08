// $Id: heightlineedit.h 350 2010-03-27 12:01:23Z nebanch $
// (c) 2008, Parallel Pixels Ltd. 

#ifndef HEIGHTLINEEDIT_H
#define HEIGHTLINEEDIT_H

#include <QObject>
#include <QLineEdit>
#include <QValidator>
#include <QString>

#include "src/util/heightunits.h"

class HeightLineEdit : public QLineEdit
{
	Q_OBJECT

public:
        HeightLineEdit( QWidget *parent = 0);
        ~HeightLineEdit();

        void setValue( const double value) { mValue.setValue( value); emit valueChanged(value); }
        double value() const { return mValue.value();}
	void displayValue( const int digits = 1, bool suffix = true);

        QString	height( const int digits = 1) const;
        void setHeight( QString dist);

private slots:

        void updateHeight();

signals:
        void valueChanged(double);

private:

        HeightString	mValue;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class HeightValidator : public QValidator
{
	Q_OBJECT

public:

        HeightValidator(QObject *parent);
        ~HeightValidator();

	QValidator::State validate( QString &input, int &pos) const;

private:
};

#endif // HEIGHTLINEEDIT_H
