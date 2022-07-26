#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAGSAString
 * @brief Data from GSA NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGSAString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGSAString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGSAString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


