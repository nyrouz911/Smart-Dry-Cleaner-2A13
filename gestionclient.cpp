/*#include "gestionclient.h"
#include "ui_gestionclient.h"

gestionclient::gestionclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionclient)
{
    ui->setupUi(this);
}

gestionclient::~gestionclient()
{
    delete ui;
}*/
#include "gestionclient.h"
#include "ui_gestionclient.h"
#include "client.h"
#include"notification.h"
#include"abonnement.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QDebug>
#include<QApplication>
#include <QRegularExpressionValidator>

gestionclient::gestionclient(QWidget *parent)
    : QDialog(parent),
     ui(new Ui::gestionclient)
{
    ui->setupUi(this);


    ui->lineEdit_id->setValidator( new QIntValidator(0, 999999, this));
     ui->lineEdit_num->setValidator( new QIntValidator(0, 99999999, this));
     ui->lineEdit_id_ab->setValidator( new QIntValidator(0, 999999, this));
      ui->lineEdit_num_ab->setValidator( new QIntValidator(0, 9999, this));
      ui->lineEdit_point->setValidator( new QIntValidator(0, 9999, this));



    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                      QRegularExpression::CaseInsensitiveOption);
            ui->lineEdit_nom->setValidator(new QRegularExpressionValidator(rx, this));

            QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                          QRegularExpression::CaseInsensitiveOption);
                ui->lineEdit_prenom->setValidator(new QRegularExpressionValidator(rx1, this));

                QRegularExpression rx2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->lineEdit_adresse->setValidator(new QRegularExpressionValidator(rx2, this));
                    QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                                      QRegularExpression::CaseInsensitiveOption);



}


/*gestionclient::~gestionclient()
{
    delete ui;
    ui->tableView_interface->setModel(cl.afficher());
}*/


void gestionclient::on_pushButton_ajouter_clicked()
{
   Notification n;
    int ID_CL=ui->lineEdit_id->text().toInt();
   QString PRENOM_CL=ui->lineEdit_prenom->text();
   QString ADRESSE=ui->lineEdit_adresse->text();
   QString NOM_CL=ui->lineEdit_nom->text();
   QString TEL_CL=ui->lineEdit_num->text();

    client cl(ID_CL,PRENOM_CL,ADRESSE,NOM_CL,TEL_CL);
    bool test=cl.ajouter();
    if (test)

    {
        //ui
        n.notification_ajoutc();
        ui->tableView_interface->setModel(cl.afficher());
       QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("ajout effectuer. \n"
                           "click to exit"),QMessageBox::Cancel);
}
else
       QMessageBox ::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr ("ajout non effectuer. \n"
                                           "click to exit"),QMessageBox::Cancel);
}

void gestionclient::on_pushButton_supprimer_clicked()
{
    Notification n ;
    int ID_CL=ui->lineEdit_id->text().toInt();
    bool test1=cl.supprimer(ID_CL);

          if(test1)
         {
            n.notification_supprimerc();
            ui->tableView_interface->setModel(cl.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
        }
         else
        {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
         }


}



void gestionclient::on_pushButton_afficher_clicked()
{
      ui->tableView_interface->setModel(cl.afficher());
}

void gestionclient::on_pushButton_modifer_clicked()
{
         Notification n;
         int ID_CL=ui->lineEdit_id->text().toInt();
        QString PRENOM_CL=ui->lineEdit_prenom->text();
        QString ADRESSE=ui->lineEdit_adresse->text();
        QString NOM_CL=ui->lineEdit_nom->text();
        QString TEL_CL=ui->lineEdit_num->text();
          bool test2=cl.modifier(ID_CL,PRENOM_CL,ADRESSE,NOM_CL,TEL_CL);

            if(test2)
            {
                n.notification_modifierc();
                //Refresh affichage
                ui->tableView_interface->setModel(cl.afficher());
                QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
            }else
            {
                QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
            }


}

void gestionclient::on_pushButton_tri_id_clicked()
{
    ui->tableView_client->setModel(cl.tri());

}

void gestionclient::on_pushButton_tri_nom_clicked()
{
    ui->tableView_client->setModel(cl.tri2());
}

void gestionclient::on_pushButton_tri_prenom_clicked()
{
     ui->tableView_client->setModel(cl.tri1());
}

void gestionclient::on_pushButton_tri_num_clicked()
{
  ui->tableView_client->setModel(cl.tri3());
}

void gestionclient::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView_interface->setModel(cl.rechercheMulticritere(rech));
}


void gestionclient::on_pushButton_modifer_ab_clicked()
{
    Notification n;
    int ID_AB=ui->lineEdit_num_ab->text().toInt();
   QString DATE_DEB=ui->lineEdit_date_deb->text();
   QString DATE_EXP=ui->lineEdit_date_fin->text();
   int NB_PNTFID=ui->lineEdit_point->text().toInt();
   int ID_CLIENT=ui->lineEdit_id_ab->text().toInt();
     bool test2=a.modifier(ID_AB,DATE_DEB,DATE_EXP,NB_PNTFID,ID_CLIENT);

       if(test2)
       {
           n.notification_modifierab();
           //Refresh affichage
           ui->tableView_interface->setModel(cl.afficher());
           QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
       }else
       {
           QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
       }

}

void gestionclient::on_pushButton_supprimer_ab_clicked()
{
    Notification n ;
    int ID_AB=ui->lineEdit_num_ab->text().toInt();
    bool test1=a.supprimer(ID_AB);

          if(test1)
         {
            n.notification_supprimerab();
            ui->tableView_ab->setModel(a.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
        }
         else
        {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
         }

}

void gestionclient::on_pushButton_afficher_ab_clicked()
{
     ui->tableView_ab->setModel(a.afficher());
}

void gestionclient::on_pushButton_ajouter_ab_clicked()
{
    Notification n;
   int ID_AB=ui->lineEdit_num_ab->text().toInt();
   QString DATE_DEB=ui->lineEdit_date_deb->text();
   QString DATE_EXP=ui->lineEdit_date_fin->text();
   int NB_PNTFID=ui->lineEdit_point->text().toInt();
   int ID_CLIENT=ui->lineEdit_id_ab->text().toInt();

   abonnement a(ID_AB,DATE_DEB,DATE_EXP,NB_PNTFID,ID_CLIENT);
    bool test2=a.ajouterA();
    if (test2)

    {
        //ui
        n.notification_ajoutab();
        ui->tableView_ab->setModel(a.afficher());
       QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("ajout effectuer. \n"
                           "click to exit"),QMessageBox::Cancel);
}
else
       QMessageBox ::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr ("ajout non effectuer. \n"
                                           "click to exit"),QMessageBox::Cancel);
}



void gestionclient::on_pushButton_suivant_clicked()
{
ui->stackedWidget_ab->setCurrentIndex(1);
}

void gestionclient::on_pushButton_retour_ab_clicked()
{
ui->stackedWidget_ab->setCurrentIndex(0);
}

void gestionclient::on_pushButton_tri_id_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri());
}

void gestionclient::on_pushButton_tri_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri20());
}

void gestionclient::on_pushButton_tri_point_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri30());
}

void gestionclient::on_lineEdit_rech_ab_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_rech_ab->text();
    ui->tableView_ab->setModel(a.rechercheMulticritere(rech));
}

