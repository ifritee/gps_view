#pragma once

#include <vector>

#include "ANMEAString.h"

/**
 * @class UNMEAGSAString
 * @brief Data from GSA NMEA string (active satellites)
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEAGSAString : public ANMEAString
{
public:

  /**
   * @enum EFORMAT
   * @brief The format mode */
  enum class EFORMAT {
    NONE
  , FORMAT_NO = 1 ///< @brief No format
  , FORMAT_2D     ///< @brief 2D format
  , FORMAT_3D     ///< @brief 3D format
  };

  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEAGSAString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEAGSAString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /** @brief return is auto mode*/
  bool isAuto() const;
  /** @brief return Mode format*/
  EFORMAT format() const;
  /** @brief return active satellites*/
  const std::vector<quint32> & satellitesID() const;
  /** @brief return Factor PDOP */
  qreal PDOP() const;
  /** @brief return Factor HDOP horizontal */
  qreal HDOP() const;
  /** @brief return Factor VDOP vertical */
  qreal VDOP() const;
  /** @brief return Navigation system type */
  ESATELLITETYPE naviType() const;

private:
  bool _IsAuto_b; ///< @brief is auto mode
  EFORMAT _Format_en; ///< @brief Mode format
  std::vector<quint32> _SatellitesID_vec; ///< @brief active satellites
  qreal _PDOP_d; ///< @brief Factor PDOP
  qreal _HDOP_d; ///< @brief Factor HDOP horizontal
  qreal _VDOP_d; ///< @brief Factor VDOP vertical
  ESATELLITETYPE _NaviType_en; ///< @brief Navigation system type
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEAGSAString &);
#endif

