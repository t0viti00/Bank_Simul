#include "restapi_dll.h"


RestAPI_DLL::RestAPI_DLL(QObject *parent):QObject(parent)
{

}

RestAPI_DLL::~RestAPI_DLL()
{

}

void RestAPI_DLL::GetUserInfo(QString a, QString b)
{
    //hakee korttinumeron ja pin-koodin

    QJsonObject json_obj;
    json_obj.insert("cardnumber",a);
    json_obj.insert("pin",b);
    QString site_url="http://localhost:3000/login";
    QString credentials="root:4712"; //root:root kai vaihetaan jos eri
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    cardnumberManager = new QNetworkAccessManager(this);
    connect(cardnumberManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(cardnumberSlot(QNetworkReply*)));
    cardnumberReply = cardnumberManager->post(request, QJsonDocument(json_obj).toJson());
}

void RestAPI_DLL::GetAccountInfo()
{

    qDebug()<<"tehtiin account pyyntö";
    //hakee account id

    QString id="1";

    QString site_url="http://localhost:3000/account/"+id;
    QString credentials="root:4712"; //root:root kai vaihetaan jos eri
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    accountManager = new QNetworkAccessManager(this);
    connect(accountManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(accountinfoSlot(QNetworkReply*)));
    accountReply = accountManager->get(request);


}

void RestAPI_DLL::GetCardInfo(QString cardnumber)
{
    //hakee korttinumerolla

    QString site_url="http://localhost:3000/card/"+cardnumber;
    QString credentials="root:4712"; //root:root kai vaihetaan jos eri
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    cardManager = new QNetworkAccessManager(this);
    connect(cardManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(cardinfoSlot(QNetworkReply*)));
    cardReply = cardManager->get(request);

}

void RestAPI_DLL::UpdateAccountInfo(int c, QString d)
{

    //hakee id_account tiedot update requestia varten
    QJsonObject json_obj;
    json_obj.insert("balance", c);
    json_obj.insert("id_account", d);

    QString id="1";


    QString site_url="http://localhost:3000/account/"+id;
    QString credentials="root:4712"; //root:root kai vaihetaan jos eri
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    updateManager = new QNetworkAccessManager(this);
    connect(updateManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(accountUpdateSlot(QNetworkReply*)));
    updateReply = updateManager->put(request, QJsonDocument(json_obj).toJson());

}

void RestAPI_DLL::getIDAccountInfo(QString account_id_account)
{
    //hakee tiedot account_id_accountia varten käyttäen kortinnumeroa

    QString site_url="http://localhost:3000/card/"+account_id_account;
    QString credentials="root:4712"; //root:root kai vaihetaan jos eri
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    IDManager = new QNetworkAccessManager(this);
    connect(IDManager, SIGNAL(finished(QNetworkReply*)),this,SLOT(IDaccountSlot(QNetworkReply*)));
    IDReply = IDManager->get(request);

}

void RestAPI_DLL::cardnumberSlot(QNetworkReply *reply)
{
    //vie tiedot korttinumerosta ja pin-koodista

    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;


    emit tietokantaToEXE(response_data);
   cardnumberReply->deleteLater();
   cardnumberManager->deleteLater();



}

void RestAPI_DLL::accountinfoSlot(QNetworkReply *reply)
{
    //hakee accountista id_account ja vie tulostukseen vain balancen


    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString account1;
    QString account2;



    foreach (const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();
    account1+=QString::number(json_obj["id_account"].toInt())+","+json_obj["balance"].toDouble()+"\r";

    account2+=QString::number(json_obj["balance"].toDouble());
    }


    qDebug()<<"account 2 tulostus" +account2;

    emit accountToEXE(account2);

    accountReply->deleteLater();
    accountManager->deleteLater();

}

void RestAPI_DLL::cardinfoSlot(QNetworkReply *reply)
{
    //vie tiedot kun haettu korttinumerolla
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString cardnumber;

    cardnumber=QString::number(json_obj["id_card"].toInt())+","+json_obj["cardnumber"].toString()+","+json_obj["pin"].toInt()
            +","+json_obj["account_id_account"].toInt()+","+json_obj["customer_id_customer"].toInt();
;
    qDebug()<<cardnumber;


    emit cardToEXE(cardnumber);
    cardReply->deleteLater();
    cardManager->deleteLater();

}

void RestAPI_DLL::accountUpdateSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    qDebug()<< "actions toimii";


    emit updatebalanceToEXE(response_data);
    updateReply->deleteLater();
    updateManager->deleteLater();

}

void RestAPI_DLL::IDaccountSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString ID;




    foreach (const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();

    ID+=QString::number(json_obj["account_id_account"].toInt());
    }

    qDebug()<<"ID tulostus" +ID;


    emit IDToEXE(ID);

    IDReply->deleteLater();
    IDManager->deleteLater();

}



