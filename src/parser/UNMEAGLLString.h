#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAGLLString
 * @brief Data from GLL NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGLLString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGLLString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGLLString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


