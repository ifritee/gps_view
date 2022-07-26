#include "UParser.h"

#include <QByteArray>
#include <QDebug>

#include "ANMEAString.h"

UParser::UParser(const QByteArray & parseString)
  : _RawData_po(new QByteArray(parseString))
{
}

UParser::~UParser()
{
  delete _RawData_po;
  delete _NMEAData_po;
}

ANMEAString * UParser::parse()
{
  if (((*_RawData_po)[0]) != '$' && _RawData_po->contains('*')) { // Проверка на корректность строки
    qWarning()<<"NMEA data is not correct (start symbol or stop symbol is not found)";
    return nullptr;
  }
  CConstants constants;
  QString data = constants.subArray(*_RawData_po, '$', '*');
  QString crc = _RawData_po->right(4).left(2);
  if( !constants.isChecksumCorrect(data.toLatin1(), crc.toUInt(nullptr, 16))) {
    qWarning()<<"Check sum of NMEA data is not correct";
    return nullptr;
  }
//  qDebug()<<data.split(",");
  _SetelliteType_en = constants.satelliteTypeByString_en(data);
  _NMEADateType_en = constants.NMEATypeByString_en(data);
  _NMEAData_po = ANMEAString::create(_NMEADateType_en, _SetelliteType_en, data);
  return _NMEAData_po;
}
