#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Machine_f
{
    QString type,fab,num_fab;
    int id_mach,etat_mach;
public:
    //constructors


    Machine_f(){};
    Machine_f(int,QString,int,QString,QString);
    //getters
    int getid(){return id_mach;}
    QString gettype(){return type;}
    int getetat(){return etat_mach;}
    QString getfab(){return fab;}
    QString getnumfab(){return num_fab;}
    //setters
    void setid(int id){this->id_mach=id;}
    void settype(QString t){type=t;}
    void setetat(int e){etat_mach=e;}
    void setfab(QString f){fab=f;}
    void setnumfab(QString nf){num_fab=nf;}
    //focntions de base
    bool ajoutermach();
    bool supprimermach(int);
    bool modifiermach(int);
    QSqlQueryModel * affichermach();

    QSqlQueryModel * tri_fab();
    QSqlQueryModel * tri_type();
    QSqlQueryModel * tri_etat();
};

#endif // MACHINE_H
