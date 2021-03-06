// $Id: heightlineedit.cpp 324 2010-03-16 22:33:59Z boffyflow $
// (c) 2008, Parallel Pixels Ltd. 

#include <QSettings>
#include <QRegExp>

#include "src/gui/heightlineedit.h"
#include "src/util/rununits.h"
#include "src/util/cgeneral.h"

HeightLineEdit::HeightLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
    HeightValidator		*wValidator = new HeightValidator( this);
    setValidator( wValidator);

    connect( this, SIGNAL( editingFinished()), this, SLOT( updateHeight()));
}

HeightLineEdit::~HeightLineEdit()
{
}

void
HeightLineEdit::updateHeight()
{
    QString         input = QLineEdit::text();

    if( input.isEmpty())
        setValue( UNDEFINED_LENGTH);
    else
        mValue.setText( input);

    displayValue( 2);
}

void
HeightLineEdit::displayValue( int digits, bool suffix)
{
    if( mValue.value() <= UNDEFINED_LENGTH)
        setText( "");
    else
        setText( mValue.text( digits, suffix));
}

QString
HeightLineEdit::height( const int digits) const
{
    return mValue.text( digits);
}

void
HeightLineEdit::setHeight( QString dist)
{
    if( dist.isEmpty())
        setValue( UNDEFINED_LENGTH);
    else
        mValue.setText( dist);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

HeightValidator::HeightValidator( QObject *parent)
: QValidator( parent)
{
}

HeightValidator::~HeightValidator()
{

}

QValidator::State
HeightValidator::validate( QString &input, int &pos) const
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

