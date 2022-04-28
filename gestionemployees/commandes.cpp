#include "commandes.h"

Commandes::Commandes()
{

}

Commandes::Commandes(int nbPieces,int idClient,bool livrable,float montant,int idEmploye)
{
    QDate dateCourrante;

    this->nbPieces=nbPieces;
    this->idClient=idClient;
    this->dateDepot=dateCourrante.currentDate();
    this->livrable=livrable;
    this->montant=montant;
    this->idEmploye=idEmploye;
}


//getters



//setters

bool Commandes::ajouterCommande()
{
     QSqlQuery query;

     QString nbPiecesStr = QString::number(nbPieces);
     QString montantStr = QString::number(montant);
     QString idEmployeStr = QString::number(idEmploye);
     QString idClientStr = QString::number(idClient);



    query.prepare("insert into commandes (montant,nbpieces,livrable,statut,date_depot,idEmploye,idClient)" "values(:montant,:nbpieces,:livrable,:statut,:date_depot,:idEmploye,:idClient)");


    //creation des variables

    query.bindValue(":nbpieces",nbPiecesStr);
    query.bindValue(":montant",montantStr);
    query.bindValue(":date_depot",dateDepot);
    query.bindValue(":idEmploye",idEmployeStr);
    query.bindValue(":idClient",idClientStr);

    if(statut==true)
        query.bindValue(":statut","Paye");
    else if(statut==false)
        query.bindValue(":statut","Non-Paye");

    if(livrable==true)
        query.bindValue(":livrable","Oui");
    else if(livrable==false)
        query.bindValue(":livrable","Non");

    return query.exec();
}




bool Commandes::supprimerCommande(int idCommande)
{
    QSqlQuery query;
    QString idCommandeStr = QString::number(idCommande);

    query.prepare("Delete from commandes where idcommande = :idcommande");
    query.bindValue(":idcommande",idCommandeStr);

    return  query.exec();
}


QSqlQueryModel* Commandes::afficherCommande()
{
    QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from commandes");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idCommande"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("idClient"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));

     return model;
}

QSqlQueryModel* Commandes::remplirComboBoxClient()
{
    QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from CLIENT");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CL"));
     return model;
}//comboBox_5

QSqlQueryModel* Commandes::remplirComboBoxEmploye()
{
    QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from EMPLOYES");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EMP"));
     return model;
}

bool Commandes::modifierCommande(int nbPieces,int idEmploye,QString livrable,float montant,QDate dateRetrait,QString statut,int idCommande,int idClient)
{
    QSqlQuery query;

    QString nbPiecesStr = QString::number(nbPieces);
    QString montantStr = QString::number(montant);
    QString idCommandeStr = QString::number(idCommande);
    QString idEmployeStr = QString::number(idEmploye);
    QString idClientStr = QString::number(idClient);

    query.prepare("update commandes set montant= :montant,nbpieces= :nbpieces,livrable= :livrable,statut= :statut,date_retrait=:date_retrait,idEmploye=:idEmploye,idClient=:idClient where idcommande = :idcommande");
    query.bindValue(":nbpieces",nbPiecesStr);
    query.bindValue(":montant",montantStr);
    query.bindValue(":idcommande",idCommandeStr);
    query.bindValue(":livrable",livrable);
    query.bindValue(":statut",statut);
    query.bindValue(":date_retrait",dateRetrait);
    query.bindValue(":idEmploye",idEmployeStr);
    query.bindValue(":idClient",idClientStr);
    return  query.exec();
}


QSqlQueryModel* Commandes::TrierCommande(QString tri)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(tri=="montantCroissant")
        model->setQuery("select * from commandes order by montant asc");
    else if(tri=="montantDecroissant")
        model->setQuery("select * from commandes order by montant desc");
    else if(tri=="dateDepotCroissant")
        model->setQuery("select * from commandes order by date_depot asc");
    else if(tri=="dateDepotDecroissant")
        model->setQuery("select * from commandes order by date_depot desc");
    else if(tri=="dateRetraitCroissant")
        model->setQuery("select * from commandes order by date_retrait asc");
    else if(tri=="dateRetraitDecroissant")
        model->setQuery("select * from commandes order by date_retrait desc");
    else if(tri=="nbpiecesCroissant")
        model->setQuery("select * from commandes order by nbpieces asc");
    else if(tri=="nbpiecesDecroissant")
        model->setQuery("select * from commandes order by nbpieces desc");


     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idCommande"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("idClient"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));

     return model;
}



