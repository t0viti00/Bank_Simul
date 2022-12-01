#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "serialport_dll.h"
#include "pincodedll.h"
#include "restapi_dll.h"
#include "dialog.h"

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QList>
#include <QVector>
#include <QPushButton>
#include <QSerialPort>
#include <QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    PinCodeDLL * pPinCodeDLL = new PinCodeDLL;
    void ButtonClicked();
    QString cardnumber;
    QString pin;
    QString testi;
    QString tulos;
    QString account;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_Enter_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_cardtest_clicked();

public slots:
    void getSignalFromDLL(QString);
    void getCardFromDLL(QString data);
    void getTietokantaFromDLL(QString response_data);
    void getAccountIDFromDLL(QString ID);

signals:
    void sendCardnumber(QString cardinfo);

private:
    Ui::MainWindow *ui;
    SerialPort_DLL* pSerialPort;
    QVector<QPushButton *> napit;
    RestAPI_DLL* pRestAPI;
    QNetworkAccessManager *cardManager;
    QNetworkReply *cardReply;


};
#endif // MAINWINDOW_H
