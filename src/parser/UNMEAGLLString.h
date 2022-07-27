#pragma once

#include <map>

#include "ANMEAString.h"

class QGeoCoordinate;
class QTime;

/**
 * @class UNMEAGLLString
 * @brief Data from GLL NMEA string (geo coordinates)
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGLLString : public ANMEAString
{
public:

  /**
   * @enum ECALCMETHOD
   * @brief Coordinate Calculation Method */
  enum class ECALCMETHOD {
    NONE        ///< @brief '0' - недоступно
  , AUTO        ///< @brief 'A' - автономный
  , DIFF        ///< @brief 'D' - дифференциальный
  , APPROX      ///< @brief 'E' - аппроксимация
  , FIX_DATA    ///< @brief 'M' - фиксированные данные
  , FALSE_DATA  ///< @brief 'N' - недостоверные данные
  };
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
  /** @brief return Last coordinates */
  const QGeoCoordinate & coordinates() const;
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return Data's is reliability */
  bool isReliability() const;
  /** @brief return Coordinate calculation method */
  ECALCMETHOD calcMethod() const;

private:
  QGeoCoordinate * _Coordinates_po; ///< @brief Last coordinates
  QTime * _UTCTime_po; ///< @brief Time in UTC
  bool _IsReliability_b; ///< @brief Data's is reliability
  ECALCMETHOD _CalcMethod_en; ///< @brief Coordinate calculation method
  std::map<QString, ECALCMETHOD> _CalcMethodDict_map; ///< @brief Hash from key = char, val = calc method
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAGLLString &);
#endif

