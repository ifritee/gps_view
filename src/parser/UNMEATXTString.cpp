#include "UNMEATXTString.h"

#include <QDebug>

UNMEATXTString::UNMEATXTString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::TXT;
}

UNMEATXTString::~UNMEATXTString()
{
}

void UNMEATXTString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
