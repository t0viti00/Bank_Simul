#ifndef DIALOG_H
#define DIALOG_H

#include "serialport_dll.h"
#include "pincodedll.h"
#include "restapi_dll.h"
#include "mainwindow.h"
#include <QMainWindow>

namespace Ui {
class Dialog;
}

class Dialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int raha_maara;
    QString cardID= "0600062721";
    QString id;
    int balance;
    QString cardnumber;

    void Tilihallinta(QString tilinumero);
    void IDhallinta();

private slots:

    void on_pushButton_Selaa_clicked();

    void on_pushButton_Nosta_clicked();

    void on_pushButton_5_clicked();


public slots:
    void getAccountInfoFromDLL(QString account);
    void getCardInfoFromDLL(QString cardnumber);
    void getCardnumberFromMainWindow(QString);
    void updateAccountFromDLL(QString);
    void IDFromDLL(QString ID);

private:
    Ui::Dialog *ui;
    RestAPI_DLL *pRestAPI;
    QString tilinumero;
};

#endif // DIALOG_H
