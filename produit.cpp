#include "produit.h"

produit::produit()
{


}
bool produit::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO PRODUIT (ID_PRODUIT, FOURNISSEUR,QUANTITE,PRIX_UNITAIRE,TYPE_MACHINE) " "VALUES (:id_produit, :fournisseur, :quantite, :prix_unitaire,:type_machine)");
    query.bindValue(":id_produit", id_produit);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix_unitaire", prix_unitaire);
    query.bindValue(":type_machine", type_machine);


    return query.exec();
}
QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUIT ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PRODUIT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNITAIRE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));

    model->setQuery("SELECT ID_PRODUIT, FOURNISSEUR,QUANTITE,PRIX_UNITAIRE,TYPE_MACHINE FROM PRODUIT");
    return model;

}

/*bool produit::modifier(int id_produit)
{

    QSqlQuery query;


    query.bindValue(":id_produit", id_produit);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix_unitaire", prix_unitaire);
    query.bindValue(":type_machine", type_machine);
    query.prepare("UPDATE PRODUIT SET   FOURNISSEUR = :fournisseur, QUANTITE = :quantite, PRIX_UNITAIRE= :prix_unitaire, TYPE_MACHINE = :type_machine  WHERE ID_PRODUIT = :id_produit " );


    return query.exec();




}*/

bool produit::modifier(int id_produit,QString fournisseur,int quantite ,int prix_unitaire,QString type_machine){
 QSqlQuery query;



query.prepare("UPDATE PRODUIT SET FOURNISSEUR=:fournisseur, QUANTITE=:quantite, PRIX_UNITAIRE=:prix_unitaire,TYPE_MACHINE=:type_machine where ID_PRODUIT=:id_produit ");


 query.bindValue(":id_produit", id_produit);
 query.bindValue(":fournisseur", fournisseur);
 query.bindValue(":quantite", quantite);
 query.bindValue(":prix_unitaire", prix_unitaire);
 query.bindValue(":type_machine", type_machine);

 return query.exec();
}

bool produit::supprimer(int id_produit)
{
    QSqlQuery query;
    query.prepare("Delete from PRODUIT where ID_PRODUIT = :id_produit ");
    query.bindValue(":id_produit",id_produit);
    return query.exec();
}



