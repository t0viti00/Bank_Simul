#ifndef RESTAPI_DLL_H
#define RESTAPI_DLL_H

#include "RestAPI_DLL_global.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QObject>
#include <QMainWindow>

class RESTAPI_DLL_EXPORT RestAPI_DLL : public QObject
{
    Q_OBJECT

public:
    RestAPI_DLL(QObject * parent = nullptr);
    ~RestAPI_DLL();
    void GetUserInfo(QString a, QString b);
    void GetAccountInfo();
    void GetCardInfo(QString cardnumber);
    void UpdateAccountInfo(int c, QString d);
    void getIDAccountInfo(QString account_id_account);


public slots:
    void cardnumberSlot(QNetworkReply *reply);
    void accountinfoSlot(QNetworkReply *reply);
    void cardinfoSlot(QNetworkReply *reply);
    void accountUpdateSlot(QNetworkReply *reply);
    void IDaccountSlot(QNetworkReply *reply);

signals:
    void tietokantaToEXE(QString card);
    void accountToEXE(QString);
    void cardToEXE(QString);
    void updatebalanceToEXE(QString);
    void IDToEXE(QString);

private:
    QNetworkAccessManager *cardnumberManager;
    QNetworkReply *cardnumberReply;
    QNetworkAccessManager *accountManager;
    QNetworkReply *accountReply;
    QNetworkAccessManager *cardManager;
    QNetworkReply *cardReply;
    QNetworkAccessManager *updateManager;
    QNetworkReply *updateReply;
    QNetworkAccessManager *IDManager;
    QNetworkReply *IDReply;

};

#endif // RESTAPI_DLL_H


