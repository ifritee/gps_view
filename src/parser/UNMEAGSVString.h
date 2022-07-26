#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAGSVString
 * @brief Data from GSV NMEA string
 * @author Nikishin E. V.
 * @date 25.07.2022 */
class UNMEAGSVString : public ANMEAString
{
public:
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGSVString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGSVString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /**
   * @brief Return quantity of messages */
  quint32 messagesQty() const;
  /**
   * @brief Return message number */
  quint32 messageNumber() const;
  /**
   * @brief Return satellites quantity of message */
  quint32 satellitesQty() const;
  /**
   * @brief Return all satellite's data */
  const std::vector<SGSVSatellitesData> &satellitesData() const;

private:
  quint32 _MessagesQty_u = 0; ///< @brief Quantity of messages
  quint32 _MessageNumber_u = 0; ///< @brief Message number
  quint32 _SatellitesQty_u = 0; ///< @brief Satellites quantity of message
  std::vector<SGSVSatellitesData> _SatellitesData_vec; ///< @brief Array of satellite's data
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAGSVString &);
#endif
