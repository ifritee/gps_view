#include "DSettings.h"

#include <QFile>
#include <QSettings>
#include <QStandardPaths>

#include "CConstants.h"
#include "ui_DSettings.h"

DSettings::DSettings(QWidget *parent)
: QDialog(parent)
, ui(new Ui::DSettings)
{
  ui->setupUi(this);

  connect(ui->refresh_pb, &QPushButton::clicked, this, &DSettings::RefreshPorts_slt);
}

DSettings::~DSettings()
{
  delete ui;
}

QString DSettings::portName()
{
  if (ui->avaiblePorts_cb->currentText().isEmpty()) {
    RefreshPorts_slt();
  }
  return ui->avaiblePorts_cb->currentText();
}

int DSettings::boundRate()
{
  return ui->boundRates_cb->currentText().toInt();
}

QSerialPort::DataBits DSettings::dataBits()
{
  return static_cast<QSerialPort::DataBits>(ui->dataBits_cb->currentIndex());
}

QSerialPort::Parity DSettings::parity()
{
  return static_cast<QSerialPort::Parity>(ui->parity_cb->currentIndex() > 0 ? ui->parity_cb->currentIndex() + 1 : 0);
}

QSerialPort::StopBits DSettings::stopBits()
{
  return static_cast<QSerialPort::StopBits>(ui->stopBits_cb->currentIndex() + 1);
}

QSerialPort::FlowControl DSettings::flowControl()
{
  return static_cast<QSerialPort::FlowControl>(ui->flowControls_cb->currentIndex());
}

void DSettings::Save_slt()
{
  QSettings settings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/" + SETTINGS_FILENAME, QSettings::NativeFormat);
  settings.beginGroup(SETTINGS_RS232);
  settings.setValue(SETTINGS_PORTNAME, portName());
  settings.setValue(SETTINGS_BOUNDRATE, ui->boundRates_cb->currentText());
  settings.setValue(SETTINGS_DATABITS, ui->dataBits_cb->currentText());
  settings.setValue(SETTINGS_PARITY, ui->parity_cb->currentText());
  settings.setValue(SETTINGS_STOPBITS, ui->stopBits_cb->currentText());
  settings.setValue(SETTINGS_FLOWCONTROL, ui->flowControls_cb->currentText());
  settings.endGroup();
}

void DSettings::Load_slt()
{
  portName();
  QSettings settings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/" + SETTINGS_FILENAME, QSettings::NativeFormat);
  QString rs232(SETTINGS_RS232);
  ui->avaiblePorts_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_PORTNAME).toString());
  ui->boundRates_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_BOUNDRATE).toString());
  ui->dataBits_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_DATABITS).toString());
  ui->parity_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_PARITY).toString());
  ui->stopBits_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_STOPBITS).toString());
  ui->flowControls_cb->setCurrentText(settings.value(rs232 + "/" + SETTINGS_FLOWCONTROL).toString());
}

void DSettings::RefreshPorts_slt()
{
  ui->avaiblePorts_cb->clear();
  foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    ui->avaiblePorts_cb->addItem(info.portName());
  }
}
