#include "USatelliteItem.h"

#include <QPainter>

#include "CConstants.h"

USatelliteItem::USatelliteItem(QGraphicsItem *parent)
  : QGraphicsItem(parent)
{

}

USatelliteItem::~USatelliteItem()
{

}

void USatelliteItem::setData_v(ESATELLITETYPE satelliteType, const SGSVSatellitesData & data)
{
  _SatelliteType_en = satelliteType;
  _GSVData_o = data;
}

QRectF USatelliteItem::boundingRect() const
{
  return QRectF(-16, -16, 32, 32);
}

void USatelliteItem::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
  painter->setPen(Qt::red);
  painter->setBrush(Qt::red);
  if (_SatelliteType_en == ESATELLITETYPE::GP) { // Если GPS
    painter->drawEllipse(QPointF(0,0), 4, 4);
  }
  painter->setPen(Qt::white);
  painter->drawText(QPointF(-6, 14), QString::number(_GSVData_o._IDSatellite_u).rightJustified(2, '0'));
}
