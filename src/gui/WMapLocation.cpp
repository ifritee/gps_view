#include "WMapLocation.h"

#include <QDebug>
#include <QQuickView>
#include <QQmlContext>
#include <QVBoxLayout>

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
