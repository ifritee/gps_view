#include "UNMEAGSTString.h"

#include <QDebug>

UNMEAGSTString::UNMEAGSTString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::GST;
}

UNMEAGSTString::~UNMEAGSTString()
{
}

void UNMEAGSTString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
