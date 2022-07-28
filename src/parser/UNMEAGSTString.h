#pragma once

#include "ANMEAString.h"

class QTime;

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
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return Total RMS standard deviation of ranges */
  qreal rms() const;
  /** @brief return Standard deviation (meters) of semi-major */
  qreal errorSemiMajor() const;
  /** @brief return Standard deviation (meters) of semi-minor */
  qreal errorSemiMinor() const;
  /** @brief return Orientation of semi-major axis of error ellipse */
  qreal errorSMajorOrientation() const;
  /** @brief return Standard deviation (meters) of latitude error */
  qreal errorLatitude() const;
  /** @brief return Standard deviation (meters) of longitude error */
  qreal errorLongitude() const;
  /** @brief return Standard deviation (meters) of altitude error */
  qreal errorAltitude() const;

private:
  QTime * _UTCTime_po; ///< @brief TC time of associated GGA fix in UTC
  qreal _RMS_d; ///< @brief Total RMS standard deviation of ranges inputs to the navigation solution
  qreal _ErrorSemiMajor_d; ///< @brief Standard deviation (meters) of semi-major axis of error ellipse
  qreal _ErrorSemiMinor_d; ///< @brief Standard deviation (meters) of semi-minor axis of error ellipse
  qreal _ErrorSMajorOrientation_d; ///< @brief Orientation of semi-major axis of error ellipse (true north degrees)
  qreal _ErrorLatitude_d; ///< @brief Standard deviation (meters) of latitude error
  qreal _ErrorLongitude_d; ///< @brief Standard deviation (meters) of longitude error
  qreal _ErrorAltitude_d; ///< @brief Standard deviation (meters) of altitude error
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAGSTString &);
#endif
