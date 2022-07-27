#pragma once


#include "ANMEAString.h"

class QTime;
class QVector3D;

/**
 * @class UNMEADHVString
 * @brief Data from DHV NMEA string (speed)
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
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return Speed 3D m/s */
  qreal speed3D() const;
  /** @brief return Speed ECEF (X, Y, Z) in m/s */
  const QVector3D & speedECEF() const;
  /** @brief return Speed in m/s */
  qreal speed() const;


private:
  QTime * _UTCTime_po; ///< @brief Time in UTC
  qreal _Speed3D_d; ///< @brief Speed 3D m/s
  QVector3D * _SpeedECEF_po; ///< @brief Speed ECEF m/s
  qreal _Speed_d; ///< @brief Speed in m/s
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEADHVString &);
#endif


