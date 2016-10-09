// (c)2007 Parallel Pixels Ltd. 
// $Id: runtabledelegate.cpp 291 2010-03-01 02:39:57Z robert $

#include <QLineEdit>
#include <QModelIndex>
#include <QTimeEdit>
#include <QPainter>
#include <QEvent>
#include <QKeyEvent>
#include <QtGui>

#include "runtabledelegate.h"
#include "src/gui/runlineedit.h"

RunTableDelegate::RunTableDelegate( QObject *parent)
	: QItemDelegate( parent)
{
}

RunTableDelegate::~RunTableDelegate()
{
}

QWidget *
RunTableDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const
{
	if( index.column() == 0)	// distance
	{
		RunLineEdit	 *editor = new RunLineEdit( parent);
		editor->setFocusPolicy( Qt::StrongFocus);
		connect( editor, SIGNAL( editingFinished()), this, SLOT( commitAndCloseEditor()));

		return editor;
	}
	if( index.column() == 1)	// time
	{
		QTimeEdit *editor = new QTimeEdit( parent);
                editor->setDisplayFormat( "HH:mm:ss");
		editor->setFocusPolicy( Qt::StrongFocus);

		return editor;
	}
	if( index.column() == 3)	// heartrate
	{
		QLineEdit *editor = new QLineEdit( parent);
		editor->setValidator( new QIntValidator( 0, 500, editor));
		connect( editor, SIGNAL( editingFinished()), this, SLOT( commitAndCloseEditor()));

		return editor;
	}
	if( index.column() == 4)	// comment
	{
		QLineEdit *editor = new QLineEdit( parent);
		connect( editor, SIGNAL( editingFinished()), this, SLOT( commitAndCloseEditor()));

		return editor;
	}
	return NULL;
}

void
RunTableDelegate::setEditorData( QWidget *editor, const QModelIndex &index) const
{
	RunLineEdit		*redit = qobject_cast<RunLineEdit *>(editor);
	if( redit)
	{
		redit->setValue( index.model()->data( index, Qt::UserRole).toDouble());
		redit->displayValue( 2);
	}
	else
	{
		QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
		if( edit)
		{
			edit->setText( index.model()->data( index, Qt::EditRole).toString());
			if( index.column() == 3)		// heartrate
			{
				if( index.model()->data( index, Qt::EditRole).toInt() == 0)
					edit->setText( "");
			}
		}
		else
		{
			QTimeEdit	*timeEditor = qobject_cast<QTimeEdit *>(editor);
			if( timeEditor)
			{
                                timeEditor->setTime( QTime::fromString( index.model()->data( index, Qt::EditRole).toString(), "HH:mm:ss"));
			}
		}
	}
}

void
RunTableDelegate::setModelData( QWidget *editor, QAbstractItemModel *model,
									   const QModelIndex &index) const
{
	RunLineEdit		*redit = qobject_cast<RunLineEdit *>(editor);
	if( redit)
	{
		model->setData( index, redit->value(), Qt::UserRole);
		model->setData( index, redit->distance( 2), Qt::DisplayRole);
	}
	else
	{
		QLineEdit *edit = qobject_cast<QLineEdit *>(editor);
		if( edit)
		{
			model->setData( index, edit->text());
		}
		else
		{
			QTimeEdit	*timeEditor = qobject_cast<QTimeEdit *>(editor);
			if( timeEditor)
			{
                                model->setData( index, timeEditor->time().toString( "HH:mm:ss"));
			}
		}
	}
}

void
RunTableDelegate::commitAndCloseEditor()
{
	RunLineEdit *reditor = qobject_cast<RunLineEdit *>(sender());
	if( reditor)
	{
		emit commitData( reditor);
		emit closeEditor( reditor);
	}
	else
	{
		QLineEdit	*editor = qobject_cast<QLineEdit *>(sender());
		if( editor)
		{
			emit commitData( editor);
			emit closeEditor( editor);
		}
	}
}

bool
RunTableDelegate::eventFilter( QObject *editor, QEvent *event)
{
	RunLineEdit *reditor = qobject_cast<RunLineEdit *>(editor);
	if( reditor)
	{
		return false;
	}

	QTimeEdit	*teditor = qobject_cast<QTimeEdit *>(editor);
	if( teditor)
	{
		return false;
	}

	return QItemDelegate::eventFilter( editor, event);
}
