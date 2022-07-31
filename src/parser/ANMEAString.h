#pragma once

#include "CConstants.h"

/**
 * @class ANMEAString
 * @brief Abstraction parsing data from NMEA string
 * @author Nikishin E. V.
 * @date 24.07.2022 */
class ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param type Satellite type
   * @param text NMEA string */
  explicit ANMEAString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~ANMEAString();
  /**
   * @brief Run parse NMEA string */
  virtual void parsing() = 0;
  /**
   * @brief create obgect child abstract ANMEAString
   * @return new object */
  static ANMEAString * create(ENMEADATATYPE dataType, ESATELLITETYPE satelliteType, const QString & text);
  /** @brief return satellite type */
  ESATELLITETYPE satelliteType_en() const;
  /** @brief return NMEA data type */
  ENMEADATATYPE nmeaDataType_en() const;

protected:
  ENMEADATATYPE _NMEADataType_en; ///< @brief NMEA data
  QString * _NMEAText_pstr; ///< @brief Raw string of NMEA

private:
  ESATELLITETYPE _SatelliteType_en; ///< @brief Satellite type

};

