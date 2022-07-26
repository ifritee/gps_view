#pragma once

#include "CConstants.h"

class QByteArray;
class ANMEAString;

/**
 * @class UParser
 * @brief The UParser class for parsing raw NMEA string
 * @author Nikishin E. V.
 * @date 23.07.2022 */
class UParser
{
public:
  /**
   * @brief UParser Constructor
   * @param parseString NMEA string */
  explicit UParser(const QByteArray & parseString);
  /** @brief Destuctor */
  virtual ~UParser();
  /** @brief Start NMEA parsing */
  virtual ANMEAString * parse();

private:
  QByteArray * _RawData_po; ///< @brief Saved NMEA string
  ESATELLITETYPE _SetelliteType_en; ///< @brief Satellite type
  ENMEADATATYPE _NMEADateType_en; ///< @brief NMEA data type
  ANMEAString * _NMEAData_po = nullptr; ///< @brief Parsing data from NMEA string
};