QSqlQueryModel* Commandes::Rechercher(QString query)
{
    QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from commandes where idCommande like '%"+query+"%' or idClient like '%"+query+"%' or idEmploye like '%"+query+"%' ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idCommande"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("idClient"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));

     return model;
}

QSqlQueryModel* Commandes::Filtrer(QString query)
{
    QSqlQueryModel * model = new QSqlQueryModel();

     if(query=="livrable")
        model->setQuery("select * from commandes where livrable='Oui'");
     else if(query=="nonLivrable")
         model->setQuery("select * from commandes where livrable='Non'");
     else if(query=="paye")
         model->setQuery("select * from commandes where statut='Paye'");
     else if(query=="nonPaye")
         model->setQuery("select * from commandes where statut='Non-Paye'");

     /*model->setHeaderData(0,Qt::Horizontal,QObject::tr("idCommande"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("idClient"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Montant"));*/

     return model;
}





/*
    Personnel::Personnel()
    {
        this->nom = " ";
        this->prenom = " ";
        this->cin = 0;
        this->date_naissance = QDate();
        this->ville = " ";
        this->adresse = " ";
        this->age = 0;
        this->tel = 0;
    }

    Personnel::Personnel(QString n,QString p,int c,QDate d,QString v,QString ad,int ag,int t)
    {
        this->nom = n;
        this->prenom = p;
        this->cin = c;
        this->date_naissance = d;
        this->ville = v;
        this->adresse = ad;
        this->age = ag;
        this->tel = t;
    }


    bool Personnel::ajouter()
    {
     QSqlQuery query;
     QString res = QString::number(cin);
     QString ag_res = QString::number(age);
     QString t_res = QString::number(tel);
     //prepare() prend la requete en parametre pour la preparer a l'execution;

       query.prepare("insert into gs_personnels(nom,prenom,cin,date_naissance,age,ville,adresse,telephone)""values(:nom,:prenom,:cin,:date_naissance,:age,:ville,:adresse,:tel)");
     //creation des variable liees;
       query.bindValue(":cin",res);
       query.bindValue(":nom",nom);
       query.bindValue(":prenom",prenom);
       query.bindValue(":date_naissance",date_naissance);
       query.bindValue(":age",ag_res);
       query.bindValue(":ville",ville);
       query.bindValue(":adresse",adresse);
       query.bindValue(":tel",t_res);

       return query.exec(); //envoi la requete pour l'executer
    }

    QSqlQueryModel *Personnel::afficher()
    {
      QSqlQueryModel * model = new QSqlQueryModel();
       model->setQuery("select * from gs_personnels");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("DateNaissance"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("Age"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("Telephone"));
       model->setHeaderData(6,Qt::Horizontal,QObject::tr("Adresse"));
       model->setHeaderData(7,Qt::Horizontal,QObject::tr("Ville"));

       return model;
    }

    //QString nom,QString prenom,int cin,QDate date_naissance,int age,QString ville,QString adresse,int tel)
    bool Personnel::modifier(int cin)
    {
      QSqlQuery query;
      QString res = QString::number(cin);
      QString ag_res = QString::number(age);
      QString t_res = QString::number(tel);
      query.prepare("Update gs_personnels set nom=:nom,prenom=:prenom,date_naissance=:date_naissance,age=:age,ville=:ville,adresse=:adresse,telephone=:tel where cin=:cin");
      query.bindValue(":cin",res);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":date_naissance",date_naissance);
      query.bindValue(":age",ag_res);
      query.bindValue(":ville",ville);
      query.bindValue(":adresse",adresse);
      query.bindValue(":tel",t_res);

      return query.exec();
    }

    bool Personnel::supprimer(int)
    {
        QSqlQuery query;
        QString res = QString::number(cin);
        query.prepare("Delete from gs_personnels where cin = :cin");
        query.bindValue(":cin",res);

        return  query.exec();
    }


    QSqlQueryModel *Personnel::rechercher(QString q)
    {
        QString res= QString::number(cin);
        QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM gs_personnels  WHERE nom like '%"+q+"%'" );

         return model;
    }


    QSqlQueryModel *Personnel::Trie_Nom_A()
    {
        QSqlQueryModel * model = new QSqlQueryModel();
         model->setQuery("select * from gs_personnels order by nom,prenom ASC");

         return model;
    }

    QSqlQueryModel *Personnel::Trie_age_A()
    {
        QSqlQueryModel * model = new QSqlQueryModel();
         model->setQuery("select * from gs_personnels order by age,date_naissance ASC");

         return model;
    }
*/
