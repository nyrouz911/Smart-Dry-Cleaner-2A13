#include "temp.h"
#include "arduino.h"
#include "ui_temp.h"

temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{


    ui->setupUi(this);
    ui->afficher_temp->setModel(t.affichertemp());

    int ret=t.connect_Arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< t.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<t.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(t.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}


temp::~temp()
{
    delete ui;
}



void temp::on_actualiser_clicked()
{
    ui->afficher_temp->setModel(t.affichertemp());

    QMessageBox msgBox;
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("select * from temperatures where value > 50 ");
    query->exec();
    if (query->next())
    {

        msgBox.setText("Une température anormale a été détectée !");
        msgBox.setInformativeText("Voulez-vous activer le moteur de refroidissement?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if (ret==QMessageBox::Ok)

           t.write_to_arduino("1");


     }
}
