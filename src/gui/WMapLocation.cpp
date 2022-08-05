#include "WMapLocation.h"

#include <QDebug>
#include <QQuickView>
#include <QQmlContext>
#include <QVBoxLayout>
#include <QGeoCoordinate>

#include "UNMEAGGAString.h"

WMapLocation::WMapLocation(QWidget *parent)
  : QWidget(parent)
  , _View_po(new QQuickView)
{
  QWidget * Container_po = createWindowContainer(_View_po, this);
  this->setLayout(new QVBoxLayout);
  layout()->addWidget(Container_po);
  layout()->setMargin(0);
  Container_po->setFocusPolicy(Qt::TabFocus);
  QQmlContext * context = _View_po->rootContext();
  context->setContextProperty("maplocation", this);
  _View_po->setSource(QUrl("qrc:/ui/WMapLocation.qml"));
  _View_po->setResizeMode(QQuickView::SizeRootObjectToView);
  Container_po->setAutoFillBackground(true);
  /*QQuickItem * item = */_View_po->rootObject();
}

WMapLocation::~WMapLocation()
{
  delete _View_po;
}

void WMapLocation::setViewData_v(ANMEAString * data)
{
  if (data->nmeaDataType_en() == ENMEADATATYPE::GGA) {
    UNMEAGGAString * gga = dynamic_cast<UNMEAGGAString *>(data);
    if (!gga) { qWarning()<<"Not GGA by type is GGA"; }
    else if (gga->coordinates().isValid()) {
      emit position(gga->coordinates());
    }
  }
}
