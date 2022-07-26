#include "UNMEAGGAString.h"

#include <QTime>
#include <QGeoCoordinate>
#include <QDebug>

#include "FCalculate.h"

UNMEAGGAString::UNMEAGGAString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _UTCTime_po(new QTime)
  , _Coordinates_po(new QGeoCoordinate)
{
  _NMEADataType_en = ENMEADATATYPE::GGA;
}

UNMEAGGAString::~UNMEAGGAString()
{
  delete _UTCTime_po;
  delete _Coordinates_po;
}

void UNMEAGGAString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 15) {
    *_UTCTime_po = QTime::fromString(NMEAData_lst[1], "HHmmss.zzz");
    _Coordinates_po->setLatitude(FCalculate::latitudeFromStr(NMEAData_lst[2], NMEAData_lst[3]));
    _Coordinates_po->setLongitude(FCalculate::longitudeFromStr(NMEAData_lst[4], NMEAData_lst[5]));
    _CalcMethod_en = static_cast<ECALCMETHOD>(NMEAData_lst[6].toInt());
    _SatellitesQty_u = NMEAData_lst[7].toUInt();
    _HDOP_d = NMEAData_lst[8].toDouble();
    _Altitude_d = FCalculate::altitudeFromStr(NMEAData_lst[9], NMEAData_lst[10]);
    _MeanSeaLevel_d = FCalculate::altitudeFromStr(NMEAData_lst[11], NMEAData_lst[12]);
    _Timeout_d = NMEAData_lst[13].toDouble();
    _StationID_u = NMEAData_lst[14].toUInt();
  }
  qDebug()<<*this;
}

const QTime &UNMEAGGAString::utcTime() const
{
  return * _UTCTime_po;
}

const QGeoCoordinate &UNMEAGGAString::coordinates() const
{
  return *_Coordinates_po;
}

UNMEAGGAString::ECALCMETHOD UNMEAGGAString::calcMethod() const
{
  return _CalcMethod_en;
}

quint32 UNMEAGGAString::satellitesQty() const
{
  return _SatellitesQty_u;
}

qreal UNMEAGGAString::hdop() const
{
  return _HDOP_d;
}

qreal UNMEAGGAString::altitude() const
{
  return _Altitude_d;
}

qreal UNMEAGGAString::meanSeaLevel() const
{
  return _MeanSeaLevel_d;
}

qreal UNMEAGGAString::timeout() const
{
  return _Timeout_d;
}

quint32 UNMEAGGAString::stationID() const
{
  return _StationID_u;
}

QDebug operator<<(QDebug debugObject, const UNMEAGGAString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.utcTime() << ", "
    << data.coordinates() << ", "
    << static_cast<int>(data.calcMethod()) << ", "
    << data.satellitesQty() << ", "
    << data.hdop() << ", "
    << data.altitude() << ", "
    << data.meanSeaLevel() << ", "
    << data.timeout() << ", "
    << data.stationID()
    << ")";
  return debugObject.space();
}
