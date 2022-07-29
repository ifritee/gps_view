#include "UNMEAZDAString.h"

#include <QTime>
#include <QDate>
#include <QDebug>

UNMEAZDAString::UNMEAZDAString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _UTCTime_po(new QTime)
  , _Date_po(new QDate)
{
  _NMEADataType_en = ENMEADATATYPE::ZDA;
}

UNMEAZDAString::~UNMEAZDAString()
{
  delete _UTCTime_po;
  delete _Date_po;
}

void UNMEAZDAString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 7) {
    *_UTCTime_po = QTime::fromString(NMEAData_lst[1], "HHmmss.zzz");
    *_Date_po = QDate::fromString(NMEAData_lst[2] + NMEAData_lst[3] + NMEAData_lst[4], "ddMMyyyy");
    _ZoneHours_i = NMEAData_lst[5].toInt();
    _ZoneMinuts_i = NMEAData_lst[6].toInt();
  }
  qDebug()<<*this;
}

const QTime &UNMEAZDAString::utcTime() const
{
  return * _UTCTime_po;
}

const QDate &UNMEAZDAString::date() const
{
  return * _Date_po;
}

qint32 UNMEAZDAString::zoneHours() const
{
  return _ZoneHours_i;
}

qint32 UNMEAZDAString::zoneMinuts() const
{
  return _ZoneMinuts_i;
}

QDebug operator<<(QDebug debugObject, const UNMEAZDAString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.utcTime() << ", "
    << data.date() << ", "
    << data.zoneHours() << ", "
    << data.zoneMinuts() << ", "
    << ")";
  return debugObject.space();
}
