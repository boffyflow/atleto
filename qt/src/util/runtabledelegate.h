// (c)2007 Parallel Pixels Ltd. 
// $Id: runtabledelegate.h 214 2009-05-28 17:44:45Z robert $

#ifndef RUNTABLEDELEGATE_H
#define RUNTABLEDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class RunTableDelegate : public QItemDelegate
{
	Q_OBJECT

public:

	RunTableDelegate( QObject *parent = 0);
	~RunTableDelegate();

	QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const;
	void setEditorData( QWidget *editor, const QModelIndex &index) const;
	void setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
	bool eventFilter( QObject *editor, QEvent *event);

private slots:

	void commitAndCloseEditor();

private:
	
};

#endif // RUNTABLEDELEGATE_H
