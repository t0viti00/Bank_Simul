#ifndef SERIALPORT_DLL_H
#define SERIALPORT_DLL_H

#include "SerialPort_DLL_global.h"
#include "engine.h"



class SERIALPORT_DLL_EXPORT SerialPort_DLL:public QObject
{
    Q_OBJECT

public:
    SerialPort_DLL(QObject * parent = nullptr);
    ~SerialPort_DLL();
    void GetID();
    void ReadID();

private:
    engine * pEngine;
signals:
    void InfoToEXE(QString);
    void DataToEXE(QString);
public slots:
    void getSignalFromEngine(QString);
    void handleReadyRead(QString);



};
#endif // SERIALPORT_DLL_H

