#include "intervention.h"

intervention::intervention(int id_main,QString type_main , int etat_main, QString descr_main , QDate date_main, int id_mach)
{
    this->id_main=id_main;
    this->type_main=type_main;
    this->etat_main=etat_main;
    this->descr_main=descr_main;
    this->date_main=date_main;
    this->id_mach=id_mach;
}

bool intervention::ajoutermain()
{
    QSqlQuery query;
    QString res= QString::number(id_main);


    query.prepare("insert into interventions (id_main,type_main,etat_main,descr_main,date_main) values (:id_main,:type_main,:etat_main,:descr_main,:date_main,:id_mach)");

    query.bindValue(":id_main",res);
    query.bindValue(":type",type_main);
    query.bindValue(":etat_mach",etat_main);
    query.bindValue(":descr_main",descr_main);
    query.bindValue(":date_main",date_main);
    query.bindValue(":id_mach",id_mach);

    return query.exec();

}

QSqlQueryModel * intervention::affichermain()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("select * from interventions");

    return model;
}

bool intervention::supprimermain(int id_main)
{
    QSqlQuery query;
    QString res=QString::number(id_main);
    query.prepare("Delete from interventions where id_main=:id_main");
    query.bindValue(":id_main",res);

    return query.exec();
}


bool intervention::modifiermain(int id_main)
{
    QSqlQuery query;
    query.prepare("Update interventions set type_main=:type_main,etat_main=:etat_main,descr_main=:descr_main,date_main=:date_main, :id_mach=id_mach where id_main=:id_main");
    query.bindValue(":id_mach",id_main);
    query.bindValue(":type_main",type_main);
    query.bindValue(":etat_main",etat_main);
    query.bindValue(":descr_main",descr_main);
    query.bindValue(":date_main",date_main);
    query.bindValue(":id_mach",id_mach);

    return query.exec();
}


//QSqlQueryModel * intervention::cherchermain(QString id_main)
//{
//    QSqlQueryModel * model= new QSqlQueryModel();

//    model->setQuery("SELECT * FROM INTERVENTIONS WHERE ID_MACH LIKE '%"+id_main+"%'" );

//    model->query().bindValue(":ID_MAIN",id_main);
//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MAIN"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE_MAIN"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ETAT_MAIN"));
//    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCR_MAIN"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_MAIN"));
//    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ID_MACH"));

//    return model;
//}


