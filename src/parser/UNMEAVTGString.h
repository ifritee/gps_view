#pragma once

#include <map>

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
  explicit UNMEAVTGString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAVTGString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /** @brief return Course over ground, degrees */
  qreal course() const;
  /** @brief return flag of valid data */
  bool isValid() const;
  /** @brief return Course over ground, degrees Magnetic */
  qreal magneticCourse() const;
  /** @brief return magnetic flag */
  bool isMagnetic() const;
  /** @brief return Speed over ground, knots */
  qreal speedN() const;
  /** @brief return Speed over ground, km/hr */
  qreal speedK() const;
  /** @brief return  FAA mode indicator */
  ECALCMETHOD calcMethod() const;

private:
  qreal _Course_d; ///< @brief Course over ground, degrees True
  bool _IsValid_b; ///< @brief  T = True, F = False
  qreal _MagneticCourse_d; ///< @brief  Course over ground, degrees Magnetic
  bool _IsMagnetic_b; ///< @brief  M = Magnetic
  qreal _SpeedN_d; ///< @brief  Speed over ground, knots, N = Knots
  qreal _SpeedK_d;///< @brief  Speed over ground, km/hr
  ECALCMETHOD _CalcMethod_en; ///< @brief  FAA mode indicator (NMEA 2.3 and later)

  std::map<QString, ECALCMETHOD> _CalcMethodDict_map; ///< @brief Hash from key = char, val = calc method
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAVTGString &);
#endif

