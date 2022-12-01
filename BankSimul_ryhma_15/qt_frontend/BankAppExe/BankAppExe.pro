QT       += core gui
QT       += serialport
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp\
    main.cpp \
    mainwindow.cpp

HEADERS += \
    dialog.h\
    mainwindow.h

FORMS += \
    dialog.ui\
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../build-SerialPort_DLL-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lSerialPort_DLL

INCLUDEPATH += $$PWD/../SerialPort_DLL
DEPENDPATH += $$PWD/../SerialPort_DLL

win32: LIBS += -L$$PWD/../build-PinCodeDLL-Desktop_Qt_5_15_0_MinGW_32_bit-Debug/debug/ -lPinCodeDLL

INCLUDEPATH += $$PWD/../PinCodeDLL
DEPENDPATH += $$PWD/../PinCodeDLL

win32: LIBS += -L$$PWD/../build-RestAPI_DLL-Desktop_Qt_5_15_2_MinGW_32_bit-Debug/debug/ -lRestAPI_DLL

INCLUDEPATH += $$PWD/../RestAPI_DLL
DEPENDPATH += $$PWD/../RestAPI_DLL
