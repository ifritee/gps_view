#include "UNMEADHVString.h"

#include <QVector3D>
#include <QTime>
#include <QDebug>

UNMEADHVString::UNMEADHVString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _UTCTime_po(new QTime)
  , _SpeedECEF_po(new QVector3D)
{
  _NMEADataType_en = ENMEADATATYPE::DHV;
}

UNMEADHVString::~UNMEADHVString()
{
  delete _UTCTime_po;
  delete _SpeedECEF_po;
}

void UNMEADHVString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 7) {
    *_UTCTime_po = QTime::fromString(NMEAData_lst[1], "HHmmss.zzz");
    _Speed3D_d = NMEAData_lst[2].toDouble();
    _SpeedECEF_po->setX(NMEAData_lst[3].toDouble());
    _SpeedECEF_po->setY(NMEAData_lst[4].toDouble());
    _SpeedECEF_po->setZ(NMEAData_lst[5].toDouble());
    _Speed_d = NMEAData_lst[6].toDouble();
  }
  qDebug()<<*this;
}

const QTime &UNMEADHVString::utcTime() const
{
  return * _UTCTime_po;
}

qreal UNMEADHVString::speed3D() const
{
  return _Speed3D_d;
}

const QVector3D &UNMEADHVString::speedECEF() const
{
  return *_SpeedECEF_po;
}

qreal UNMEADHVString::speed() const
{
  return _Speed_d;
}

QDebug operator<<(QDebug debugObject, const UNMEADHVString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.utcTime() << ", "
    << data.speed3D() << ", "
    << data.speedECEF() << ", "
    << data.speed()
    << ")";
  return debugObject.space();
}
