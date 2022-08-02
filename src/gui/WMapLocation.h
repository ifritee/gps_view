#pragma once

#include <QWidget>

class QQuickView;

class WMapLocation : public QWidget
{
  Q_OBJECT

public:
  explicit WMapLocation(QWidget *parent = nullptr);
  virtual ~WMapLocation();

private:
  QQuickView *_View_po; ///< @brief Визуализация QML

};

