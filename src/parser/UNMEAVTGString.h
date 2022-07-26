#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAVTGString
 * @brief Data from VTG NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAVTGString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAVTGString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAVTGString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;

private:

};


