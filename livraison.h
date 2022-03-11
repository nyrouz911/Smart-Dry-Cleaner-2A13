#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QTableView>
#include <QDate>
#include <QSqlQueryModel>
#include <QTextBrowser>

class livraison
{
public:
    //constructors
    livraison();
    livraison(int,QString,QString,QString,QDate,int);
    //getters

        int getID_LIVR();
        QString getETAT_LIVR();
        QString getNUM_LIVR();
        QString getADRESSE_LIVR();
        QDate getDATE_LIVR();
        int getID_COMMANDE();

    //setters

        void setID_LIVR(int);
        void setETAT_LIVR(QString);
        void setNUM_LIVR(QString);
        void setADRESSE_LIVR(QString);
        void setDATE_LIVR(QDate);
        void setID_COMMANDE(int);

     //fonctionalites
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(int id_livr);


private:
   int id_livr,id_commande;
   QString etat_livr,num_livr,adresse_livr;
   QDate date_livr;
};

#endif // LIVRAISON_H
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 #ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QTableView>
#include <QDate>
#include <QSqlQueryModel>
#include <QTextBrowser>

class livraison
{
public:
    //constructors
    livraison();
    livraison(int,QString,QString,QString,QDate,int);
    //getters

        int getID_LIVR();
        QString getETAT_LIVR();
        QString getNUM_LIVR();
        QString getADRESSE_LIVR();
        QDate getDATE_LIVR();
        int getID_COMMANDE();

    //setters

        void setID_LIVR(int);
        void setETAT_LIVR(QString);
        void setNUM_LIVR(QString);
        void setADRESSE_LIVR(QString);
        void setDATE_LIVR(QDate);
        void setID_COMMANDE(int);

     //fonctionalites
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(int id_livr);


private:
   int id_livr,id_commande;
   QString etat_livr,num_livr,adresse_livr;
   QDate date_livr;
};

#endif // LIVRAISON_H
