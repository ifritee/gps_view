#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAZDAString
 * @brief Data from ZDA NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAZDAString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAZDAString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAZDAString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


