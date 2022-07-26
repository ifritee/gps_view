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
  qDebug()<<NMEAData_lst;
}
