#pragma once

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
  class DSettings;
}

class DSettings : public QDialog
{
  Q_OBJECT

public:
  explicit DSettings(QWidget *parent = nullptr);
  ~DSettings();
  QString portName();
  int boundRate();
  QSerialPort::DataBits dataBits();
  QSerialPort::Parity parity();
  QSerialPort::StopBits stopBits();
  QSerialPort::FlowControl flowControl();

private:
  Ui::DSettings *ui;

public slots:
  void Save_slt();
  void Load_slt();

private slots:
  void RefreshPorts_slt();
};

