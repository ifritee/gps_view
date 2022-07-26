#include "UNMEAVTGString.h"

#include <QDebug>

UNMEAVTGString::UNMEAVTGString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::VTG;
}

UNMEAVTGString::~UNMEAVTGString()
{
}

void UNMEAVTGString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
