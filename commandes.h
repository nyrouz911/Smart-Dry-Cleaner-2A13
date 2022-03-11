#ifndef COMMANDES_H
#define COMMANDES_H

#include "QString"
#include "QDate"
#include "connection.h"

class Commandes
{
private:
    int idCommande,nbPieces,idClient,idEmploye;
    float montant;
    bool livrable,statut;
    QDate dateDepot,dateRetrait;

public:
    //constructeurs
    Commandes();
    Commandes(int nbPieces,int idClient,bool livrable,float montant);

    //Getters
    int getIdCommades(){return idCommande;};
    float getMontant(){return montant;};
    int getNbPieces(){return nbPieces;};
    int getIdClient(){return idClient;};
    int getIdEmploye(){return idEmploye;};
    bool getStatut(){return statut;};


    //Setters
    void setStatut(bool statut){this->statut=statut;};
    void setIdEmploye(int idEmploye){this->idEmploye=idEmploye;};
    void setLivrable(bool livrable){this->livrable=livrable;};
    void setMontant(float montant){this->montant=montant;};

    //CRUDs
    bool ajouterCommande();
    bool supprimerCommande(int idCommande);
    QSqlQueryModel* afficherCommande();
    bool modifierCommande(int nbPieces,int idEmploye,QString livrable,float montant,QDate dateRetrait,QString statut,int idCommande);
};

#endif // COMMANDES_H


/*
#ifndef PERSONNEL_H
    #define PERSONNEL_H
    #include <QString>
    #include <QSqlQuery>
    #include <QSqlQueryModel>
    #include <QDate>
#include "connection.h"
    class Personnel
    {
    private:
        QString nom,prenom,ville,adresse;
        int age;
        long int cin,tel;
        QDate date_naissance;
    public:
        Personnel();
        Personnel(QString,QString,int,QDate,QString,QString,int,int);
       //getters
        QString getNom(){return  nom;}
        QString getPrenom(){return  prenom;}
        int getCin(){return  cin;}
        int getTel(){return tel;}
        QDate getDate(){return  date_naissance;}
        QString getVille(){return  ville;}
        QString getAdresse(){return adresse;}
        int getAge(){return age;}
        //setters
        void setNom(QString n){nom = n;};
        void setPrenom(QString n){prenom = n;};
        void setCin(int n){cin = n;};
        void setDate(QDate n){date_naissance = n;};
        void setVille(QString n){ville = n;};
        void setAdresse(QString n){adresse = n;};
        void setAge(int n){age = n;};
        void setTel(int t){tel = t;}
        //Crud(fonction bassique)
        bool ajouter();
        bool modifier(int);
        bool supprimer(int);
        QSqlQueryModel *rechercher(QString);
        QSqlQueryModel *afficher();
        QSqlQueryModel *Trie_Nom_A();
        QSqlQueryModel *Trie_age_A();
        QSqlQueryModel *Trie_Nom_D();
        QSqlQueryModel *Trie_age_D();

    };

    #endif // PERSONNEL_H
*/
