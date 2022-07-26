#include "MainWindow.h"

#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

#include "UParser.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , _Timer_po(new QTimer(this))
  , _SerialPort_po(new QSerialPort)
{
  ui->setupUi(this);

  connect(ui->refresh_pb, &QPushButton::clicked, this, &MainWindow::RefreshPorts_slt);
  connect(ui->start_pb, &QPushButton::clicked, this, &MainWindow::StartGPS_slt);
  connect(ui->stop_pb, &QPushButton::clicked, this, &MainWindow::StopGPS_slt);
  connect(_SerialPort_po, &QSerialPort::readyRead, this, &MainWindow::ReadNMEA_slt);
}

MainWindow::~MainWindow()
{
  StopGPS_slt();
  delete ui;
  delete _Timer_po;
  delete _SerialPort_po;
}

void MainWindow::RefreshPorts_slt()
{
  ui->avaiblePorts_cb->clear();
  foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
    ui->avaiblePorts_cb->addItem(info.portName());
    ui->start_pb->setEnabled(true);
  }
}

void MainWindow::StartGPS_slt()
{
  _SerialPort_po->setPortName(ui->avaiblePorts_cb->currentText());
  if (_SerialPort_po->open(QIODevice::ReadOnly)) {
    if (_SerialPort_po->setBaudRate(ui->boundRates_cb->currentText().toInt())
        && _SerialPort_po->setDataBits(QSerialPort::DataBits(ui->dataBits_cb->currentIndex()))
        && _SerialPort_po->setParity(QSerialPort::Parity(ui->parity_cb->currentIndex() > 0 ? ui->parity_cb->currentIndex() + 1 : 0))
        && _SerialPort_po->setStopBits(QSerialPort::StopBits(ui->stopBits_cb->currentIndex() + 1))
        && _SerialPort_po->setFlowControl(QSerialPort::FlowControl(ui->flowControls_cb->currentIndex()))) {
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
