#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDialog>

class client
{
    int ID_CL;
    QString NOM_CL,PRENOM_CL;
    QString ADRESSE;
    QString TEL_CL;
public:
    //constructeur
    client(){}
    client(int, QString, QString, QString, QString);
    //getters

    int getID_CL(){return ID_CL;}
     QString getPRENOM_CL(){return PRENOM_CL;}
    QString getADRESSE(){return ADRESSE;}
    QString getNOM_CL(){return NOM_CL;}
     QString getTEL_CL(){return TEL_CL;}
    //Settters
    void setID_CL(int c){this->ID_CL=c;}
     void setPRENOM_CL(QString p){PRENOM_CL=p;}
       void setADRESSE(QString a){ADRESSE=a;}
       void setNOM_CL(QString n){NOM_CL=n;}
       void setTEL_CL(QString t){TEL_CL=t;}
    // Fonctionnalites de base relative a l'entite client
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel * tri();
         QSqlQueryModel * tri1();
         QSqlQueryModel * tri2();
         QSqlQueryModel * tri3();
         QSqlQueryModel * rechercheMulticritere(QString);


    };

#endif // CLIENT_H
