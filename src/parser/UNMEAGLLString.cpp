#include "UNMEAGLLString.h"

#include <QDebug>

UNMEAGLLString::UNMEAGLLString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
{
  _NMEADataType_en = ENMEADATATYPE::GLL;
}

UNMEAGLLString::~UNMEAGLLString()
{
}

void UNMEAGLLString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  qDebug()<<NMEAData_lst;
}
