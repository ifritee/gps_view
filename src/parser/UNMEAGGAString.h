#pragma once

#include "ANMEAString.h"

class QTime;
class QGeoCoordinate;

/**
 * @class UNMEAGGAString
 * @brief Data from GGA NMEA string (last position)
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGGAString : public ANMEAString
{
public:
  /**
   * @enum ECALCMETHOD
   * @brief Coordinate Calculation Method */
  enum class ECALCMETHOD {
    NONE           ///< @brief '0' - недоступно.
  , AUTO           ///< @brief '1' - автономно.
  , DIFF           ///< @brief '2' - дифференциально.
  , PPS            ///< @brief '3' - PPS.
  , FIX_RTK        ///< @brief '4' - фиксированный RTK.
  , NFIX_RTK       ///< @brief '5' - не фиксированный RTK.
  , EXTRAPOLATION  ///< @brief '6' - экстраполяция.
  , FIX_COORD      ///< @brief '7' - фиксированные координаты.
  , SIMUL          ///< @brief '8' - режим симуляции.
  };

  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGGAString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGGAString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return Last coordinates */
  const QGeoCoordinate & coordinates() const;
  /** @brief return Coordinate calculation method */
  ECALCMETHOD calcMethod() const;
  /** @brief return Quantity of active satellites */
  quint32 satellitesQty() const;
  /** @brief return Horizontal dilution of precision */
  qreal hdop() const;
  /** @brief return Altitude in meters */
  qreal altitude() const;
  /** @brief return Means mean-sea-level below ellipsoid */
  qreal meanSeaLevel() const;
  /** @brief return Age of differential GPS data, time in seconds */
  qreal timeout() const;
  /** @brief return Differential reference station ID, 0000-1023 */
  quint32 stationID() const;

private:
  QTime * _UTCTime_po; ///< @brief Time in UTC
  QGeoCoordinate * _Coordinates_po; ///< @brief Last coordinates
  ECALCMETHOD _CalcMethod_en; ///< @brief Coordinate calculation method
  quint32 _SatellitesQty_u; ///< @brief Quantity of active satellites
  qreal _HDOP_d; ///< @brief Horizontal Dilution of Precision
  qreal _Altitude_d; ///< @brief Altitude in meters
  qreal _MeanSeaLevel_d; ///< @brief Means mean-sea-level below ellipsoid
  qreal _Timeout_d; ///< @brief Age of differential GPS data, time in seconds
  quint32 _StationID_u; ///< @brief Differential reference station ID, 0000-1023
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAGGAString &);
#endif


