#ifndef COMMANDES_H
#define COMMANDES_H

#include "QString"
#include "QDate"
#include "connection.h"
#include "qr_code.h"
#include <string>

class Commandes
{
private:
    int idCommande,nbPieces,idClient,idEmploye;
    float montant;
    bool livrable,statut;
    QDate dateDepot,dateRetrait;


public:
    QR_Code qrCode;
    //constructeurs
    Commandes();
    Commandes(int nbPieces,int idClient,bool livrable,float montant,int idEmploye);

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
    bool modifierCommande(int nbPieces,int idEmploye,QString livrable,float montant,QDate dateRetrait,QString statut,int idCommande,int idClient);

    //Metiers
    QSqlQueryModel* TrierCommande(QString tri);
    QSqlQueryModel* Rechercher(QString query);
    QSqlQueryModel* Filtrer(QString query);

    //fonction complementaires
    QSqlQueryModel* remplirComboBoxClient();
    QSqlQueryModel* remplirComboBoxEmploye();
};

#endif // COMMANDES_H
