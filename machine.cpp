#include "machine.h"
#include "gestionmachine.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QVBoxLayout>

Machine_f::Machine_f(int id_mach,QString type,int etat_mach,QString fab,QString num_fab)
{
    this->id_mach=id_mach;
    this->type=type;
    this->etat_mach=etat_mach;
    this->fab=fab;
    this->num_fab=num_fab;
}

bool Machine_f::ajoutermach()
{
    QSqlQuery query;
    QString res= QString::number(id_mach);


    query.prepare("insert into machines (id_mach,type,etat_mach,fab,num_fab) values (:id_mach,:type,:etat_mach,:fab,:num_fab)");

    query.bindValue(":id_mach",res);
    query.bindValue(":type",type);
    query.bindValue(":etat_mach",etat_mach);
    query.bindValue(":fab",fab);
    query.bindValue(":num_fab",num_fab);

    return query.exec();
}


QSqlQueryModel * Machine_f::affichermach()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("select * from machines");

    return model;
}

bool Machine_f::supprimermach(int id_mach)
{
    QSqlQuery query;
    QString res=QString::number(id_mach);
    query.prepare("Delete from machines where id_mach=:id_mach");
    query.bindValue(":id_mach",res);

    return query.exec();
}

bool Machine_f::modifiermach(int id_mach)
{
    QSqlQuery query;
    query.prepare("Update machines set type=:type,etat_mach=:etat_mach,fab=:fab,num_fab=:num_fab where id_mach=:id_mach");
    query.bindValue(":id_mach",id_mach);
    query.bindValue(":type",type);
    query.bindValue(":etat_mach",etat_mach);
    query.bindValue(":fab",fab);
    query.bindValue(":num_fab",num_fab);

    return query.exec();
}

QSqlQueryModel *Machine_f::tri_fab()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  Machines ORDER BY fab ");
    q->exec();
    model->setQuery(*q);
    return model;
}


QSqlQueryModel *Machine_f::tri_type()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  Machines ORDER BY type ");
    q->exec();
    model->setQuery(*q);
    return model;
}

QSqlQueryModel *Machine_f::tri_etat()
{

    QSqlQuery *q = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    q->prepare("SELECT * FROM  Machines ORDER BY etat_mach ");
    q->exec();
    model->setQuery(*q);
    return model;
}




