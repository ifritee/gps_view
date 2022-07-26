#include "FCalculate.h"

#include <QString>

FCalculate::FCalculate()
{

}

double FCalculate::latitudeFromStr(const QString &degrees, const QString &direction)
{
  qreal deg = degrees.left(2).toDouble();
  qreal min = degrees.right(degrees.size() - 2).toDouble() / 60.0;
  return direction == "S" ? -(deg + min) : deg + min;
}

double FCalculate::longitudeFromStr(const QString &degrees, const QString &direction)
{
  qreal deg = degrees.left(3).toDouble();
  qreal min = degrees.right(degrees.size() - 3).toDouble() / 60.0;
  return direction == "W" ? -(deg + min) : deg + min;
}

double FCalculate::altitudeFromStr(const QString &altitude, const QString &unit)
{
  qreal factor = 1.0;
  if (unit == "M") {
    factor = 1.0;
  }
  return altitude.toDouble() * factor;
}

