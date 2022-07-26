#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAGSTString
 * @brief Data from GST NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGSTString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGSTString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGSTString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


