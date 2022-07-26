#include "WSatellitesView.h"

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <cmath>

#include "UNMEAGSVString.h"
#include "USatelliteItem.h"

WSatellitesView::WSatellitesView(QWidget *parent)
  : QGraphicsView(parent)
  , _Scene_po(new QGraphicsScene)
{
  //----- Немного поднастроим отображение виджета и его содержимого -----
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
  this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
  //----- Также зададим минимальные размеры виджета -----
  this->setMinimumHeight(100);
  this->setMinimumWidth(100);

  setScene(_Scene_po);
  setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

WSatellitesView::~WSatellitesView()
{
  foreach( QGraphicsItem *item, _Scene_po->items(_Scene_po->sceneRect())) {
    delete item;
  }
  _SatelliteItems_map.clear();
  delete _Scene_po;
}

void WSatellitesView::setViewData_v(ANMEAString * data)
{
  UNMEAGSVString * gsv = dynamic_cast<UNMEAGSVString *>(data);
  if (gsv) {
    const std::vector<SGSVSatellitesData> & satellites =  gsv->satellitesData();
    qreal radius = width() > height() ? height() / 2 - RADIUS_DELTA : width() / 2 - RADIUS_DELTA;
    for ( const SGSVSatellitesData & sat : satellites) {
      if (_SatelliteItems_map.find(sat._IDSatellite_u) == _SatelliteItems_map.end()) {
        _SatelliteItems_map[sat._IDSatellite_u] = new USatelliteItem;
        _Scene_po->addItem(_SatelliteItems_map[sat._IDSatellite_u]);
      }
      USatelliteItem * item = _SatelliteItems_map[sat._IDSatellite_u];
      qreal px = (90.0 - sat._Angle_u) * radius / 90.0;
      qreal x = std::sin(sat._Azimuth_u * M_PI / 180.0) * px;
      qreal y = -std::cos(sat._Azimuth_u * M_PI / 180.0) * px;
      item->setPos(x, y);
      item->setData_v(gsv->satelliteType_en(), sat);
    }
  }
}

void WSatellitesView::resizeEvent(QResizeEvent *event)
{
  QGraphicsView::resizeEvent(event);
  QTimer::singleShot(500, [this]() {
    foreach( QGraphicsItem *item, _Scene_po->items(_Scene_po->sceneRect())) {
      delete item;
    }
    _SatelliteItems_map.clear();
    _Scene_po->setSceneRect(-width() / 2, -height() / 2, width(), height());
    _Scene_po->setBackgroundBrush(Qt::black);
    qreal radius = width() > height() ? height() / 2 - RADIUS_DELTA : width() / 2 - RADIUS_DELTA;
    qreal radiusDigit = radius / CIRCLE_QTY;
    QPen linePen(QBrush(Qt::gray), 1);
    for (quint32 i = 1; i <= CIRCLE_QTY; ++i) {
      _Scene_po->addEllipse(-radiusDigit * i , -radiusDigit * i, (radiusDigit * i) * 2, (radiusDigit * i) * 2, linePen);
    }
    for(int i = 0; i < 360; i += DEGREES_DELTA) {
      _Scene_po->addLine(0, 0, std::sin(i * M_PI / 180.0) * radius, std::cos(i * M_PI / 180.0) * radius, linePen);
    }
  });
}
