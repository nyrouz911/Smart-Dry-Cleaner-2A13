#include "temp.h"
#include "arduino.h"
#include "ui_temp.h"

temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{

    QByteArray d ("0");
    ui->setupUi(this);
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
        {
            d=("1");
           t.write_to_arduino(d);
        }

     }
}


temp::~temp()
{
    delete ui;
}


