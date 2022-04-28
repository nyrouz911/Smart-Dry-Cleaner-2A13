#include "abonnement.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QObject>

abonnement::abonnement(int ID_AB,QString DATE_DEB,QString  DATE_EXP,int NB_PNTFID,int ID_CLIENT)
{
    this->ID_AB=ID_AB;
    this->DATE_DEB=DATE_DEB;
    this->DATE_EXP=DATE_EXP;
    this->NB_PNTFID=NB_PNTFID;
    this->ID_CLIENT=ID_CLIENT;
}
bool abonnement::ajouterA()
{
    QSqlQuery query;
    QString res= QString::number(ID_CLIENT);
      QString res1= QString::number(ID_AB);
        QString res2= QString::number(NB_PNTFID);

    //prepare() prend la requete en paramaetre pour la preparer a l'execution.
    query.prepare("INSERT INTO abonnement (ID_AB,DATE_DEB,DATE_EXP,NB_PNTFID,ID_CLIENT) "
                  "VALUES ( :ID_AB, :DATE_DEB, :DATE_EXP, :NB_PNTFID, :ID_CLIENT)");
    query.bindValue(":ID_AB",res1);
    query.bindValue(":DATE_DEB",DATE_DEB);
    query.bindValue(":DATE_EXP",DATE_EXP);
    query.bindValue(":NB_PNTFID",res2);
    query.bindValue(":ID_CLIENT",res);

    return query.exec();
}
QSqlQueryModel * abonnement::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * from abonnement");
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_AB"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("DATE_DEB"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_EXP"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("NB_PNTFID"));
        model->setHeaderData(4,Qt::Horizontal, QObject::tr("ID_CLIENT"));
    return model;
}
bool abonnement::supprimer(int ID_AB)
{
    QSqlQuery query;
       // QString res=QString::number(ID_AB);
           query.prepare("DELETE FROM abonnement WHERE ID_AB=:ID_AB");
           query.bindValue(":ID_AB",ID_AB);
           return  query.exec();
}
bool abonnement::modifier(int ID_AB,QString DATE_DEB,QString DATE_EXP,int NB_PNTFID,int ID_CLIENT)
{
    QSqlQuery query;
    QString res= QString::number(ID_AB);
    QString res1= QString::number(NB_PNTFID);
    QString res2= QString::number(ID_CLIENT);

    query.prepare("UPDATE abonnement SET DATE_DEB=:DATE_DEB,DATE_EXP=:DATE_EXP,NB_PNTFID=:NB_PNTFID,ID_CLIENT=:ID_CLIENT WHERE ID_AB=:ID_AB");
    query.bindValue(":ID_AB",res);
    query.bindValue(":DATE_DEB", DATE_DEB);
    query.bindValue(":DATE_EXP",DATE_EXP);
    query.bindValue(":NB_PNTFID",res1);
    query.bindValue(":ID_CLIENT",res2);
    return query.exec();

}


QSqlQueryModel * abonnement::tri()
{
QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("SELECT * FROM abonnement ORDER BY CAST(ID_CLIENT AS number)");
       model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_AB"));
       model->setHeaderData(1,Qt::Horizontal, QObject::tr("DATE_DEB"));
       model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_EXP"));
       model->setHeaderData(3,Qt::Horizontal, QObject::tr("NB_PNTFID"));
       model->setHeaderData(4,Qt::Horizontal, QObject::tr("ID_CLIENT"));


    return model;
}
QSqlQueryModel * abonnement::tri30()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM abonnement ORDER BY CAST(ID_AB AS number)");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_AB"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("DATE_DEB"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_EXP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("NB_PNTFID"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
QSqlQueryModel * abonnement::tri20()
{
QSqlQueryModel * model=new QSqlQueryModel();
       model->setQuery("SELECT * FROM abonnement ORDER BY CAST(NB_PNTFID AS number)");
       model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_AB"));
       model->setHeaderData(1,Qt::Horizontal, QObject::tr("DATE_DEB"));
       model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_EXP"));
       model->setHeaderData(3,Qt::Horizontal, QObject::tr("NB_PNTFID"));
       model->setHeaderData(4,Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
QSqlQueryModel* abonnement::rechercheMulticritere(QString recherche)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM abonnement WHERE ID_AB LIKE '"+recherche+"%' OR DATE_DEB LIKE '"+recherche+"%' OR DATE_EXP LIKE '"+recherche+"%'OR NB_PNTFID LIKE '"+recherche+"%'");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_AB"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("DATE_DEB"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("DATE_EXP"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("NB_PNTFID"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("ID_CLIENT"));

    return model;
}
