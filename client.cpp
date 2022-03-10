#include "client.h"

client::client()
{


}
bool client::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO CLIENT (IDC, ADR,PRENOMCL,NOMCL,NUM,NBPT) " "VALUES (:idc, :adr, :prenomcl, :nomcl,:num,:nbpt )");
    query.bindValue(":idc", idc);
    query.bindValue(":adr", adr);
    query.bindValue(":prenomcl", prenomcl);
    query.bindValue(":nomcl", nomcl);
    query.bindValue(":num", num);
    query.bindValue(":nbpt", nbpt);

    return query.exec();
}
QSqlQueryModel * client::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT *FROM CLIENT ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ADR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMCL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOMCL"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM"));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NBPT"));

    model->setQuery("SELECT IDC, ADR,PRENOMCL,NOMCL,NUM,NBPT FROM CLIENT");
    return model;

}
bool client::supprimer(QString idc)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where IDC = :idc ");
    query.bindValue(":idc",idc);
    return query.exec();
}
bool client::modifier(QString idc)
{

    QSqlQuery query;




    query.prepare("UPDATE CLIENT SET   NUM = :num WHERE IDC = :idc " );

    query.bindValue(":idc", idc);
    query.bindValue(":adr", adr);
    query.bindValue(":prenomcl", prenomcl);
    query.bindValue(":nomcl", nomcl);
    query.bindValue(":num", num);
    query.bindValue(":nbpt", nbpt);


    return query.exec();




}



