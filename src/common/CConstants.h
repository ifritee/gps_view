#pragma once

#include <map>

#include <QString>
#include <QColor>

const constexpr char * SETTINGS_FILENAME = "gps_view.conf";
const constexpr char * SETTINGS_RS232 = "rs232";
const constexpr char * SETTINGS_PORTNAME = "portname";
const constexpr char * SETTINGS_BOUNDRATE = "boundrate";
const constexpr char * SETTINGS_DATABITS = "databits";
const constexpr char * SETTINGS_PARITY = "parity";
const constexpr char * SETTINGS_STOPBITS = "stopbits";
const constexpr char * SETTINGS_FLOWCONTROL = "flowcontrol";

/**
 * @enum ESATELLITETYPE
 * @brief Тип спутников */
enum class ESATELLITETYPE {
  NONE
, GP /// < @brief информация получена от спутников GPS (США).
, GL /// < @brief информация получена от спутников Глонасс (Россия).
, GA /// < @brief информация получена от спутников Galileo (Европа).
, BD /// < @brief информация получена от спутников Beidou (Китай).
, GQ /// < @brief информация получена от спутников QZSS (Япония).
, GN /// < @brief информация получена от спутников разных навигационных систем.
};

/**
 * @enum ENMEADATA
 * @brief Типы данных NMEA
 */
enum class ENMEADATATYPE {
  NONE
, GGA ///< @brief Данные о последнем зафиксированном местоположении.
, GLL ///< @brief Географические координаты.
, GSA ///< @brief Информация об активных спутниках (участвующих в позиционировании).
, GSV ///< @brief Информация о всех наблюдаемых спутниках.
, RMC ///< @brief Рекомендуемый минимум навигационных данных.
, VTG ///< @brief Скорость и курс относительно земли.
, ZDA ///< @brief Дата и время.
, DHV ///< @brief Информация о скорости движения GNSS приемника.
, GST ///< @brief Статистика ошибок позиционирования.
, TXT ///< @brief Текстовое сообщение.
};

/** @brief информация о наблюдаемом спутнике */
struct SGSVSatellitesData {
  quint32 _IDSatellite_u; ///< @brief ID спутника (от 1 до 255). ID не может быть равен '0'
  quint32 _Angle_u; ///< @brief Угол возвышения спутника относительно модуля, в градусах ("00"-горизонт / "90"-зенит)
  quint32 _Azimuth_u; ///< @brief Азимут положения спутника относительно модуля, в градусах ("000" - "360")
  quint32 _SNR_u; ///< @brief Уровень сигнала SNR (отношение сигнал/шум) в дБ ("00" - "99")
};

class CConstants
{
public:
  CConstants();
  /** @brief Возвращает тип спутника по строке */
  ESATELLITETYPE satelliteTypeByString_en(const QString &);
  /** @brief Возвращает тип NMEA данных по строке */
  ENMEADATATYPE NMEATypeByString_en(const QString &);
  /**
   * @brief subArray Обрабатывает строку и выделяет первое совподение (@ref begin; @ref end)
   * @param array Начальная строка
   * @param begin Символ начала данных
   * @param end Символ конца данных
   * @return Возвращает подстроку */
  QByteArray subArray(const QByteArray & array, QChar begin, QChar end);
  /**
   * @brief isChecksumCorrect Проверяет контрольную сумму набора байт из строки NMEA
   * @param data Набор данных
   * @param crc Предполагаемая контрольная сумма
   * @return true - совпадение */
  bool isChecksumCorrect(const QByteArray & data, quint32 crc);

  /** @brief Возвращает цвет по С/Ш */
  static QColor colorBySNR(quint32 snr);

private:
  std::map<QString, ESATELLITETYPE> _SatelliteTypes_map; ///< @brief Набор типов по строкам
  std::map<QString, ENMEADATATYPE> _NMEADataTypes_map; ///< @brief Набор типов NMEA по строкам
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug, const SGSVSatellitesData &);
#endif
