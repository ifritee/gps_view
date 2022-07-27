#include "UNMEAGSAString.h"

#include <QDebug>

UNMEAGSAString::UNMEAGSAString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::GSA;
}

UNMEAGSAString::~UNMEAGSAString()
{
}

void UNMEAGSAString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 18) {
    _IsAuto_b = (NMEAData_lst[1] == "A");
    _Format_en = static_cast<EFORMAT>(NMEAData_lst[2].toUInt());
    _SatellitesID_vec.clear();
    for (int i = 3; i <= 14; ++i) {
      int id = NMEAData_lst[i].toUInt();
      if (id > 0) { _SatellitesID_vec.push_back(id); }
    }
    _PDOP_d = NMEAData_lst[15].toDouble();
    _HDOP_d = NMEAData_lst[16].toDouble();
    _VDOP_d = NMEAData_lst[17].toDouble();
    if (satelliteType_en() == ESATELLITETYPE::GN && NMEAData_lst.size() >= 19) {
      _NaviType_en = static_cast<ESATELLITETYPE>(NMEAData_lst[18].toUInt());
    }
  }
  qDebug()<<*this;
}

bool UNMEAGSAString::isAuto() const
{
  return _IsAuto_b;
}

UNMEAGSAString::EFORMAT UNMEAGSAString::format() const
{
  return _Format_en;
}

const std::vector<quint32> &UNMEAGSAString::satellitesID() const
{
  return _SatellitesID_vec;
}

qreal UNMEAGSAString::PDOP() const
{
  return _PDOP_d;
}

qreal UNMEAGSAString::HDOP() const
{
  return _HDOP_d;
}

qreal UNMEAGSAString::VDOP() const
{
  return _VDOP_d;
}

ESATELLITETYPE UNMEAGSAString::naviType() const
{
  return _NaviType_en;
}


QDebug operator<<(QDebug debugObject, const UNMEAGSAString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.isAuto() << ", "
    << static_cast<int>(data.format()) << ", "
    << data.satellitesID() << ", "
    << data.PDOP() << ", "
    << data.HDOP() << ", "
    << data.VDOP() << ", "
    << static_cast<int>(data.naviType())
    << ")";
  return debugObject.space();
}
