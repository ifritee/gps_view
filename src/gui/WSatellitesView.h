#pragma once

#include <QGraphicsView>
#include <map>

class QGraphicsScene;
class USatelliteItem;
class ANMEAString;

/**
 * @class WSatellitesView
 * @brief The WSatellitesView class GUI view satellites on screen
 * @author Nikishin E. V.
 * @date 30.07.2022 */
class WSatellitesView : public QGraphicsView
{
  Q_OBJECT

  const quint32 RADIUS_DELTA = 24; ///< @brief Delta offset radius
  const quint32 CIRCLE_QTY = 3; ///< @brief Quantity circles on screen
  const quint32 DEGREES_DELTA = 30; ///< @brief Delta offset degreeses

public:
  /** @brief Construcror */
  explicit WSatellitesView(QWidget *parent = nullptr);
  /** @brief Destructor */
  virtual ~WSatellitesView();
  /** @brief Set data for view screen */
  void setViewData_v(ANMEAString *);

protected:
  void resizeEvent(QResizeEvent *event) override final;

private:
  QGraphicsScene * _Scene_po; ///< @brief Draw scene
  std::map<quint32, USatelliteItem *> _SatelliteItems_map; ///< @brief hash from satellites data
};

