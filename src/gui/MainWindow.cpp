#include "MainWindow.h"

#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

#include "UParser.h"
#include "DSettings.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , _Timer_po(new QTimer(this))
  , _SerialPort_po(new QSerialPort)
  , _Settings_po(new DSettings(this))
{
  ui->setupUi(this);

  connect(ui->start_pb, &QPushButton::clicked, this, &MainWindow::StartGPS_slt);
  connect(ui->stop_pb, &QPushButton::clicked, this, &MainWindow::StopGPS_slt);
  connect(_SerialPort_po, &QSerialPort::readyRead, this, &MainWindow::ReadNMEA_slt);
  connect(ui->actionSettings, &QAction::triggered, [this](){ _Settings_po->exec(); });
  connect(ui->actionSave_settings, &QAction::triggered, _Settings_po, &DSettings::Save_slt);
  connect(ui->actionLoad_settings, &QAction::triggered, _Settings_po, &DSettings::Load_slt);
  connect(ui->actionExit, &QAction::triggered, [this](){ qApp->quit();});
}

MainWindow::~MainWindow()
{
  StopGPS_slt();
  delete ui;
  delete _Timer_po;
  delete _SerialPort_po;
  delete _Settings_po;
}

void MainWindow::StartGPS_slt()
{
  _SerialPort_po->setPortName(_Settings_po->portName());
  if (_SerialPort_po->open(QIODevice::ReadOnly)) {
    if (_SerialPort_po->setBaudRate(_Settings_po->boundRate())
        && _SerialPort_po->setDataBits(_Settings_po->dataBits())
        && _SerialPort_po->setParity(_Settings_po->parity())
        && _SerialPort_po->setStopBits(_Settings_po->stopBits())
        && _SerialPort_po->setFlowControl(_Settings_po->flowControl())) {
      if (_SerialPort_po->isOpen()){
        qDebug()<<"RS232 port is open!!!";
        ui->stop_pb->setEnabled(true);
      } else {
        qWarning()<<"RS232 port failed open!!!";
        _SerialPort_po->close();
      }
    } else {
      qWarning()<<"RS232 port failed set attributes!!!";
      _SerialPort_po->close();
    }
  } else {
    qWarning()<<"RS232 port is not avaible!!!";
  }
}

void MainWindow::StopGPS_slt()
{
  if (_SerialPort_po->isOpen()) {
    qDebug()<<"RS232 port is closed!!!";
    _SerialPort_po->close();
  }
}

void MainWindow::ReadNMEA_slt()
{
  _ReciveData_o.append(_SerialPort_po->readAll());
  if (_ReciveData_o.size() > 2 && _ReciveData_o[_ReciveData_o.size() - 2] == '\r' && _ReciveData_o[_ReciveData_o.size() - 1] == '\n') {
    UParser parser(_ReciveData_o);
    ANMEAString * data = parser.parse();
    ui->graphicsView->setViewData_v(data);
    _ReciveData_o.clear();
  }
}
