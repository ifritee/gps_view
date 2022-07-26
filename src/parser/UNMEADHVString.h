#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEADHVString
 * @brief Data from DHV NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEADHVString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEADHVString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEADHVString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


