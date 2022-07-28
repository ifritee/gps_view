#include "UNMEARMCString.h"

#include <QGeoCoordinate>
#include <QDate>
#include <QTime>
#include <QDebug>

#include "FCalculate.h"

UNMEARMCString::UNMEARMCString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _UTCTime_po(new QTime)
  , _Coordinates_po(new QGeoCoordinate)
  , _Date_po(new QDate)
{
  _NMEADataType_en = ENMEADATATYPE::RMC;

  _CalcMethodDict_map["A"] = ECALCMETHOD::AUTO;
  _CalcMethodDict_map["D"] = ECALCMETHOD::DIFF;
  _CalcMethodDict_map["E"] = ECALCMETHOD::APPROX;
  _CalcMethodDict_map["M"] = ECALCMETHOD::FIX_DATA;
  _CalcMethodDict_map["N"] = ECALCMETHOD::FALSE_DATA;

  _Status_map["N"] = ENAVIGATIONSTATUS::NO_VALID;
  _Status_map["S"] = ENAVIGATIONSTATUS::SIMUL;
  _Status_map["V"] = ENAVIGATIONSTATUS::VALID;
}

UNMEARMCString::~UNMEARMCString()
{
  delete _UTCTime_po;
  delete _Coordinates_po;
  delete _Date_po;
}

void UNMEARMCString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 14) {
    *_UTCTime_po = QTime::fromString(NMEAData_lst[1], "HHmmss.zzz");
    _IsValid_b = (NMEAData_lst[2] == "A");
    _Coordinates_po->setLatitude(FCalculate::latitudeFromStr(NMEAData_lst[3], NMEAData_lst[4]));
    _Coordinates_po->setLongitude(FCalculate::longitudeFromStr(NMEAData_lst[5], NMEAData_lst[6]));
    _Speed_d = NMEAData_lst[7].toDouble();
    _Course_d = NMEAData_lst[8].toDouble();
    *_Date_po = QDate::fromString(NMEAData_lst[9], "ddMMyy");
    _MagneticVariation_d = NMEAData_lst[10].toDouble();
    _IsDirectionWest_b = (NMEAData_lst[11] == "W");
    if (_CalcMethodDict_map.find(NMEAData_lst[12]) != _CalcMethodDict_map.end()) {
      _CalcMethod_en = _CalcMethodDict_map[ NMEAData_lst[12] ];
    }
    if (_Status_map.find(NMEAData_lst[13]) != _Status_map.end()) {
      _Status_en = _Status_map[ NMEAData_lst[13] ];
    }
  }
  qDebug()<<*this;
}

const QTime &UNMEARMCString::utcTime() const
{
  return * _UTCTime_po;
}

bool UNMEARMCString::isValid() const
{
  return _IsValid_b;
}

const QGeoCoordinate &UNMEARMCString::coordinates() const
{
  return * _Coordinates_po;
}

qreal UNMEARMCString::speed() const
{
  return _Speed_d;
}

qreal UNMEARMCString::course() const
{
  return _Course_d;
}

const QDate &UNMEARMCString::date() const
{
  return *_Date_po;
}

qreal UNMEARMCString::magneticVariation() const
{
  return _MagneticVariation_d;
}

bool UNMEARMCString::isDirectionWest() const
{
  return _IsDirectionWest_b;
}

UNMEARMCString::ECALCMETHOD UNMEARMCString::calcMethod() const
{
  return _CalcMethod_en;
}

UNMEARMCString::ENAVIGATIONSTATUS UNMEARMCString::status() const
{
  return _Status_en;
}

QDebug operator<<(QDebug debugObject, const UNMEARMCString & data)
{
  debugObject.nospace()
    << "UNMEAGGAString" << " ("
    << data.utcTime() << ", "
    << data.isValid() << ", "
    << data.coordinates() << ", "
    << data.speed() << ", "
    << data.course() << ", "
    << data.date() << ", "
    << data.magneticVariation() << ", "
    << data.isDirectionWest() << ", "
    << static_cast<int>(data.calcMethod()) << ", "
    << static_cast<int>(data.status())
    << ")";
  return debugObject.space();
}
