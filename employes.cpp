#include "employes.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
//#include "gestionemployes.h"


using namespace std;

Employes::Employes()
{
   id_employee=0;
    nom=" ";
    prenom=" ";
    salaire=0;
    role=" ";
}

Employes::Employes( QString nom , QString prenom, int salaire , QString role )
{
    this->nom=nom;this->prenom=prenom;this->salaire=salaire;this->role=role;
}

QString Employes::getnom(){return nom;}
QString Employes::getprenom(){return prenom;}
int Employes::getsalaire(){return salaire; }
QString Employes::getrole(){return role;}

void Employes::setnom (QString nom){this->nom=nom;}
void Employes::setprenom (QString prenom){this->prenom=prenom;}
void Employes::setsalaire(int salaire){this->salaire=salaire;}
void Employes::setrole (QString role){this->role=role;}

bool Employes::ajouter()
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



bool Employes::supprimer(int id_employee )
{   QSqlQuery query;


         query.prepare("delete from EMPLOYEE where ID_EMPLOYEE=:id");
         query.bindValue(":id", id_employee);
         return query.exec();
}


QSqlQueryModel* Employes::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM EMPLOYEE");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));
    return model;
}

bool Employes::modifier(int id_employee,QString nom, QString prenom,int salaire,QString role)
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
QSqlQueryModel * Employes::tri()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY CAST(salaire AS number)");
    model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));

    return model;
}
QSqlQueryModel * Employes::tri1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM employee ORDER BY NOM");
        model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("id"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));

        return model;
}
QSqlQueryModel * Employes::tri2()
{
QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY PRENOM");
    model ->setHeaderData(0,Qt::Horizontal ,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));


    return model;
}

/*void Employee::chercherClient(int critere)
{
    QSqlQuery query;


    if(critere==1)
    {
        query.prepare("SELECT * FROM Employee WHERE id =:id " );
        query.bindValue(":id", id_employee);
        query.exec();




        while(query.next())
       {
            //this->id=query.value(0).toInt();

            this->nom=query.value(1).toString();
            this->prenom=query.value(2).toString();
            this->salaire=query.value(4).toInt();

       }
    }

}*/

QSqlQueryModel* Employes::RechercheByRole(QString r)
{
   QString res= role;
        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE role like '%"+r+"%'");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));
    return model;
}

QSqlQueryModel* Employes::RechercheByNom(QString r)
{
   QString res= nom;
        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE nom like '%"+r+"%'");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));
    return model;
}

QSqlQueryModel* Employes::RechercheByPrenom(QString r)
{
     QString res= prenom;
        QSqlQueryModel* model=new QSqlQueryModel();
    model ->setQuery("SELECT * FROM Employee WHERE prenom like '%"+r+"%'");
    model ->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model ->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model ->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model ->setHeaderData(3,Qt::Horizontal,QObject::tr("salaire"));
    model ->setHeaderData(4,Qt::Horizontal,QObject::tr("role"));
    return model;
}


