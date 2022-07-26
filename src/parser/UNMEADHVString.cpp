#include "UNMEADHVString.h"

#include <QDebug>

UNMEADHVString::UNMEADHVString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::DHV;
}

UNMEADHVString::~UNMEADHVString()
{
}

void UNMEADHVString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
