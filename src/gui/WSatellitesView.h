#pragma once

#include <QGraphicsView>
#include <map>

class QGraphicsScene;
class USatelliteItem;
class ANMEAString;

class WSatellitesView : public QGraphicsView
{
  Q_OBJECT

  const quint32 RADIUS_DELTA = 24;
  const quint32 CIRCLE_QTY = 3;
  const quint32 DEGREES_DELTA = 30;

public:
  explicit WSatellitesView(QWidget *parent = nullptr);
  virtual ~WSatellitesView();
  /** @brief Set data for view screen */
  void setViewData_v(ANMEAString *);

protected:
  void resizeEvent(QResizeEvent *event) override final;

private:
  QGraphicsScene * _Scene_po; ///< @brief Draw scene
  std::map<quint32, USatelliteItem *> _SatelliteItems_map; ///< @brief hash from satellites data
};

