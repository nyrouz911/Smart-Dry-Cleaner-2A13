#include "produit.h"

produit::produit()
{


}
bool produit::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO PRODUITS (ID_PROD, FOURNISS,QTE,PRIX_UNIT,TYPE_MACHINE,IMAGE) " "VALUES (:ID_PROD, :FOURNISS, :QTE, :PRIX_UNIT,:TYPE_MACHINE,:IMAGE)");
    query.bindValue(":ID_PROD", id_produit);
    query.bindValue(":FOURNISS", fournisseur);
    query.bindValue(":QTE", quantite);
    query.bindValue(":PRIX_UNIT", prix_unitaire);
    query.bindValue(":TYPE_MACHINE", type_machine);
    query.bindValue(":IMAGE", image);


    return query.exec();
}
QSqlQueryModel * produit::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));


    model->setQuery("SELECT ID_PROD, FOURNISS,QTE,PRIX_UNIT,TYPE_MACHINE,IMAGE FROM PRODUITS");
    return model;

}

/*bool produit::modifier(int ID_PROD)
{

    QSqlQuery query;


    query.bindValue(":ID_PROD", ID_PROD);
    query.bindValue(":FOURNISS", FOURNISS);
    query.bindValue(":QTE", QTE);
    query.bindValue(":PRIX_UNIT", PRIX_UNIT);
    query.bindValue(":type_machine", type_machine);
    query.prepare("UPDATE PRODUIT SET   FOURNISS = :FOURNISS, QTE = :QTE, PRIX_UNIT= :PRIX_UNIT, TYPE_MACHINE = :type_machine , IMAGE:=IMAGE WHERE ID_PROD = :ID_PROD " );


    return query.exec();




}*/

bool produit::modifier(int id_produit){
 QSqlQuery query;



query.prepare("UPDATE PRODUITS SET FOURNISS=:FOURNISS, QTE=:QTE, PRIX_UNIT=:PRIX_UNIT, TYPE_MACHINE=:TYPE_MACHINE, IMAGE=:IMAGE where ID_PROD=:ID_PROD ");


query.bindValue(":ID_PROD", id_produit);
query.bindValue(":FOURNISS", fournisseur);
query.bindValue(":QTE", quantite);
query.bindValue(":PRIX_UNIT", prix_unitaire);
query.bindValue(":TYPE_MACHINE", type_machine);
query.bindValue(":IMAGE", image);

 return query.exec();
}

bool produit::supprimer(int id_produit)
{
    QSqlQuery query;
    query.prepare("Delete from PRODUITS where ID_PROD = :ID_PROD ");
    query.bindValue(":ID_PROD",id_produit);
    return query.exec();


}
QSqlQueryModel * produit ::recherche(QString id_produit)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS WHERE ID_PROD LIKE '%"+id_produit+"%'" );

    model->query().bindValue(":ID_PROD",id_produit);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel * produit ::recherchefournisseur(QString fournisseur)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS WHERE FOURNISS LIKE '%"+fournisseur+"%'" );

    model->query().bindValue(":FOURNISS",fournisseur);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel * produit ::recherchequantite(QString quantite)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS WHERE QTE LIKE '%"+quantite+"%'" );

    model->query().bindValue(":QTE",quantite);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel * produit ::rechercheprix(QString prix_unitaire)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS WHERE PRIX_UNIT LIKE '%"+prix_unitaire+"%'" );

    model->query().bindValue(":PRIX_UNIT",prix_unitaire);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel * produit ::recherchetype(QString type_machine)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS WHERE TYPE_MACHINE LIKE '%"+type_machine+"%'" );

    model->query().bindValue(":TYPE_MACHINE",type_machine);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}
/*QSqlQueryModel* produit::tri(QString id_produit){
            QSqlQuery qry;
             qry.prepare("select * from PRODUITS where ID_PROD=:ID_PROD order by prix_unitaire ASC ");
             qry.bindValue(":ID_PROD",id_produit);
             qry.exec();
             QSqlQueryModel *model= new QSqlQueryModel;
             model->setQuery(qry);

            return model;
  }*/


QSqlQueryModel * produit::AfficherTriquantite()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS ORDER BY QTE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}

QSqlQueryModel * produit::AfficherTriID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS ORDER BY ID_PROD ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}
QSqlQueryModel * produit::AfficherTriprix()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS ORDER BY PRIX_UNIT ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("FOURNISS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QTE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX_UNIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TYPE_MACHINE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("IMAGE"));

    return model;
}
