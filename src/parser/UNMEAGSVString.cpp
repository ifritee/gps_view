#include "UNMEAGSVString.h"

#include <QDebug>

UNMEAGSVString::UNMEAGSVString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::GSV;
}

UNMEAGSVString::~UNMEAGSVString()
{
  _SatellitesData_vec.clear();
}

void UNMEAGSVString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  _MessagesQty_u = NMEAData_lst[1].toUInt();
  _MessageNumber_u = NMEAData_lst[2].toUInt();
  _SatellitesQty_u = NMEAData_lst[3].toUInt();
  for (int i = 4; i < NMEAData_lst.size(); i+=4) {
    SGSVSatellitesData data;
    data._IDSatellite_u = NMEAData_lst[i + 0].toUInt();
    data._Angle_u = NMEAData_lst[i + 1].toUInt();
    data._Azimuth_u = NMEAData_lst[i + 2].toUInt();
    data._SNR_u = NMEAData_lst[i + 3].toUInt();
    _SatellitesData_vec.push_back(data);
  }
  qDebug()<<*this;
}

quint32 UNMEAGSVString::messagesQty() const
{
  return _MessagesQty_u;
}

quint32 UNMEAGSVString::messageNumber() const
{
  return _MessageNumber_u;
}

quint32 UNMEAGSVString::satellitesQty() const
{
  return _SatellitesQty_u;
}

const std::vector<SGSVSatellitesData> & UNMEAGSVString::satellitesData() const
{
  return _SatellitesData_vec;
}

QDebug operator<<(QDebug debugObject, const UNMEAGSVString & data)
{
  debugObject.nospace()
    << "UNMEAGSVString" << " ("
    << data.messagesQty() << ", "
    << data.messageNumber() << ", "
    << data.satellitesQty() << ", "
    << data.satellitesData()
    << ")";
  return debugObject.space();
}
