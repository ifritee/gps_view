#include "MainWindow.h"

#include <QTimer>
#include <QButtonGroup>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

#include "UParser.h"
#include "DSettings.h"
#include "DHelpAbout.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , _Timer_po(new QTimer(this))
  , _SerialPort_po(new QSerialPort)
  , _Settings_po(new DSettings(this))
  , _HelpAbout_po(new DHelpAbout(this))
  , _ControlView_po (new QButtonGroup(this))
{
  ui->setupUi(this);

  QPushButton * satellitesView = new QPushButton("S", this);
  satellitesView->setFixedSize(24, 24);
  satellitesView->setCheckable(true);
  satellitesView->setChecked(true);
  QPushButton * lacationView = new QPushButton("M", this);
  lacationView->setFixedSize(24, 24);
  lacationView->setCheckable(true);
  _ControlView_po->addButton(satellitesView, static_cast<int>(EVIEWCONTROLS::SATELLITES));
  _ControlView_po->addButton(lacationView, static_cast<int>(EVIEWCONTROLS::LOCATION));
  _ControlView_po->setExclusive(true);
  ui->statusbar->addPermanentWidget(satellitesView);
  ui->statusbar->addPermanentWidget(lacationView);

  connect(_SerialPort_po, &QSerialPort::readyRead, this, &MainWindow::ReadNMEA_slt);
  connect(ui->actionSettings, &QAction::triggered, [this](){ _Settings_po->exec(); });
  connect(ui->actionAbout, &QAction::triggered, [this](){ _HelpAbout_po->exec(); });
  connect(ui->actionSave_settings, &QAction::triggered, _Settings_po, &DSettings::Save_slt);
  connect(ui->actionLoad_settings, &QAction::triggered, _Settings_po, &DSettings::Load_slt);
  connect(ui->actionExit, &QAction::triggered, [this](){ qApp->quit();});
  connect(_ControlView_po, &QButtonGroup::idClicked, ui->stackedWidget, &QStackedWidget::setCurrentIndex);
}

MainWindow::~MainWindow()
{
  StopGPS_slt();
  delete ui;
  delete _Timer_po;
  delete _SerialPort_po;
  delete _Settings_po;
  delete _HelpAbout_po;
  for(auto * button : _ControlView_po->buttons()) {
    delete button;
  }
  delete _ControlView_po;
}

void MainWindow::showEvent(QShowEvent *event)
{
  QMainWindow::showEvent(event);
  if (!_SerialPort_po->isOpen()) {
    StartGPS_slt();
  }
//  QTimer::singleShot(500, [this]() {
//    QAbstractButton * sat = _ControlView_po->button(static_cast<int>(EVIEWCONTROLS::SATELLITES));
//    QAbstractButton * loc = _ControlView_po->button(static_cast<int>(EVIEWCONTROLS::LOCATION));
//    sat->move(ui->frame->width() + 8, ui->menubar->height() + 2);
//    loc->move(ui->frame->width() + sat->width() + 8, ui->menubar->height() + 2);
//  });
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
    QTimer::singleShot(1000, this, &MainWindow::StartGPS_slt);
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
    if (data) {
      ui->graphicsView->setViewData_v(data);
      ui->generalData->setViewData_v(data);
      ui->pageLocation->setViewData_v(data);
    }
    _ReciveData_o.clear();
  }
}
