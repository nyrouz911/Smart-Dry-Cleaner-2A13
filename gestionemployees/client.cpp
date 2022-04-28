#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QObject>

client::client(int ID_CL,QString PRENOM_CL,QString ADRESSE,QString NOM_CL,QString TEL_CL)
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
    //prepare() prend la requete en paramaetre pour la preparer a l'execution.
    query.prepare("INSERT INTO CLIENT (ID_CL,PRENOM_CL,ADRESSE,NOM_CL,TEL_CL) "
                  "VALUES (:ID_CL, :PRENOM_CL, :ADRESSE, :NOM_CL, :TEL_CL)");
    query.bindValue(":ID_CL",res);
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
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRENOM_CL"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("NOM_CL"));
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
bool client::modifier(int ID_CL,QString PRENOM_CL,QString ADRESSE,QString NOM_CL,QString TEL_CL)
{
    QSqlQuery query;
    QString res= QString::number(ID_CL);

    query.prepare("UPDATE client SET PRENOM_CL=:PRENOM_CL,ADRESSE=:ADRESSE,NOM_CL=:NOM_CL,TEL_CL=:TEL_CL    WHERE ID_CL=:ID_CL");
    query.bindValue(":ID_CL", res);
    query.bindValue(":PRENOM_CL", PRENOM_CL);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":NOM_CL", NOM_CL);
    query.bindValue(":TEL_CL", TEL_CL);
    return query.exec();

}
QSqlQueryModel * client::tri()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY CAST(ID_CL AS number)");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM_CL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL_CL"));

    return model;
}
QSqlQueryModel * client::tri2()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER by  NOM_CL ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM_CL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL_CL"));


    return model;
}
QSqlQueryModel * client::tri3()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY CAST(TEL_CL AS number)");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM_CL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL_CL"));


    return model;
}
QSqlQueryModel * client::tri1()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER by  PRENOM_CL ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM_CL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL_CL"));


    return model;
}
QSqlQueryModel* client::rechercheMulticritere(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM client WHERE ID_CL LIKE '"+recherche+"%' OR NOM_CL LIKE '"+recherche+"%' OR PRENOM_CL LIKE '"+recherche+"%'OR TEL_CL LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("PRENOM_CL"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOM_CL"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("TEL_CL"));
    return model;
}



