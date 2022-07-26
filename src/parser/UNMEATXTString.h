#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEATXTString
 * @brief Data from TXT NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEATXTString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEATXTString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEATXTString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


