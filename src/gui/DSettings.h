#pragma once

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
  class DSettings;
}

/**
 * @class DSettings
 * @brief GUI settings dialog. Includes rs232 options.
 * @author Nikishin E. V.
 * @date 29.07.2022 */
class DSettings : public QDialog
{
  Q_OBJECT

public:
  /** @brief Constructor */
  explicit DSettings(QWidget *parent = nullptr);
  /** @brief Destructor */
  virtual ~DSettings();
  /** @brief Return port name with refresh ports */
  QString portName();
  /** @brief Return bound rate */
  int boundRate();
  /** @brief Return data bits */
  QSerialPort::DataBits dataBits();
  /** @brief Return parity */
  QSerialPort::Parity parity();
  /** @brief Return stop bit */
  QSerialPort::StopBits stopBits();
  /** @brief Return flow control mode */
  QSerialPort::FlowControl flowControl();

private:
  Ui::DSettings *ui; ///< @brief GUI view

public slots:
  /** @brief Seve settings in file */
  void Save_slt();
  /** @brief Load settings from file */
  void Load_slt();

private slots:
  /** @brief Refresh ports list */
  void RefreshPorts_slt();
};

