#pragma once

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class QTimer;
class QSerialPort;

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  virtual ~MainWindow();

private:
  Ui::MainWindow *ui;
  QTimer * _Timer_po; ///< @brief Таймер считывания данных
  QSerialPort * _SerialPort_po; ///< @brief RS232 порт
  QByteArray _ReciveData_o;

private slots:
  void RefreshPorts_slt();
  void StartGPS_slt();
  void StopGPS_slt();
  void ReadNMEA_slt();
};

