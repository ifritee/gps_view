#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEARMCString
 * @brief Data from RMC NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEARMCString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEARMCString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEARMCString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


