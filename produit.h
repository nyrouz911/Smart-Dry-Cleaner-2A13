#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>


class produit
{
private:
    QString fournisseur,type_machine,image;
        int id_produit , quantite,prix_unitaire ;

public:
    produit();
    produit(int id_produit,QString fournisseur,int quantite ,int prix_unitaire,QString type_machine,QString image){
        this->id_produit = id_produit ;
        this->quantite = quantite;
        this->fournisseur=fournisseur;
        this->prix_unitaire=prix_unitaire;
        this->type_machine=type_machine;
        this->image=image;

    }
    void setid_produit(int id_produit){this->id_produit=id_produit;}
    int getid_produit(){return this->id_produit;}
    void setfournisseur(QString fournisseur){this->fournisseur=fournisseur;}
    QString getfournisseur(){return this->fournisseur;}
    void setquantite(int quantite){this->quantite=quantite;}
    int getquantite(){return this->quantite;}
    void setprix_unitaire(int prix_unitaire){this->prix_unitaire=prix_unitaire;}
    int getprix_unitaire(){return this->prix_unitaire;}
    void settype_machine(int type_machine){this->type_machine=type_machine;}
    QString gettype_machine(){return this->type_machine;}


    bool ajouter();
    bool modifier(int id_produit/*,QString fournisseur,int quantite ,int prix_unitaire,QString type_machine*/);
    bool supprimer(int id_produit);
    QSqlQueryModel * recherche(QString id_produit);
    QSqlQueryModel * recherchefournisseur(QString fournisseur);
    QSqlQueryModel * recherchequantite(QString fournisseur);
    QSqlQueryModel * rechercheprix(QString prix_unitaire);
    QSqlQueryModel * recherchetype(QString type_machine);
    QSqlQueryModel * afficher();
    //QSqlQueryModel*  tri(QString id_produit);
    QSqlQueryModel * tri(QString type_machine);
    QSqlQueryModel * AfficherTriprix();
};

#endif
