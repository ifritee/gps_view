#include "UNMEARMCString.h"

#include <QDebug>

UNMEARMCString::UNMEARMCString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::RMC;
}

UNMEARMCString::~UNMEARMCString()
{
}

void UNMEARMCString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
