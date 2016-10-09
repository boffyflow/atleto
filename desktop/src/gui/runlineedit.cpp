// $Id: runlineedit.cpp 214 2009-05-28 17:44:45Z robert $
// (c) 2008, Parallel Pixels Ltd. 

#include <QSettings>
#include <QRegExp>

#include "src/gui/runlineedit.h"
#include "src/util/rununits.h"
#include "src/util/cgeneral.h"

RunLineEdit::RunLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	RunValidator		*wValidator = new RunValidator( this);
	setValidator( wValidator);

	connect( this, SIGNAL( editingFinished()), this, SLOT( updateRun()));
}

RunLineEdit::~RunLineEdit()
{
}

void
RunLineEdit::updateRun()
{
	QString				input = QLineEdit::text();

	if( input.isEmpty())
		setValue( UNDEFINED_LENGTH);
	else
		mValue.setText( input);
	
	displayValue();
}

void
RunLineEdit::displayValue( int digits, bool suffix)
{
	if( mValue.value() <= UNDEFINED_LENGTH)
		setText( "");
	else
		setText( mValue.text( digits, suffix));
}

QString
RunLineEdit::distance( const int digits) const
{
	return mValue.text( digits);
}

void
RunLineEdit::setDistance( QString dist)
{
	if( dist.isEmpty())
		setValue( UNDEFINED_LENGTH);
	else
		mValue.setText( dist);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

RunValidator::RunValidator( QObject *parent)
: QValidator( parent)
{
}

RunValidator::~RunValidator()
{

}

QValidator::State
RunValidator::validate( QString &input, int &pos) const
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

