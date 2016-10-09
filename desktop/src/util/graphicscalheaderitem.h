// $Id: graphicscalheaderitem.h 294 2010-03-05 18:37:10Z  $
// (c) 2009, Parallel Pixels Ltd.

#ifndef GRAPHICSCALHEADERITEM_H
#define GRAPHICSCALHEADERITEM_H

#include <QGraphicsRectItem>
#include <QDate>
#include <QPainter>

class QColor;
class QGraphicsProxyWidget;
class GraphicsButtonItem;

class GraphicsCalHeaderItem : public QGraphicsRectItem
{
public:

    GraphicsCalHeaderItem( qreal x, qreal y, qreal width, qreal height);

    void hoverEnterEvent( QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent( QGraphicsSceneHoverEvent * event);

    void setDate( const QDate &date);
    void setBackGroundColor( const QColor &color) { mBackGround = color;};
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    bool                    mInside;
    QColor                  mBackGround;
    QDate                   mDate;
    QGraphicsProxyWidget    *mDateLabel;
    GraphicsButtonItem      *mWeatherButton;
    GraphicsButtonItem      *mPhysicalButton;
    GraphicsButtonItem      *mJournalButton;
};

#endif // GRAPHICSCALHEADERITEM_H
