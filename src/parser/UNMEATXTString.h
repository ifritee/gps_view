#pragma once

#include "ANMEAString.h"

class QString;

/**
 * @class UNMEATXTString
 * @brief Data from TXT NMEA string
 * @author Nikishin E. V.
 * @date 26.07.2022 */
class UNMEATXTString : public ANMEAString
{
public:

  /**
   * @enum EMESSAGES
   * @brief Messages type numerator */
  enum class EMESSAGETYPE {
    ERROR
  , WARNING
  , INFO
  , USER = 7
  };
  /**
   * @brief Constructor
   * @param text NMEA string */
  explicit UNMEATXTString(ESATELLITETYPE type, const QString & text);
  /**
   * @brief Destructor */
  virtual ~UNMEATXTString();
  /**
   * @brief Run parse NMEA string */
  void parsing() override final;
  /** @brief return Message strings quantity */
  quint32 stringsQty() const;
  /** @brief return Message string number */
  quint32 stringsNumber() const;
  /** @brief return Message type */
  EMESSAGETYPE messageType() const;
  /** @brief return array of messages */
  QString text() const;

private:
  quint32 _StringsQty_u; ///< @brief Message strings quantity
  quint32 _StringsNumber_u; ///< @brief Message string number
  EMESSAGETYPE _MessageType_en; ///< @brief Message type
  QString * _Text_pstr; ///< @brief  messages
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const UNMEATXTString &);
#endif


