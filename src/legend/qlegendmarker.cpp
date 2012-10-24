/****************************************************************************
 **
 ** Copyright (C) 2012 Digia Plc
 ** All rights reserved.
 ** For any questions to Digia, please use contact form at http://qt.digia.com
 **
 ** This file is part of the Qt Commercial Charts Add-on.
 **
 ** $QT_BEGIN_LICENSE$
 ** Licensees holding valid Qt Commercial licenses may use this file in
 ** accordance with the Qt Commercial License Agreement provided with the
 ** Software or, alternatively, in accordance with the terms contained in
 ** a written agreement between you and Digia.
 **
 ** If you have questions regarding the use of this file, please use
 ** contact form at http://qt.digia.com
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

#include "qlegendmarker.h"
#include "qlegendmarker_p.h"
#include "legendmarkeritem_p.h"
#include "qlegend.h"
#include "qlegend_p.h"
#include "legendlayout_p.h"
#include <QFontMetrics>
#include <QGraphicsSceneEvent>
#include <QAbstractSeries>

QTCOMMERCIALCHART_BEGIN_NAMESPACE

/*!
    \class QLegendMarker
    \brief LegendMarker object
    \mainclass

    QLegendMarker is abstract object that can be used to access markers inside QLegend. The QLegendMarker is always connected
    to some series

    \image examples_legendmarkers.png

    \sa QLegend
*/
/*!
    \enum QLegendMarker::LegendMarkerType

    The type of the legendmarker object.

    \value LegendMarkerTypeArea
    \value LegendMarkerTypeBar
    \value LegendMarkerTypePie
    \value LegendMarkerTypeXY
*/

/*!
    \fn virtual LegendMarkerType QLegendMarker::type() = 0;
    Returns the type of legendmarker. Type depends of the related series. LegendMarkerTypeXY is used for all QXYSeries derived
    classes.
*/

/*!
    \fn virtual QAbstractSeries* QLegendMarker::series() = 0;
    Returns pointer to series, which is related to this marker. Marker is always related to some series.
*/

/*!
  \fn void QLegendMarker::clicked();
  This signal is emitted, when marker is clicked with mouse.
*/

/*!
  \fn void QLegendMarker::hovered(bool status);
  This signal is emitted, when mouse is hovered over marker. \a status is true, when mouse enters the marker
  and false when it leaves the marker.
*/

/*!
 Constructor of marker
 */
QLegendMarker::QLegendMarker(QLegendMarkerPrivate &d, QObject *parent) :
    QObject(parent),
    d_ptr(&d)
{
    d_ptr->m_item->setVisible(d_ptr->series()->isVisible());
}

/*!
  Destructor of marker
*/
QLegendMarker::~QLegendMarker()
{
}

/*!
  Returns the label of the marker.
*/
QString QLegendMarker::label() const
{
    return d_ptr->m_item->label();
}

/*!
  Sets the \a label of marker. Note that changing name of series will also change label of its marker.
*/
void QLegendMarker::setLabel(const QString &label)
{
    d_ptr->m_item->setLabel(label);
}
/*!
  Returns the brush which is used to draw label.
*/
QBrush QLegendMarker::labelBrush() const
{
    return d_ptr->m_item->labelBrush();
}

/*!
  Sets the \a brush of label
*/
void QLegendMarker::setLabelBrush(const QBrush &brush)
{
    d_ptr->m_item->setLabelBrush(brush);
}

/*!
  Retuns the font of label
*/
QFont QLegendMarker::font() const
{
    return d_ptr->m_item->font();
}

/*!
  Sets the \a font of label
*/
void QLegendMarker::setFont(const QFont &font)
{
    d_ptr->m_item->setFont(font);
}

/*!
  Returns the pen of marker item
*/
QPen QLegendMarker::pen() const
{
    return d_ptr->m_item->pen();
}

/*!
  Sets the \a pen of marker item
*/
void QLegendMarker::setPen(const QPen &pen)
{
    d_ptr->m_item->setPen(pen);
}

/*!
  Returns the brush of marker item
*/
QBrush QLegendMarker::brush() const
{
    return d_ptr->m_item->brush();
}

/*!
  Sets the \a brush of marker item. Note that changing color of the series also changes this.
*/
void QLegendMarker::setBrush(const QBrush &brush)
{
    d_ptr->m_item->setBrush(brush);
}

/*!
  Returns visibility of the marker
*/
bool QLegendMarker::isVisible() const
{
    return d_ptr->m_item->isVisible();
}

/*!
  Sets markers visibility to \a visible
*/
void QLegendMarker::setVisible(bool visible)
{
    d_ptr->m_item->setVisible(visible);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QLegendMarkerPrivate::QLegendMarkerPrivate(QLegendMarker *q, QLegend *legend) :
    m_legend(legend),
    q_ptr(q)
{
    m_item = new LegendMarkerItem(this);
}

QLegendMarkerPrivate::~QLegendMarkerPrivate()
{
}

void QLegendMarkerPrivate::invalidateLegend()
{
    m_legend->d_ptr->m_layout->invalidate();
}

#include "moc_qlegendmarker.cpp"
#include "moc_qlegendmarker_p.cpp"

QTCOMMERCIALCHART_END_NAMESPACE
