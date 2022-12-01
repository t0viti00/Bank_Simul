#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serialport_dll.h"
#include "restapi_dll.h"
#include "dialog.h"

#include <QString>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    napit.append(ui->pushButton);
    napit.append(ui->pushButton_2);
    napit.append(ui->pushButton_3);
    napit.append(ui->pushButton_4);
    napit.append(ui->pushButton_5);
    napit.append(ui->pushButton_6);
    napit.append(ui->pushButton_7);
    napit.append(ui->pushButton_8);
    napit.append(ui->pushButton_9);
    napit.append(ui->pushButton_Cancel);
    napit.append(ui->pushButton_Enter);

    pSerialPort = new SerialPort_DLL(this);
    pRestAPI = new RestAPI_DLL(this);
    connect(pSerialPort,SIGNAL(InfoToEXE(QString)),this, SLOT(getSignalFromDLL(QString)));
    connect(pSerialPort,SIGNAL(DataToEXE(QString)),this, SLOT(getCardFromDLL(QString)));
    connect(pRestAPI,SIGNAL(tietokantaToEXE(QString)),this, SLOT(getTietokantaFromDLL(QString)));//tiedot korttinumerosta ja pin-koodista


}

MainWindow::~MainWindow()
{
    delete ui;
    delete pSerialPort;
    pSerialPort = nullptr;

}

void MainWindow::ButtonClicked()
{
    if (cardnumber.isEmpty())
        {
        qDebug()<<"ei korttia";
    }
        else {

            qDebug()<<"kortti ok";


    QObject* sender = QObject::sender();

  //qDebug() << sender->objectName();

    QString painettunappi = sender->objectName();



    if (painettunappi == "pushButton")

            ui->lineEdit->setText(ui->lineEdit->text()+ "1");

    else if(painettunappi == "pushButton_2")

        ui->lineEdit->setText(ui->lineEdit->text()+ "2");

    else if(painettunappi == "pushButton_3")

        ui->lineEdit->setText(ui->lineEdit->text()+ "3");

    else if(painettunappi == "pushButton_4")

        ui->lineEdit->setText(ui->lineEdit->text()+ "4");

    else if(painettunappi == "pushButton_5")

        ui->lineEdit->setText(ui->lineEdit->text()+ "5");

    else if(painettunappi == "pushButton_6")

        ui->lineEdit->setText(ui->lineEdit->text()+ "6");

    else if(painettunappi == "pushButton_7")

        ui->lineEdit->setText(ui->lineEdit->text()+ "7");

    else if(painettunappi == "pushButton_8")

        ui->lineEdit->setText(ui->lineEdit->text()+ "8");

    else if(painettunappi == "pushButton_9")

        ui->lineEdit->setText(ui->lineEdit->text()+ "9");

    else if(painettunappi == "pushButton_10")

        ui->lineEdit->setText(ui->lineEdit->text()+ "0");

    else if(painettunappi == "pushButton_Enter")

        qDebug()<<"enter toimii";


          //ui->label_3->setText(ui->lineEdit->text());

    };

}


void MainWindow::on_pushButton_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_2_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_3_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_4_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_5_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_6_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_7_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_8_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_9_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_10_clicked()
{
    ButtonClicked();

}

void MainWindow::on_pushButton_Enter_clicked()
{
    ButtonClicked();
    pin=ui->lineEdit->text();
    pRestAPI->GetUserInfo(cardnumber,pin);//hakee korttinumeron ja pin-koodin



}

void MainWindow::on_pushButton_Cancel_clicked()
{
    ui->lineEdit->setText("");


}

void MainWindow::on_pushButton_11_clicked()
{
    pSerialPort->GetID();



}

void MainWindow::getSignalFromDLL(QString)
{


}

void MainWindow::getCardFromDLL(QString data)
{
    ui->Tulostus_Widget->addItem(data);
    cardnumber= data;
    qDebug()<<cardnumber;
    //tulostaa korttinumeron serialportilta

}

void MainWindow::getTietokantaFromDLL(QString response_data)
{
    ui->label_4->setText(response_data);
    //tulostaa true tai false


}

void MainWindow::getAccountIDFromDLL(QString ID)
{
    //ui->label_4->setText(ID);
   // account= ui->label_4->text();

}



void MainWindow::on_pushButton_cardtest_clicked()
{
    //tarkistaa login.js onko true vai false
    //avaa uuden ikkunan

    if(ui->label_4->text()=="true"){

        pRestAPI->GetCardInfo(cardnumber);



     Dialog * pDialog = new Dialog(this);
     pDialog->Tilihallinta(cardnumber);
     pDialog->IDhallinta();

     //connect(ui->label_4, SIGNAL(sendCardnumber(QString)), this, SLOT(getCardnumberFromMainWindow(Qstring)));
      pDialog->show();
        }
      else {

          qDebug()<<"nope";
        }

}
