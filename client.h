#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QPainter>
#include <QGraphicsItem>


class client
{
private:
    QString nomcl ,prenomcl,adr,idc;
        int num, nbpt;

public:
    client();
    client(QString idc,QString nomcl, int num,int nbpt ,QString prenomcl ,QString adr){
        this->idc = idc ;
        this->prenomcl = prenomcl;
        this->adr=adr;
        this->nomcl=nomcl;
        this->num=num;
        this->nbpt=nbpt;



    }
    void setidc(int idc){this->idc=idc;}
    QString getidc(){return this->idc;}
    void setnomcl(QString nomcl){this->nomcl=nomcl;}
    QString getnomcl(){return this->nomcl;}
    void setprenomcl(int prenomcl){this->prenomcl=prenomcl;}
    QString getprenomcl(){return this->prenomcl;}
    void setadr(int adr){this->adr=adr;}
    QString getadr(){return this->adr;}
    void setnum(int num){this->num=num;}
    int getnum(){return this->num;}
    void setnbpt(int nbpt){this->nbpt=nbpt;}
    int getnbpt(){return this->nbpt;}

    bool ajouter();
    bool modifier(QString idc);
    bool supprimer(QString idc);

    QSqlQueryModel * afficher();
};

#endif // MATERIEL_H
