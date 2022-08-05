#include "UNMEAGSTString.h"

#include <QTime>
#include <QDebug>

UNMEAGSTString::UNMEAGSTString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _UTCTime_po(new QTime)
{
  _NMEADataType_en = ENMEADATATYPE::GST;
}

UNMEAGSTString::~UNMEAGSTString()
{
  delete _UTCTime_po;
}

void UNMEAGSTString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 9) {
    *_UTCTime_po = QTime::fromString(NMEAData_lst[1], "HHmmss.zzz");
    _RMS_d = NMEAData_lst[2].toDouble();
    _ErrorSemiMajor_d = NMEAData_lst[3].toDouble();
    _ErrorSemiMinor_d = NMEAData_lst[4].toDouble();
    _ErrorSMajorOrientation_d = NMEAData_lst[5].toDouble();
    _ErrorLatitude_d = NMEAData_lst[6].toDouble();
    _ErrorLongitude_d = NMEAData_lst[7].toDouble();
    _ErrorAltitude_d = NMEAData_lst[8].toDouble();
  }
  qDebug()<<*this;
}

const QTime &UNMEAGSTString::utcTime() const
{
  return *_UTCTime_po;
}

qreal UNMEAGSTString::rms() const
{
  return _RMS_d;
}

qreal UNMEAGSTString::errorSemiMajor() const
{
  return _ErrorSemiMajor_d;
}

qreal UNMEAGSTString::errorSemiMinor() const
{
  return _ErrorSemiMinor_d;
}

qreal UNMEAGSTString::errorSMajorOrientation() const
{
  return _ErrorSMajorOrientation_d;
}

qreal UNMEAGSTString::errorLatitude() const
{
  return _ErrorLatitude_d;
}

qreal UNMEAGSTString::errorLongitude() const
{
  return _ErrorLongitude_d;
}

qreal UNMEAGSTString::errorAltitude() const
{
  return _ErrorAltitude_d;
}

QDebug operator<<(QDebug debugObject, const UNMEAGSTString & data)
{
  debugObject.nospace()
    << "UNMEAGSTString" << " ("
    << data.utcTime() << ", "
    << data.rms() << ", "
    << data.errorSemiMajor() << ", "
    << data.errorSemiMinor() << ", "
    << data.errorSMajorOrientation() << ", "
    << data.errorLatitude() << ", "
    << data.errorLongitude() << ", "
    << data.errorAltitude()
    << ")";
  return debugObject.space();
}
