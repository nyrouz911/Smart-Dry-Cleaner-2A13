#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QDialog>

class abonnement
{
    int ID_CLIENT;
   int ID_AB;
    QString DATE_DEB,DATE_EXP;
    int NB_PNTFID;
public:

    //constructeur
    abonnement(){}
    abonnement( int, QString , QString, int, int);
    //getters

     int getID_AB(){return ID_AB;}
    QString getDATE_DEB(){return DATE_DEB;}
    QString getDATE_EXP(){return DATE_EXP;}
     int getNB_PNTFID(){return NB_PNTFID;}
      int getID_CLIENT(){return ID_CLIENT;}
    //Settters
     void setID_AB(int A){this->ID_AB=A;}
       void setDATE_DEB(QString d){DATE_DEB=d;}
       void setDATE_EXP(QString F){DATE_EXP=F;}
       void setNB_PNTFID(int N){this->NB_PNTFID=N;}
        void setID_CLIENT(int c){this->ID_CLIENT=c;}

    // Fonctionnalites de base relative a l'entite client
    bool ajouterA();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,int);
    QSqlQueryModel * tri();
    QSqlQueryModel * tri20();
    QSqlQueryModel * tri30();
    QSqlQueryModel * rechercheMulticritere(QString);
};

#endif // ABONNEMENT_H
