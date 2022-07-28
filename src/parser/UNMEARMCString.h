#pragma once

#include <map>

#include "ANMEAString.h"
#include "CConstants.h"

class QDate;
class QTime;
class QGeoCoordinate;

/**
 * @class UNMEARMCString
 * @brief Data from RMC NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEARMCString : public ANMEAString
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
   * @enum ENAVIGATIONSTATUS
   * @brief Status of navigation */
  enum class ENAVIGATIONSTATUS {
    NO_VALID  ///< @brief Not valid
  , SIMUL ///< @brief Simulation
  , VALID ///< @brief Valid status
  };

  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEARMCString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEARMCString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /** @brief return Time in UTC */
  const QTime & utcTime() const;
  /** @brief return valid data */
  bool isValid() const;
  /** @brief return Last coordinates */
  const QGeoCoordinate & coordinates() const;
  /** @brief return Speed over ground, knots */
  qreal speed() const;
  /** @brief return Track made good, degrees true */
  qreal course() const;
  /** @brief return date */
  const QDate & date() const;
  /** @brief return Magnetic Variation, degrees */
  qreal magneticVariation() const;
  /** @brief return Eeast (false) or West (true) */
  bool isDirectionWest() const;
  /** @brief return FAA mode indicator */
  ECALCMETHOD calcMethod() const;
  /** @brief return Nav Status (NMEA 4.1 and later) */
  ENAVIGATIONSTATUS status() const;

private:
  QTime * _UTCTime_po; ///< @brief UTC of position fix, hh is hours, mm is minutes, ss.ss is seconds.
  bool _IsValid_b; ///< @brief Status, A = Valid, V = Warning
  QGeoCoordinate * _Coordinates_po; ///< @brief coordinates
  qreal _Speed_d; ///< @brief Speed over ground, knots
  qreal _Course_d; ///< @brief Track made good, degrees true
  QDate * _Date_po; ///< @brief Date, ddmmyy
  qreal _MagneticVariation_d; ///< @brief Magnetic Variation, degrees
  bool _IsDirectionWest_b; ///< @brief E or W
  ECALCMETHOD _CalcMethod_en; ///< @brief FAA mode indicator (NMEA 2.3 and later)
  ENAVIGATIONSTATUS _Status_en; ///< @brief Nav Status (NMEA 4.1 and later) A=autonomous, D=differential, E=Estimated, M=Manual input mode N=not valid, S=Simulator, V = Valid

  std::map<QString, ECALCMETHOD> _CalcMethodDict_map; ///< @brief Hash from key = char, val = calc method
  std::map<QString, ENAVIGATIONSTATUS> _Status_map; ///< @brief Hash from key = char, val = status
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEARMCString &);
#endif

