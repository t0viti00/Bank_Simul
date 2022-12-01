#ifndef ENGINE_H
#define ENGINE_H

#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
//#include <QObject>
#include <QString>
#include <QList>
//#include <QByteArray>

class engine:public QObject
{
    Q_OBJECT
public:
    engine(QObject * parent = nullptr);
    ~engine();
    void open(void);
    void info(void);

private:
    QSerialPort * pQSerialPort;
    QSerialPortInfo * pQSerialPortInfo;

signals:
    void sendToSerialPort_DLL(QString);
    void sendToInterface(QString);

public slots:
    void cardfound(void);

};

#endif // ENGINE_H
