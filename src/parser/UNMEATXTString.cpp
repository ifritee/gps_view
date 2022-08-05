#include "UNMEATXTString.h"

#include <QString>
#include <QDebug>

UNMEATXTString::UNMEATXTString(ESATELLITETYPE type, const QString & text)
  : ANMEAString(type, text)
  , _Text_pstr(new QString)
{
  _NMEADataType_en = ENMEADATATYPE::TXT;
}

UNMEATXTString::~UNMEATXTString()
{
  delete _Text_pstr;
}

void UNMEATXTString::parsing()
{
  QStringList NMEAData_lst = _NMEAText_pstr->split(",");
  if (NMEAData_lst.size() >= 4) {
    _StringsQty_u = NMEAData_lst[1].toUInt();
    _StringsNumber_u = NMEAData_lst[2].toUInt();
    _MessageType_en = static_cast<EMESSAGETYPE>(NMEAData_lst[3].toUInt());
    *_Text_pstr = NMEAData_lst[4];
  }
  qDebug()<<*this;
}

quint32 UNMEATXTString::stringsQty() const
{
  return _StringsQty_u;
}

quint32 UNMEATXTString::stringsNumber() const
{
  return _StringsNumber_u;
}

UNMEATXTString::EMESSAGETYPE UNMEATXTString::messageType() const
{
  return _MessageType_en;
}

QString UNMEATXTString::text() const
{
  return *_Text_pstr;
}

QDebug operator<<(QDebug debugObject, const UNMEATXTString & data)
{
  debugObject.nospace()
    << "UNMEATXTString" << " ("
    << data.stringsQty() << ", "
    << data.stringsNumber() << ", "
    << static_cast<int>(data.messageType()) << ", "
    << data.text()
    << ")";
  return debugObject.space();
}
