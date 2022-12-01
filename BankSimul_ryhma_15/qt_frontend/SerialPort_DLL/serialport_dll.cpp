#include "serialport_dll.h"

#include <fstream>
#include <iostream>

#include <string>
using namespace std;



SerialPort_DLL::SerialPort_DLL(QObject *parent):QObject(parent)
{
    pEngine = new engine(this);
    connect(pEngine,SIGNAL(sendToSerialPort_DLL(QString)), this, SLOT(getSignalFromEngine(QString)));
    connect(pEngine,SIGNAL(sendToInterface(QString)), this, SLOT(handleReadyRead(QString)));

}

SerialPort_DLL::~SerialPort_DLL()
{
    delete pEngine;
    pEngine = nullptr;

}

void SerialPort_DLL::GetID()
{

    pEngine -> open();

}

void SerialPort_DLL::ReadID()
{
    pEngine-> info();

}

void SerialPort_DLL::handleReadyRead(QString data)
{
    //readdata.append(pQSerialPort->readAll());
    emit DataToEXE(data);

}

void SerialPort_DLL::getSignalFromEngine(QString info)
{
    emit InfoToEXE(info);

}
