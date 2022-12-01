#include "engine.h"


engine::engine(QObject *parent):QObject(parent)
{
    pQSerialPort = new QSerialPort;
    pQSerialPortInfo = new QSerialPortInfo;
    connect(pQSerialPort,SIGNAL(readyRead()), this, SLOT(cardfound()));

}

engine::~engine()
{
   
    delete pQSerialPort;
    pQSerialPort = nullptr;

    delete pQSerialPortInfo;
    pQSerialPortInfo = nullptr;

}

void engine::open()
{
    pQSerialPort->setPortName("COM10");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);


    if (!pQSerialPort->open(QIODevice::ReadWrite))
    {
        qDebug()<< "ei aukea" << Qt::endl;
    }
    else
    {
        qDebug() << "portti aukesi" << Qt::endl;
       // qDebug() << pQSerialPort-> readAll();
    }

    //qDebug() <<"suljetaan lopuksi";
    

}

void engine::info()
{
    QList<QSerialPortInfo> ports = pQSerialPortInfo->availablePorts();

    foreach(QSerialPortInfo info, ports)
    {
       // qDebug() << info.portName();
        emit sendToSerialPort_DLL(info.portName());
       // qDebug()<< info.manufacturer();
        emit sendToSerialPort_DLL(info.manufacturer());
    }

   // emit sendToSerialPort_DLL("moi");
   // emit sendToSerialPort_DLL("hei");

}

void engine::cardfound()
{
    qDebug() << "kortti laitettu";
    QString card = pQSerialPort->readAll();
    card.remove(0,3);
    card.remove(10,13);
    //pQSerialPort->readAll();
    qDebug()<<card;

    emit sendToInterface(card);
    //
    pQSerialPort->close();
}
