#include "livraison.h"
#include <QSqlQuery>
#include <QDate>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>

livraison::livraison()
{
id_livr=0;
etat_livr="";
n#include "livraison.h"
#include <QSqlQuery>
#include <QDate>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>

livraison::livraison()
{
id_livr=0;
etat_livr="";
num_livr="";
adresse_livr="";
id_commande=0;
}
livraison::livraison(int id_livr,QString etat_livr,QString num_livr,QString adresse_livr,QDate date_livr,int id_commande)

{
    this->id_livr=id_livr;
    this->etat_livr=etat_livr;
    this->num_livr=num_livr;
    this->adresse_livr=adresse_livr;
    this->date_livr=date_livr;
    this->id_commande=id_commande;

}
    int livraison::getID_LIVR(){return id_livr;}
    QString livraison::getETAT_LIVR(){return etat_livr;}
    QString livraison::getNUM_LIVR(){return num_livr;}
    QString livraison::getADRESSE_LIVR(){return adresse_livr;}
    QDate livraison::getDATE_LIVR(){return date_livr;}
    int livraison::getID_COMMANDE(){return id_commande;}



    void livraison::setID_LIVR(int id_livr){this->id_livr=id_livr;}
    void livraison::setETAT_LIVR(QString etat_livr){this->etat_livr=etat_livr;}
    void livraison::setNUM_LIVR(QString num_livr){this->num_livr=num_livr;}
    void livraison::setADRESSE_LIVR(QString adresse_livr){this->adresse_livr=adresse_livr;}
    void livraison::setDATE_LIVR(QDate date_livr){this->date_livr=date_livr;}
    void livraison::setID_COMMANDE(int id_commande){this->id_commande=id_commande;}



    bool livraison::ajouter()
    {

    QSqlQuery query;
    query.prepare("INSERT INTO LIVRAISONS (id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande) "
                  "VALUES (:id_livr, :etat_livr, :num_livr, :adresse_livr, :date_livr, :id_commande)");
    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);

    return    query.exec();
    }

    QSqlQueryModel* livraison::afficher()
    {

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM LIVRAISONS");

    return model;
    }

    bool livraison::supprimer(int)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM LIVRAISONS WHERE id_livr=:id_livr");
        query.bindValue(0, id_livr);
        return query.exec();
    }

    bool livraison::modifier(int id_livr)
    {
     QSqlQuery query;



    query.prepare("update  LIVRAISONS set etat_livr=:etat_livr, num_livr=:num_livr, adresse_livr=:adresse_livr, date_livr=:date_livr,id_commande=:id_commande where id_livr=:id_livr ");


    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);



     return query.exec();
    }





