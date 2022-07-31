#include "WGeneralData.h"

#include <QTime>
#include <QTimeZone>
#include <QGeoCoordinate>
#include <QDebug>

#include "UNMEAZDAString.h"
#include "UNMEAGGAString.h"
#include "ui_WGeneralData.h"

WGeneralData::WGeneralData(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::WGeneralData)
  , _TimeZone_po(new QTimeZone)
{
  ui->setupUi(this);
}

WGeneralData::~WGeneralData()
{
  delete ui;
  delete _TimeZone_po;
}

void WGeneralData::setViewData_v(ANMEAString * data)
{
  if (data->nmeaDataType_en() == ENMEADATATYPE::ZDA) {
    UNMEAZDAString * zda = dynamic_cast<UNMEAZDAString *>(data);
    if (!zda) { qWarning()<<"Not ZDA by type is ZDA"; }
    else { viewZDAData(*zda); }
  } else if (data->nmeaDataType_en() == ENMEADATATYPE::GGA) {
    UNMEAGGAString * gga = dynamic_cast<UNMEAGGAString *>(data);
    if (!gga) { qWarning()<<"Not GGA by type is GGA"; }
    else { viewGGAData(*gga); }
  }
}

void WGeneralData::viewZDAData(const UNMEAZDAString & zda)
{
//  ui->time->setText(zda.utcTime().toString("hh:mm:ss"));
  *_TimeZone_po = QTimeZone(zda.zoneHours() * 3600 + zda.zoneMinuts() * 60);
  if (zda.date().isValid()) {
    ui->date->setText(zda.date().toString("dd-MM-yyyy"));
  }
}

void WGeneralData::viewGGAData(const UNMEAGGAString & gga)
{
  if (gga.utcTime().isValid()) {
    QTime time = gga.utcTime();
    ui->time->setText(time.toString("hh:mm:ss"));
  }
  if (gga.coordinates().isValid()) {
    QStringList list = gga.coordinates().toString(QGeoCoordinate::DegreesMinutesSeconds).split(",");
    if (list.size() == 2) {
      ui->latitude->setText(list[0]);
      ui->longitude->setText(list[1]);
    }
  }
}
