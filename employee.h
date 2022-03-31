#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQueryModel>

class Employee
{
public:
    Employee();
    Employee(QString,QString,int,QString);
    //GET
    int getid();
    QString getnom();
    QString getprenom();
    int getsalaire();
    QString getrole();

    //SET
    void setnom (QString);
    void setprenom (QString);
    void setsalaire(int);
    void setrole(QString);

    //FN
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id_employee);
    bool modifier(int,QString,QString,int,QString);
   QSqlQueryModel* RechercheByRole(QString);
   QSqlQueryModel* RechercheByNom(QString);
   QSqlQueryModel* RechercheByPrenom(QString);
    QSqlQueryModel* tri();
    QSqlQueryModel* tri1();
    QSqlQueryModel* tri2();


 private:
    QString nom , prenom , role;
    int id_employee, salaire ;
};

#endif // EMPLOYEE_H

