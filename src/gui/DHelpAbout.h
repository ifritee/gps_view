#pragma once

#include <QDialog>

namespace Ui {
  class DHelpAbout;
}

class DHelpAbout : public QDialog
{
  Q_OBJECT

public:
  explicit DHelpAbout(QWidget *parent = nullptr);
  ~DHelpAbout();

private:
  Ui::DHelpAbout *ui;
};

