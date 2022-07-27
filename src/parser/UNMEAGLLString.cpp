#include "UNMEAGLLString.h"

#include <QGeoCoordinate>
#include <QTime>
#include <QDebug>

#include "FCalculate.h"

UNMEAGLLString::UNMEAGLLString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _Coordinates_po(new QGeoCoordinate)
  , _UTCTime_po(new QTime)
{
  _NMEADataType_en = ENMEADATATYPE::GLL;

  _CalcMethodDict_map["A"] = ECALCMETHOD::AUTO;
  _CalcMethodDict_map["D"] = ECALCMETHOD::DIFF;
  _CalcMethodDict_map["E"] = ECALCMETHOD::APPROX;
  _CalcMethodDict_map["M"] = ECALCMETHOD::FIX_DATA;
  _CalcMethodDict_map["N"] = ECALCMETHOD::FALSE_DATA;
}

UNMEAGLLString::~UNMEAGLLString()
{
  delete _UTCTime_po;
  delete _Coordinates_po;
}

void UNMEAGLLString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 8) {
    _Coordinates_po->setLatitude(FCalculate::latitudeFromStr(NMEAData_lst[1], NMEAData_lst[2]));
    _Coordinates_po->setLongitude(FCalculate::longitudeFromStr(NMEAData_lst[3], NMEAData_lst[4]));
    *_UTCTime_po = QTime::fromString(NMEAData_lst[5], "HHmmss.zzz");
    _IsReliability_b = (NMEAData_lst[6] == "A");
    _CalcMethod_en = ECALCMETHOD::NONE;
    if (_CalcMethodDict_map.find(NMEAData_lst[7]) != _CalcMethodDict_map.end()) {
      _CalcMethod_en = _CalcMethodDict_map[NMEAData_lst[7]];
    }
  }
  qDebug()<<*this;
}

const QGeoCoordinate &UNMEAGLLString::coordinates() const
{
  return *_Coordinates_po;
}

const QTime &UNMEAGLLString::utcTime() const
{
  return *_UTCTime_po;
}

bool UNMEAGLLString::isReliability() const
{
  return _IsReliability_b;
}

UNMEAGLLString::ECALCMETHOD UNMEAGLLString::calcMethod() const
{
  return _CalcMethod_en;
}

QDebug operator<<(QDebug debugObject, const UNMEAGLLString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.coordinates() << ", "
    << data.utcTime() << ", "
    << data.isReliability() << ", "
    << static_cast<int>(data.calcMethod())
    << ")";
  return debugObject.space();
}
