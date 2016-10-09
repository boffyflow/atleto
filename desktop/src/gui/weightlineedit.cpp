// $Id: weightlineedit.cpp 286 2010-02-19 09:24:49Z  $
// (c) 2008, Parallel Pixels Ltd. 

#include <QSettings>
#include <QRegExp>

#include "src/gui/weightlineedit.h"
#include "src/util/weightunits.h"
#include "src/util/cgeneral.h"

WeightLineEdit::WeightLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	WeightValidator		*wValidator = new WeightValidator( this);
	setValidator( wValidator);

	connect( this, SIGNAL( editingFinished()), this, SLOT( updateWeight()));
}

WeightLineEdit::~WeightLineEdit()
{
}

void
WeightLineEdit::updateWeight()
{
	QString				input = text();

	if( input.isEmpty())
		setValue( UNDEFINED_WEIGHT);
	else
		mValue.setText( input);
	
	displayValue();
}

void
WeightLineEdit::displayValue( int digits, bool suffix)
{
	if( mValue.value() <= UNDEFINED_WEIGHT)
		setText( "");
	else
		setText( mValue.text( digits, suffix));
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

WeightValidator::WeightValidator( QObject *parent)
: QValidator( parent)
{
}

WeightValidator::~WeightValidator()
{

}

QValidator::State
WeightValidator::validate( QString &input, int &pos) const
{
/*
	for( int i = 0; i < input.size(); i++)
	{
		if( !input[i].isDigit() && input[i] != '.' && input[i] != 'c' && input[i] != 'C' && input[i] != 'f' &&
			!input[i].isSpace() && input[i] != 'F' && input[i] != '-')
			return QValidator::Invalid;
	}

	if( ( input.count( 'c', Qt::CaseInsensitive) > 1) || ( input.count( 'f', Qt::CaseInsensitive) > 1))
		return QValidator::Invalid;
*/
	return QValidator::Acceptable;
}
