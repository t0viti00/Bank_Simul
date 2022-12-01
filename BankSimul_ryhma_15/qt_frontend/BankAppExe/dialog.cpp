#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "restapi_dll.h"

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    pRestAPI = new RestAPI_DLL(this);
    connect(pRestAPI,SIGNAL(accountToEXE(QString)),this, SLOT(getAccountInfoFromDLL(QString)));//haetaan account id:llä
    connect(pRestAPI,SIGNAL(cardToEXE(QString)),this, SLOT(getCardInfoFromDLL(QString)));//haetaan korttinumerolla
    connect(pRestAPI,SIGNAL(updatebalanceToEXE(QString)),this, SLOT(updateAccountFromDLL(QString)));
    connect(pRestAPI,SIGNAL(IDToEXE(QString)),this, SLOT(IDFromDLL(QString)));//haetaan tilitapahtumat
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::Tilihallinta(QString tilinumero)
{
    cardnumber = tilinumero;
    qDebug()<< cardnumber;

    pRestAPI->getIDAccountInfo(cardnumber);







}

void Dialog::IDhallinta()
{
    QString ID;
    ID= ui->label_4->text();
    pRestAPI->GetAccountInfo();

}







void Dialog::on_pushButton_Selaa_clicked()
{

}

void Dialog::on_pushButton_Nosta_clicked()
{
    //raha_maara
    raha_maara= ui->label->text().toInt();
    qDebug()<<raha_maara;

    int nostomaara;
    nostomaara = ui->lineEdit->text().toInt();

    if(nostomaara>raha_maara){

        ui->label_3->setText("ERROR! Tilin kate ei riitä");
    }
    else{

        ui->label_3->setText("");

        balance=raha_maara-nostomaara;

        pRestAPI->UpdateAccountInfo(balance, id);

        ui->label->setText(QString::number(balance));

    }

}

void Dialog::on_pushButton_5_clicked()
{
    close();
}

void Dialog::getAccountInfoFromDLL(QString account)
{
    pRestAPI->GetAccountInfo();
    qDebug()<< "slotissa onnistui";
    qDebug()<<account; //tulostaa balancen
    ui->label->setText(account);


}

void Dialog::getCardInfoFromDLL(QString cardnumber)
{
    ui->label_3->setText(cardnumber);

}

void Dialog::getCardnumberFromMainWindow(QString cardinfo)
{
    ui->label_4->setText(cardinfo);



}

void Dialog::updateAccountFromDLL(QString)
{

}

void Dialog::IDFromDLL(QString ID)
{
   // pRestAPI->getIDAccountInfo(ID);
    ui->label_4->setText(ID);
    qDebug()<<ID;


}




