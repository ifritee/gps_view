#pragma once

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class QTimer;
class QSerialPort;
class DSettings;

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
  QByteArray _ReciveData_o; ///< @brief Принятые данные
  DSettings * _Settings_po; ///< @brief Диалог настроек

private slots:
  void StartGPS_slt();
  void StopGPS_slt();
  void ReadNMEA_slt();
};

