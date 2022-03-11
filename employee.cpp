#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

using namespace std;

Employee::Employee()
{
    nom=" ";
    prenom=" ";
    salaire=0;
    role=" ";
}

Employee::Employee( QString nom , QString prenom, int salaire , QString role )
{
    this->nom=nom;this->prenom=prenom;this->salaire=salaire;this->role=role;
}

QString Employee::getnom(){return nom;}
QString Employee::getprenom(){return prenom;}
int Employee::getsalaire(){return salaire; }
QString Employee::getrole(){return role;}

void Employee::setnom (QString nom){this->nom=nom;}
void Employee::setprenom (QString prenom){this->prenom=prenom;}
void Employee::setsalaire(int salaire){this->salaire=salaire;}
void Employee::setrole (QString role){this->role=role;}

bool Employee::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id_employee);
    //QString salaire_string=QString::number(salaire);

         query.prepare("INSERT INTO EMPLOYEE (nom, prenom,salaire,role ) "
                       "VALUES (:nom, :prenom, :salaire, :role )");
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":salaire", salaire);
         query.bindValue(":role", role);
         return query.exec();
}



bool Employee::supprimer(int id_employee )
{   QSqlQuery query;


         query.prepare("delete from EMPLOYEE where ID_EMPLOYEE=:id");
         query.bindValue(":id", id_employee);
         return query.exec();
}


QSqlQueryModel* Employee::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM EMPLOYEE");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));
    return model;
}

bool Employee::modifier(int id_employee,QString nom, QString prenom,int salaire,QString role)
{
        QSqlQuery query;
        query.prepare("UPDATE EMPLOYEE SET NOM=(?),PRENOM=(?),SALAIRE=(?),ROLE=(?) where ID_EMPLOYEE=(?) ");

        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(salaire);
        query.addBindValue(role);
        query.addBindValue(id_employee);
   return  query.exec();
}
