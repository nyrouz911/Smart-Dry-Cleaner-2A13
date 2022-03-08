#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QObject>

client::client(int ID_CL,QString PRENOM_CL,QString ADRESSE,QString NOM_CL,int TEL_CL)
{
    this->ID_CL=ID_CL;
    this->PRENOM_CL=PRENOM_CL;
    this->ADRESSE=ADRESSE;
    this->NOM_CL=NOM_CL;
    this->TEL_CL=TEL_CL;
}
bool client::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(ID_CL);
    QString num_string=QString::number(TEL_CL);
    //prepare() prend la requete en paramaetre pour la preparer a l'execution.
    query.prepare("INSERT INTO CLIENT (ID_CL,PRENOM_CL,ADRESSE,NOM_CL,TEL_CL) "
                  "VALUES (:ID_CL, :PRENOM_CL, :NOM_CL, :ADRESSE, :TEL_CL)");
    query.bindValue(":ID_CL",ID_CL);
    query.bindValue(":PRENOM_CL",PRENOM_CL);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":NOM_CL",NOM_CL);
    query.bindValue(":TEL_CL",TEL_CL);


    return query.exec();
}
QSqlQueryModel * client::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_CL"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("PRENOM_CL"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("TEL_CL"));
    return model;
}
bool client::supprimer(int ID_CL)
{
    QSqlQuery query;
       // QString res=QString::number(ID_CL);
           query.prepare("DELETE FROM CLIENT WHERE ID_CL=:ID_CL");
           query.bindValue(":ID_CL",ID_CL);
           return  query.exec();
}
bool  client::modifier(int ID_CL)
{
    QSqlQuery query;

    query.prepare("UPDATE CLIENT SET PRENOM_CL=:PRENOM_CL,ADRESSE=:ADRESSE,NOM_CL=:NOM_Cl,TEL_CL=:TEL_CL WHERE ID_CL=:ID_CL");
    query.bindValue(":ID_CL", ID_CL);
    query.bindValue(":PRENOM", PRENOM_CL);
    query.bindValue(":NOM", NOM_CL);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue("TEL_CL", TEL_CL);
    return query.exec();
}





