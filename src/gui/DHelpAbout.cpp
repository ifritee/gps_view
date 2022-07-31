#include "DHelpAbout.h"
#include "ui_DHelpAbout.h"

DHelpAbout::DHelpAbout(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DHelpAbout)
{
  ui->setupUi(this);
}

DHelpAbout::~DHelpAbout()
{
  delete ui;
}
