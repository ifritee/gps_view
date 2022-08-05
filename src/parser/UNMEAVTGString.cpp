#include "UNMEAVTGString.h"

#include <QDebug>

UNMEAVTGString::UNMEAVTGString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::VTG;

  _CalcMethodDict_map["A"] = ECALCMETHOD::AUTO;
  _CalcMethodDict_map["D"] = ECALCMETHOD::DIFF;
  _CalcMethodDict_map["E"] = ECALCMETHOD::APPROX;
  _CalcMethodDict_map["M"] = ECALCMETHOD::FIX_DATA;
  _CalcMethodDict_map["N"] = ECALCMETHOD::FALSE_DATA;
}

UNMEAVTGString::~UNMEAVTGString()
{
}

void UNMEAVTGString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 9) {
    _Course_d = NMEAData_lst[1].toDouble();
    _IsValid_b = (NMEAData_lst[2] == "T");
    _MagneticCourse_d = NMEAData_lst[3].toDouble();
    _IsMagnetic_b = (NMEAData_lst[4] == "M");
    _SpeedN_d = NMEAData_lst[5].toDouble();
    _SpeedK_d = NMEAData_lst[7].toDouble();
    if (NMEAData_lst.size() >= 10 && _CalcMethodDict_map.find(NMEAData_lst[9]) != _CalcMethodDict_map.end()) {
      _CalcMethod_en = _CalcMethodDict_map[ NMEAData_lst[9] ];
    }
  }
  qDebug()<<*this;
}

qreal UNMEAVTGString::course() const
{
  return _Course_d;
}

bool UNMEAVTGString::isValid() const
{
  return _IsValid_b;
}

qreal UNMEAVTGString::magneticCourse() const
{
  return _MagneticCourse_d;
}

bool UNMEAVTGString::isMagnetic() const
{
  return _IsMagnetic_b;
}

qreal UNMEAVTGString::speedN() const
{
  return _SpeedN_d;
}

qreal UNMEAVTGString::speedK() const
{
  return _SpeedK_d;
}

UNMEAVTGString::ECALCMETHOD UNMEAVTGString::calcMethod() const
{
  return _CalcMethod_en;
}

QDebug operator<<(QDebug debugObject, const UNMEAVTGString & data)
{
  debugObject.nospace()
    << "UNMEAVTGString" << " ("
    << data.course() << ", "
    << data.isValid() << ", "
    << data.magneticCourse() << ", "
    << data.isMagnetic() << ", "
    << data.speedN() << ", "
    << data.speedK() << ", "
    << static_cast<int>(data.calcMethod())
    << ")";
  return debugObject.space();
}
