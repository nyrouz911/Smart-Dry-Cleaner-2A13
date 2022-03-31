#ifndef INTERVENTION_H
#define INTERVENTION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class intervention
{
    QString type_main,descr_main;
    int id_main,etat_main,id_mach;
    QDate date_main;
public:
    //constructors

    intervention(){};
    intervention(int,QString,int,QString,QDate,int);
    //getters
    int getid_main(){return id_main;}
    QString gettype_main(){return type_main;}
    int getetat_main(){return etat_main;}
    QString getdescr_main(){return descr_main;}
    QDate getdate_main(){return date_main;}
    int getid_mach(){return id_mach;}
    //setters
    void setid_main(int id){this->id_main=id;}
    void settype_main(QString t){type_main=t;}
    void setetat_main(int e){etat_main=e;}
    void setdescr_main(int d){this->descr_main=d;}
    void setid_mach(int id_m){this->id_mach=id_m;}
    //focntions de base
    bool ajoutermain();
    bool supprimermain(int);
    bool modifiermain(int);
    QSqlQueryModel * affichermain();
    QSqlQueryModel * cherchermain(QString);
};




#endif // INTERVENTION_H
