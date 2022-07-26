#include "CConstants.h"

#include <QDebug>

CConstants::CConstants()
{
  _SatelliteTypes_map["GP"] = ESATELLITETYPE::GP;
  _SatelliteTypes_map["GL"] = ESATELLITETYPE::GL;
  _SatelliteTypes_map["GA"] = ESATELLITETYPE::GA;
  _SatelliteTypes_map["BD"] = ESATELLITETYPE::BD;
  _SatelliteTypes_map["GQ"] = ESATELLITETYPE::GQ;
  _SatelliteTypes_map["GN"] = ESATELLITETYPE::GN;

  _NMEADataTypes_map["GGA"] = ENMEADATATYPE::GGA;
  _NMEADataTypes_map["GLL"] = ENMEADATATYPE::GLL;
  _NMEADataTypes_map["GSA"] = ENMEADATATYPE::GSA;
  _NMEADataTypes_map["GSV"] = ENMEADATATYPE::GSV;
  _NMEADataTypes_map["RMC"] = ENMEADATATYPE::RMC;
  _NMEADataTypes_map["VTG"] = ENMEADATATYPE::VTG;
  _NMEADataTypes_map["ZDA"] = ENMEADATATYPE::ZDA;
  _NMEADataTypes_map["DHV"] = ENMEADATATYPE::DHV;
  _NMEADataTypes_map["GST"] = ENMEADATATYPE::GST;
  _NMEADataTypes_map["TXT"] = ENMEADATATYPE::TXT;
}

ESATELLITETYPE CConstants::satelliteTypeByString_en(const QString & text)
{
  for (auto type : _SatelliteTypes_map) {
    if (text.contains(type.first)) {
      return type.second;
    }
  }
  return ESATELLITETYPE::NONE;
}

ENMEADATATYPE CConstants::NMEATypeByString_en(const QString & text)
{
  for (auto type : _NMEADataTypes_map) {
    if (text.contains(type.first)) {
      return type.second;
    }
  }
  return ENMEADATATYPE::NONE;
}

QByteArray CConstants::subArray(const QByteArray &array, QChar begin, QChar end)
{
  QByteArray returnArray;
  bool isStart = false, isEnd = false;
  for(const QChar & symbol : array) {
    if (symbol == begin) { isStart = true; continue; }
    if (symbol == end) { isEnd = true; break; }
    if (isStart == true) {
      returnArray += symbol.toLatin1();
    }
  }
  if (isStart != true || isEnd != true) { returnArray = QByteArray(); }
  return returnArray;
}

bool CConstants::isChecksumCorrect(const QByteArray &data, quint32 crc)
{
  unsigned char xorData = 0;
  for (char symbol : data) {
    xorData = xorData ^ symbol;
  }
  return xorData == crc;
}

QDebug operator<<(QDebug debugObject, const SGSVSatellitesData & data)
{
  debugObject.nospace()
      << "SGSVSatellitesData" << " ("
    << data._IDSatellite_u << ", "
    << data._Angle_u << ", "
    << data._Azimuth_u << ", "
    << data._SNR_u
    << ")";
  return debugObject.space();
}
