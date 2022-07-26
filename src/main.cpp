#include <QApplication>
#include <iostream>
#include <exception>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
  QApplication application(argc, argv);
  int returnCode = 0;
  try {
    MainWindow mainWindow;
    mainWindow.show();
    returnCode = application.exec();
  }
  catch (const std::exception & e) {
    std::cerr<<e.what()<<std::endl;
    returnCode = -1;
  }

  return returnCode;
}
