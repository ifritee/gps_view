QT       += core serialport gui widgets positioning

TEMPLATE = app
CONFIG += console c++17

SOURCES += \
        src/common/CConstants.cpp \
        src/common/FCalculate.cpp \
        src/gui/MainWindow.cpp \
        src/gui/USatelliteItem.cpp \
        src/gui/WSatellitesView.cpp \
        src/main.cpp \
        src/parser/ANMEAString.cpp \
        src/parser/UNMEADHVString.cpp \
        src/parser/UNMEAGGAString.cpp \
        src/parser/UNMEAGLLString.cpp \
        src/parser/UNMEAGSAString.cpp \
        src/parser/UNMEAGSTString.cpp \
        src/parser/UNMEAGSVString.cpp \
        src/parser/UNMEARMCString.cpp \
        src/parser/UNMEATXTString.cpp \
        src/parser/UNMEAVTGString.cpp \
        src/parser/UNMEAZDAString.cpp \
        src/parser/UParser.cpp

HEADERS += \
  src/common/CConstants.h \
  src/common/FCalculate.h \
  src/gui/MainWindow.h \
  src/gui/USatelliteItem.h \
  src/gui/WSatellitesView.h \
  src/parser/ANMEAString.h \
  src/parser/UNMEADHVString.h \
  src/parser/UNMEAGGAString.h \
  src/parser/UNMEAGLLString.h \
  src/parser/UNMEAGSAString.h \
  src/parser/UNMEAGSTString.h \
  src/parser/UNMEAGSVString.h \
  src/parser/UNMEARMCString.h \
  src/parser/UNMEATXTString.h \
  src/parser/UNMEAVTGString.h \
  src/parser/UNMEAZDAString.h \
  src/parser/UParser.h

INCLUDEPATH += \
  src \
  src/common \
  src/gui \
  src/parser

FORMS += \
  src/gui/MainWindow.ui
