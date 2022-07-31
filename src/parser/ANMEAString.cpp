#include "ANMEAString.h"

#include <QDebug>

#include "UNMEAGGAString.h"
#include "UNMEAGLLString.h"
#include "UNMEAGSAString.h"
#include "UNMEAGSVString.h"
#include "UNMEARMCString.h"
#include "UNMEAVTGString.h"
#include "UNMEAZDAString.h"
#include "UNMEADHVString.h"
#include "UNMEAGSTString.h"
#include "UNMEATXTString.h"

ANMEAString::ANMEAString(ESATELLITETYPE type, const QString & text)
  : _NMEAText_pstr(new QString(text))
  , _SatelliteType_en(type)
{

}

ANMEAString::~ANMEAString()
{
  delete _NMEAText_pstr;
}

ANMEAString *ANMEAString::create(ENMEADATATYPE dataType, ESATELLITETYPE satelliteType, const QString & text)
{
  ANMEAString * nmea = nullptr;
  if (dataType == ENMEADATATYPE::GGA) nmea = new UNMEAGGAString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::GLL) nmea = new UNMEAGLLString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::GSA) nmea = new UNMEAGSAString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::GSV) nmea = new UNMEAGSVString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::RMC) nmea = new UNMEARMCString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::VTG) nmea = new UNMEAVTGString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::ZDA) nmea = new UNMEAZDAString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::DHV) nmea = new UNMEADHVString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::GST) nmea = new UNMEAGSTString(satelliteType, text);
  else if (dataType == ENMEADATATYPE::TXT) nmea = new UNMEATXTString(satelliteType, text);

  if (nmea) { nmea->parsing(); }
  else {
    qWarning()<<"NO parser: "<<text;
  }
  return nmea;
}

ESATELLITETYPE ANMEAString::satelliteType_en() const
{
  return _SatelliteType_en;
}

ENMEADATATYPE ANMEAString::nmeaDataType_en() const
{
  return _NMEADataType_en;
}
