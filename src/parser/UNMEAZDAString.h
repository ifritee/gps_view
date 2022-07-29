#pragma once

#include "ANMEAString.h"

class QTime;
class QDate;

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
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return Date */
  const QDate & date() const;
  /** @brief return Local zone description */
  qint32 zoneHours() const;
  /** @brief return Local zone minutes description */
  qint32 zoneMinuts() const;

private:
  QTime * _UTCTime_po; ///< @brief Time in UTC
  QDate * _Date_po; ///< @brief Date
  qint32 _ZoneHours_i; ///< @brief Local zone description, 00 to +- 13 hours
  qint32 _ZoneMinuts_i; ///< @brief Local zone minutes description, 00 to 59, apply same sign as local hours
};


#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAZDAString &);
#endif

