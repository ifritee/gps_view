#pragma once

#include <QGraphicsItem>

#include "CConstants.h"

class SGSVSatellitesData;

/**
 * @class USatelliteItem
 * @brief Graphics item for satellite
 * @author Nikishin E.V.
 * @date 24.07.2022 */
class USatelliteItem : public QGraphicsItem
{
public:
  /** @brief Constructor */
  explicit USatelliteItem(QGraphicsItem *parent = nullptr);
  /** @brief Destructor */
  virtual ~USatelliteItem();
  /** @brief Set new view data */
  void setData_v(ESATELLITETYPE, const SGSVSatellitesData &);
  /** @brief Defines the outer bounds of the item */
  QRectF boundingRect() const override;
  /** @brief Main draw method */
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
  SGSVSatellitesData _GSVData_o; ///< @brief Data of satellite
  ESATELLITETYPE _SatelliteType_en; ///< @brief Satellite type
};

