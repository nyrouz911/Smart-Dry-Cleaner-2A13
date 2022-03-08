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
    int TEL_CL;
public:
    //constructeur
    client(){}
    client(int, QString, QString, QString, int);
    //getters

    int getID_CL(){return ID_CL;}
     QString getPRENOM_CL(){return PRENOM_CL;}
    QString getADRESSE(){return ADRESSE;}
    QString getNOM_CL(){return NOM_CL;}
    int getTEL_CL(){return TEL_CL;}
    //Settters
    void setID_CL(int ID_CL){this->ID_CL=ID_CL;}
     void setPRENOM_CL(QString p){PRENOM_CL=p;}
       void setADRESSE(QString a){ADRESSE=a;}
    void setNOM_CL(QString n){NOM_CL=n;}
    void setTEL_CL(int TEL_CL){this->TEL_CL=TEL_CL;}
    // Fonctionnalites de base relative a l'entite client
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);


    };

#endif // CLIENT_H
