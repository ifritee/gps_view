#pragma once

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class QTimer;
class QSerialPort;
class DSettings;
class DHelpAbout;

/**
 * @class MainWindow
 * @brief GUI Main window
 * @author Nikishin E.V.
 * @date 29.07.2022 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /** @brief Constructor */
  explicit MainWindow(QWidget *parent = nullptr);
  /** @brief Destructor */
  virtual ~MainWindow();

private:
  Ui::MainWindow *ui; ///< @brief GUI view
  QTimer * _Timer_po; ///< @brief Timer read data
  QSerialPort * _SerialPort_po; ///< @brief RS232 port
  QByteArray _ReciveData_o; ///< @brief Recived data
  DSettings * _Settings_po; ///< @brief Settings dialog
  DHelpAbout * _HelpAbout_po; ///< @brief Help window "About..."

protected:
  /** @brief widget show */
  void showEvent(QShowEvent * event) override final;

private slots:
  /** @brief Start GPS control */
  void StartGPS_slt();
  /** @brief Stop GPS control */
  void StopGPS_slt();
  /** @brief Read NMEA string */
  void ReadNMEA_slt();
};

