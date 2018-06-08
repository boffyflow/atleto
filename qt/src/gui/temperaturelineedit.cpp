// $Id: temperaturelineedit.cpp 286 2010-02-19 09:24:49Z  $
// (c) 2008, Parallel Pixels Ltd. 

#include <QSettings>
#include <QRegExp>

#include "src/gui/temperaturelineedit.h"
#include "src/util/temperatureunits.h"
#include "src/util/cgeneral.h"

TemperatureLineEdit::TemperatureLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	TemperatureValidator	*tempValidator = new TemperatureValidator( this);
	setValidator( tempValidator);

	connect( this, SIGNAL( editingFinished()), this, SLOT( updateTemperature()));
}

TemperatureLineEdit::~TemperatureLineEdit()
{
}

void
TemperatureLineEdit::updateTemperature()
{
	QString				input = text();

	if( input.isEmpty())
		setValue( UNDEFINED_TEMPERATURE);
	else
		mValue.setText( input);
	
	displayValue();
}

void
TemperatureLineEdit::displayValue( int digits, bool suffix)
{
	if( mValue.value() <= UNDEFINED_TEMPERATURE)
		setText( "");
	else
		setText( mValue.text( digits, suffix));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

TemperatureValidator::TemperatureValidator( QObject *parent)
: QValidator( parent)
{
}

TemperatureValidator::~TemperatureValidator()
{

}

QValidator::State
TemperatureValidator::validate( QString &input, int &pos) const
{
	for( int i = 0; i < input.size(); i++)
	{
		if( !input[i].isDigit() && input[i] != '.' && input[i] != 'c' && input[i] != 'C' && input[i] != 'f' &&
			!input[i].isSpace() && input[i] != 'F' && input[i] != '-')
			return QValidator::Invalid;
	}

	if( ( input.count( 'c', Qt::CaseInsensitive) > 1) || ( input.count( 'f', Qt::CaseInsensitive) > 1))
		return QValidator::Invalid;

	return QValidator::Acceptable;
}
