#include "UNMEAZDAString.h"

#include <QDebug>

UNMEAZDAString::UNMEAZDAString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::ZDA;
}

UNMEAZDAString::~UNMEAZDAString()
{
}

void UNMEAZDAString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
