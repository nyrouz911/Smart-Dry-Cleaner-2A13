/*
#include "gestionemployes.h"
#include "ui_gestionemployes.h"

gestionemployes::gestionemployes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionemployes)
{
    ui->setupUi(this);
}*/

#include "gestionemployes.h"
#include "ui_gestionemployes.h"
#include "employes.h"
#include <QMessageBox>
#include "QMessageBox"
#include <QApplication>
#include <QIntValidator>
#include <QStackedWidget>
#include <QDateEdit>
#include<QSqlQuery>
#include <QComboBox>
#include <QDialog>


/*gestionemployes::gestionemployes(QWidget *parent):
    QDialog(parent)
    , ui(new Ui::gestionemployes)*/
gestionemployes::gestionemployes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionemployes)
{
    //afficher
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
    ui->AfficherMessage->setModel(m.afficherM());
}

void gestionemployes::on_pushButton_clicked()
{
    //ajouter
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int salaire=ui->salaire->text().toFloat();
    QString role=ui->role->text();

    Employes e(nom,prenom,salaire,role);

        bool test=e.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);

}

void gestionemployes::on_pushButton_2_clicked()
{
    //supprimer
    int id=ui->lineEdit_5->text().toUInt();
    bool test=e.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);

}

void gestionemployes::on_pushButton_3_clicked()
{
    //modifier
    int id=ui->lineEdit_6->text().toUInt();
    QString nom=ui->lineEdit_7->text();
    QString prenom=ui->lineEdit_8->text();
    int salaire=ui->lineEdit_9->text().toFloat();
    QString role=ui->lineEdit_10->text();
    bool test=e.modifier(id,nom,prenom,salaire,role);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);


}

void gestionemployes::on_pushButton_4_clicked()
//afficher2.0
{
    ui->tableView->setModel(e.afficher());
}

void gestionemployes::on_pushButton_5_clicked()
{
    QMessageBox msgBox;

        QSqlQuery query;
        QString nom="",prenom="",role="";
        int critere=ui->comboBox->currentIndex();

        if(critere==2)
        {
             role=ui->lineEdit->text();

             ui->tableView->setModel(e.RechercheByRole(role));

             query.bindValue(":role", role);
             query.exec();
        }
           else if(critere==0)
           {
               nom=ui->lineEdit->text();
               ui->tableView->setModel(e.RechercheByNom(nom));
               query.bindValue(":nom", nom);
               query.exec();

           }
           else if(critere==1)
           {
               prenom=ui->lineEdit->text();
               ui->tableView->setModel(e.RechercheByPrenom(prenom));
               query.bindValue(":prenom", prenom);
               query.exec();
           }
}

void gestionemployes::on_pushButton_6_clicked()
{
    ui->tableView->setModel(e.tri());
}


void gestionemployes::on_pushButton_7_clicked()
{
    ui->tableView->setModel(e.tri1());
}

void gestionemployes::on_pushButton_8_clicked()
{
    ui->tableView->setModel(e.tri2());
}

void gestionemployes::on_comboBox_activated(const QString &arg1)
{

}

void gestionemployes::on_pushButton_9_clicked() // français
{
    ui->label_2->setText("Nom");
    ui->label_3->setText("Prénom");
    ui->label_4->setText("Salaire");
    ui->label_5->setText("Role");
    ui->label_8->setText("Nom");
    ui->label_9->setText("Prénom");
    ui->label_10->setText("Salaire");
    ui->label_11->setText("Role");

    ui->pushButton_5->setText("chercher");
    ui->send->setText("envoyer");
    //ui->bind->setText("connect");
    //ui->pushButton_9->setText("Français");
    //ui->pushButton_10->setText("Anglais");
    ui->pushButton_7->setText("tri nom");
    ui->pushButton_8->setText("tri prenom");
    ui->pushButton_6->setText("tri salaire");
    ui->pushButton_4->setText("Actualiser");
    ui->label_14->setText("message");
}

void gestionemployes::on_pushButton_10_clicked() // anglais
{
       ui->label_2->setText("Name");
       ui->label_3->setText("Surname");
       ui->label_4->setText("Salary");
       ui->label_5->setText("Role");
       ui->label_8->setText("Name");
       ui->label_9->setText("Surname");
       ui->label_10->setText("Salary");
       ui->label_11->setText("Role");
       ui->pushButton_5->setText("Reseach");
       ui->send->setText("send");
       ui->pushButton_7->setText("Sorte by Name");
       ui->pushButton_8->setText("Sorte by Surname");
       ui->pushButton_6->setText("Sorte by Salary");
       ui->pushButton_4->setText("Update");
       ui->label_14->setText("message");



}

void gestionemployes::on_send_clicked()
{
    //ajouter
    QString message=ui->message->text();
    Message m(message);

        //bool test=
                m.ajouterM();
       /* if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);*/

}



void gestionemployes::on_afficherM_clicked()
{
    ui->AfficherMessage->setModel(m.afficherM());
}
