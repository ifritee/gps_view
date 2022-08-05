#pragma once

#include <QWidget>

class QQuickView;
class QGeoCoordinate;
class ANMEAString;

class WMapLocation : public QWidget
{
  Q_OBJECT

public:
  explicit WMapLocation(QWidget *parent = nullptr);
  virtual ~WMapLocation();
  /** @brief Set data for view screen */
  void setViewData_v(ANMEAString * );

private:
  QQuickView *_View_po; ///< @brief Визуализация QML

signals:
  /** @brief Set coordinates*/
  void position(const QGeoCoordinate & coord);

};

