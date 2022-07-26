#pragma once

class QString;

class FCalculate
{
public:
  FCalculate();
  /**
   * @brief latitudeFromStr Convert string (format "5546.95900" = 55°46.959' = 55.78265°)
   * @param degrees "DDMM.MMMMM"
   * @param direction N - north, S - south
   * @return degrees DD.DDDDD */
  static double latitudeFromStr(const QString & degrees, const QString & direction);
  /**
   * @brief longitudeFromStr Convert string (format "5546.95900" = 55°46.959' = 55.78265°)
   * @param degrees "DDDMM.MMMMM"
   * @param direction E - east, W - west
   * @return degrees DDD.DDDDD */
  static double longitudeFromStr(const QString & degrees, const QString & direction);
  /**
   * @brief altitude Convert string (format "XXX.YY")
   * @param altitude "XXX.YY"
   * @param unit M - meters
   * @return degrees DDD.DDDDD */
  static double altitudeFromStr(const QString & altitude, const QString & unit);
};

