#include "gestionemployes.h"
#include "ui_gestionemployes.h"
#include "employes.h"
#include "client.h"
#include "notification.h"
#include "abonnement.h"
#include "livraison.h"
#include "qr_code.h"
#include "qrcodegen.h"
#include "commandes.h"
#include <QMessageBox>
#include "QMessageBox"
#include <QApplication>
#include <QIntValidator>
#include <QStackedWidget>
#include <QDateEdit>
#include <QSqlQuery>
#include <QComboBox>
#include <QDialog>
#include <QDate>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QFontDialog>
#include <QIntValidator>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>



/*gestionemployes::gestionemployes(QWidget *parent):
    QDialog(parent)
    , ui(new Ui::gestionemployes)*/
gestionemployes::gestionemployes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionemployes)
{
    //afficher
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
    ui->AfficherMessage->setModel(m.afficherM());

    //CS MAYSSEN
    ui->lineEdit_5->setValidator( new QIntValidator(0, 999999, this));
    ui->salaire->setValidator( new QIntValidator(0, 999999, this));


    //CS NOUR
    ui->lineEdit_id->setValidator( new QIntValidator(0, 999999, this));
     ui->lineEdit_num->setValidator( new QIntValidator(0, 99999999, this));
     ui->lineEdit_id_ab->setValidator( new QIntValidator(0, 999999, this));
      ui->lineEdit_num_ab->setValidator( new QIntValidator(0, 9999, this));
      ui->lineEdit_point->setValidator( new QIntValidator(0, 9999, this));


      //CS MAYSSEN
    QRegularExpression rx4("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                      QRegularExpression::CaseInsensitiveOption);
            ui->nom->setValidator(new QRegularExpressionValidator(rx4, this));

            QRegularExpression rx5("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                          QRegularExpression::CaseInsensitiveOption);
                ui->prenom->setValidator(new QRegularExpressionValidator(rx5, this));

                QRegularExpression rx6("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                              QRegularExpression::CaseInsensitiveOption);
                    ui->role->setValidator(new QRegularExpressionValidator(rx6, this));


            //CS NOUR
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

             // CS BRAHYM
                                    QRegExp rx10("[a-zA-Z]+");
                                    QValidator *validator = new
                                    QRegExpValidator(rx10,this);
                                    //ui->lineEdit_2->setValidator(validator);
                                    ui->lineEdit_3->setValidator(new QIntValidator(0,99999999.,this));
                                    ui->lineEdit_4->setValidator(validator);
                                    //ui->lineEdit->setValidator(new QIntValidator(0,999999.,this));
                                    //ui->tab_livraison->setModel(l.afficher());
                                    // ui->textBrowser->hide();


             //CS NAYROUZ
                                    ui->id_mach_mod->setValidator( new QIntValidator(0, 999999, this));
                                    ui->num_fab->setValidator( new QIntValidator(0, 99999999, this));
                                    QRegularExpression rx80("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                    QRegularExpression::CaseInsensitiveOption);
                                    ui->type_mach->setValidator(new QRegularExpressionValidator(rx80, this));
                                    QRegularExpression rx81("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                    QRegularExpression::CaseInsensitiveOption);
                                    ui->fab->setValidator(new QRegularExpressionValidator(rx81, this));
                                    QRegularExpression rx83("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
                                    QRegularExpression::CaseInsensitiveOption);



}
//BOUTONS MAYSSEN (employee)

void gestionemployes::on_pushButton_clicked()
{
    //ajouter
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int salaire=ui->salaire->text().toFloat();
    QString role=ui->role->text();

    Employes e(nom,prenom,salaire,role);

        bool test=e.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);

}

void gestionemployes::on_pushButton_2_clicked()
{
    //supprimer
    int id=ui->lineEdit_5->text().toUInt();
    bool test=e.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("supprimé \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);

}

void gestionemployes::on_pushButton_3_clicked()
{
    //modifier
    int id=ui->lineEdit_6->text().toUInt();
    QString nom=ui->lineEdit_7->text();
    QString prenom=ui->lineEdit_8->text();
    int salaire=ui->lineEdit_9->text().toFloat();
    QString role=ui->lineEdit_10->text();
    bool test=e.modifier(id,nom,prenom,salaire,role);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modifié \n"
                                             "click to cancel"), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);


}

void gestionemployes::on_pushButton_4_clicked()
//afficher2.0
{
    ui->tableView->setModel(e.afficher());
}

void gestionemployes::on_pushButton_5_clicked()
{
    QMessageBox msgBox;

        QSqlQuery query;
        QString nom="",prenom="",role="";
        int critere=ui->comboBox->currentIndex();

        if(critere==2)
        {
             role=ui->lineEdit->text();

             ui->tableView->setModel(e.RechercheByRole(role));

             query.bindValue(":role", role);
             query.exec();
        }
           else if(critere==0)
           {
               nom=ui->lineEdit->text();
               ui->tableView->setModel(e.RechercheByNom(nom));
               query.bindValue(":nom", nom);
               query.exec();

           }
           else if(critere==1)
           {
               prenom=ui->lineEdit->text();
               ui->tableView->setModel(e.RechercheByPrenom(prenom));
               query.bindValue(":prenom", prenom);
               query.exec();
           }
}

void gestionemployes::on_pushButton_6_clicked()
{
    ui->tableView->setModel(e.tri());
}


void gestionemployes::on_pushButton_7_clicked()
{
    ui->tableView->setModel(e.tri1());
}

void gestionemployes::on_pushButton_8_clicked()
{
    ui->tableView->setModel(e.tri2());
}

void gestionemployes::on_comboBox_activated(const QString &arg1)
{

}

void gestionemployes::on_pushButton_9_clicked() // français
{
    /*ui->label_2->setText("Nom");
    ui->label_3->setText("Prénom");
    ui->label_4->setText("Salaire");
    ui->label_5->setText("Role");
    ui->label_8->setText("Nom");
    ui->label_9->setText("Prénom");
    ui->label_10->setText("Salaire");
    ui->label_11->setText("Role");

    ui->pushButton_5->setText("chercher");
    ui->send->setText("envoyer");
    //ui->bind->setText("connect");
    //ui->pushButton_9->setText("Français");
    //ui->pushButton_10->setText("Anglais");
    ui->pushButton_7->setText("tri nom");
    ui->pushButton_8->setText("tri prenom");
    ui->pushButton_6->setText("tri salaire");
    ui->pushButton_4->setText("Actualiser");
    ui->label_14->setText("message");*/

    ui->stackedWidget->setCurrentIndex(2);
}

void gestionemployes::on_pushButton_10_clicked() // anglais
{
       ui->label_2->setText("Name");
       ui->label_3->setText("Surname");
       ui->label_4->setText("Salary");
       ui->label_5->setText("Role");
       ui->label_8->setText("Name");
       ui->label_9->setText("Surname");
       ui->label_10->setText("Salary");
       ui->label_11->setText("Role");
       ui->pushButton_5->setText("Reseach");
       ui->send->setText("send");
       ui->pushButton_7->setText("Sorte by Name");
       ui->pushButton_8->setText("Sorte by Surname");
       ui->pushButton_6->setText("Sorte by Salary");
       ui->pushButton_4->setText("Update");
       ui->label_14->setText("message");



}

void gestionemployes::on_send_clicked()
{
    //ajouter
    QString message=ui->message->text();
    Message m(message);

        //bool test=
                m.ajouterM();
       /* if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecute"),QMessageBox::Cancel);*/

}



void gestionemployes::on_afficherM_clicked()
{
    ui->AfficherMessage->setModel(m.afficherM());
}

void gestionemployes::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void gestionemployes::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void gestionemployes::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void gestionemployes::on_pushButton_33_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}





// BOUTONS NOUR (client)
void gestionemployes::on_pushButton_ajouter_clicked()
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

void gestionemployes::on_pushButton_supprimer_clicked()
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



void gestionemployes::on_pushButton_afficher_clicked()
{
      ui->tableView_interface->setModel(cl.afficher());
}

void gestionemployes::on_pushButton_modifer_clicked()
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

void gestionemployes::on_pushButton_tri_id_clicked()
{
    ui->tableView_client->setModel(cl.tri());

}

void gestionemployes::on_pushButton_tri_nom_clicked()
{
    ui->tableView_client->setModel(cl.tri2());
}

void gestionemployes::on_pushButton_tri_prenom_clicked()
{
     ui->tableView_client->setModel(cl.tri1());
}

void gestionemployes::on_pushButton_tri_num_clicked()
{
  ui->tableView_client->setModel(cl.tri3());
}

void gestionemployes::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView_interface->setModel(cl.rechercheMulticritere(rech));
}


void gestionemployes::on_pushButton_modifer_ab_clicked()
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

void gestionemployes::on_pushButton_supprimer_ab_clicked()
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

void gestionemployes::on_pushButton_afficher_ab_clicked()
{
     ui->tableView_ab->setModel(a.afficher());
}

void gestionemployes::on_pushButton_ajouter_ab_clicked()
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



void gestionemployes::on_pushButton_suivant_clicked()
{
ui->stackedWidget_ab->setCurrentIndex(1);
}

void gestionemployes::on_pushButton_retour_ab_clicked()
{
ui->stackedWidget_ab->setCurrentIndex(0);
}

void gestionemployes::on_pushButton_tri_id_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri());
}

void gestionemployes::on_pushButton_tri_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri20());
}

void gestionemployes::on_pushButton_tri_point_ab_clicked()
{
    ui->tableView_ab_2->setModel(a.tri30());
}

void gestionemployes::on_lineEdit_rech_ab_textChanged(const QString &arg1)
{
    QString rech=ui->lineEdit_rech_ab->text();
    ui->tableView_ab->setModel(a.rechercheMulticritere(rech));
}

//BOUTONS BRAHYM (livraison)
void gestionemployes::on_ajouter_3_clicked()

{
    int id_livr=ui->lineEdit_3->text().toInt();
    QString etat_livr=ui->lineEdit_4->text();
    QString num_livr=ui->lineEdit_17->text();
    QString adresse_livr=ui->lineEdit_19->text();
    QDate date_livr=ui->dateEdit->date();
    int id_commande=ui->lineEdit_18->text().toInt();

   livraison l(id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande);


      bool test1=l.ajouter();
      if(test1)
    {

    QMessageBox::information(nullptr, QObject::tr("Ajouter une livraison"),
                      QObject::tr("Livraison ajoutée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

           ui->tab_livraison->setModel(l.afficher());

    }
      else
    {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une livraison"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    }

}//end



void gestionemployes::on_supprimer_clicked()
{
   livraison bs;
   bs.setID_LIVR(ui->lineEdit_6->text().toInt());
   bool test2=bs.supprimer(bs.getID_LIVR());
   if(test2)
 {

 QMessageBox::information(nullptr, QObject::tr("supprimer une livraison"),
                   QObject::tr("livraison supprime.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

 ui->tab_livraison->setModel(bs.afficher());

 }
   else
 {
             QMessageBox::critical(nullptr, QObject::tr("supprimer une livraison"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
 }
}




void gestionemployes::on_modifier_clicked()
{
    int id_livr=ui->lineEdit->text().toInt();
    QString etat_livr=ui->lineEdit_4->text();
    QString num_livr=ui->lineEdit_3->text();
    QString adresse_livr=ui->lineEdit_19->text();
    QDate date_livr=ui->dateEdit->date();
    int id_commande=ui->lineEdit_5->text().toInt();


          livraison l(id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande);
        bool test=l.modifier(id_livr);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier une livraison"),
                                     QObject::tr("  Livraison Modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_livraison->setModel(l.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier une livraison"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}





void gestionemployes::on_chercherid_clicked()
{
    ui->tab_livraison->setModel(l.recherche_id(ui->tttt->text()));
}

void gestionemployes::on_cherchedate_clicked()
{
    ui->tab_livraison->setModel(l.recherche_date(ui->tttt->text()));
}

void gestionemployes::on_cherchernum_clicked()
{
    ui->tab_livraison->setModel(l.recherche_numlivreur(ui->tttt->text()));
}

void gestionemployes::on_trierid_clicked()
{
    ui->tab_livraison->setModel(l.trier_id());
}

void gestionemployes::on_trierdate_clicked()
{
    ui->tab_livraison->setModel(l.trier_date());
}

void gestionemployes::on_triernum_clicked()
{
    ui->tab_livraison->setModel(l.trier_numlivreur());
}

/*void gestionlivraison::on_generer_clicked()
 {
    l.exporterpdf(ui->textBrowser);
}*/

void gestionemployes::on_Francais_clicked()
{

        ui->label->setText("ID Livraison");
        ui->label_2->setText("Etat Livraison");
        ui->label_3->setText("Num Livreur");
        ui->label_7->setText("ID Commande");
        ui->label_4->setText("Date");
        ui->label_5->setText("Adresse");
        ui->label_6->setText("ID Livraison");
        ui->label_8->setText("Chercher par :");
        ui->label_9->setText("Trier par : ");
        //ui->ajouter->setText("Ajouter");
        //ui->modifier->setText("Modifer");
       // ui->supprimer->setText("Supprimer");
        ui->trierid->setText("ID");
        ui->trierdate->setText("DATE");
        ui->triernum->setText("NUM LIVREUR");
        ui->chercherid->setText("Chercher");
        ui->generer->setText("Generer PDF");
        ui->Excel->setText("Generer EXCEL");
        ui->Francais->setText("Fr");
        ui->Anglais->setText("An");

}

void gestionemployes::on_Anglais_clicked()
{
    ui->label->setText("Delivery ID");
    ui->label_2->setText("State Delivery");
    ui->label_3->setText("Delivery Number");
    ui->label_7->setText("Order ID");
    ui->label_4->setText("Date");
    ui->label_5->setText("Address");
    ui->label_6->setText("Delivery ID");
    ui->label_8->setText("Search by :");
    ui->label_9->setText("Sort by : ");
    //ui->ajouter->setText("Add");
    //ui->modifier->setText("Modify");
    //ui->supprimer->setText("Delete");
    ui->trierid->setText("ID");
    ui->trierdate->setText("DATE");
    ui->triernum->setText("DELIVERY NUMBER");
    ui->chercherid->setText("Search");
    ui->generer->setText("Generate PDF");
    ui->Excel->setText("Generate EXCEL");
    ui->Francais->setText("Fr");
    ui->Anglais->setText("En");
}

void gestionemployes::on_Excel_clicked()
{
    QTableView *table;
                       table = ui->tab_livraison;

                       QString filters("CSV files (.xlsx);;All files (.*)");
                       QString defaultFilter("CSV files (*.xlsx)");
                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                          filters, &defaultFilter);
                       QFile file(fileName);

                       QAbstractItemModel *model =  table->model();
                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                           QTextStream data(&file);
                           QStringList strList;
                           for (int i = 0; i < model->columnCount(); i++) {
                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") << "\n";
                           for (int i = 0; i < model->rowCount(); i++) {
                               strList.clear();
                               for (int j = 0; j < model->columnCount(); j++) {

                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") + "\n";
                           }
                           file.close();
                           QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                                     QObject::tr("Export avec succes .\n"
                                                                 "Click OK to exit."), QMessageBox::Ok);
                       }
    }
    QString currDate()
    {
        QDate date = QDate::currentDate();
        return date.toString("dd.MM.yyyy");
}





void gestionemployes::on_pushButton_livraison_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void gestionemployes::on_pushButton_retourb_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

// BOUTONS NAYROUZ (machine)

void gestionemployes::on_ajouter_2_clicked()
{

    int id_mach=ui->id_mach_mod->text().toInt();
    QString type=ui->type_mach->text();
    int etat_mach=ui->etat_mach->currentIndex();
    QString fab=ui->fab->text();
    QString num_fab=ui->num_fab->text();

Machine_f m(id_mach,type,etat_mach,fab,num_fab);

   bool test=m.ajoutermach();

    if(test)
    {

        //refresh
        ui->tableViewN->setModel(Machtmp.affichermach());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestionemployes::on_modifier_2_clicked()
{
    int id_mach=ui->id_mach_mod->text().toInt();
    QString type=ui->type_mach->text();
    int etat_mach=ui->etat_mach->currentIndex();
    QString fab=ui->fab->text();
    QString num_fab=ui->num_fab->text();


    Machine_f m(id_mach,type,etat_mach,fab,num_fab);
    bool test = m.modifiermach(id_mach);

    //refresh
    ui->tableView->setModel(Machtmp.affichermach());

    if(test){
        QMessageBox::information(nullptr, QObject::tr("update status"),QObject::tr("Machine updated.\nClick Cancel to exit."), QMessageBox::Cancel,QMessageBox::NoIcon);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("update status"),QObject::tr("Machine not updated.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestionemployes::on_supprimer_2_clicked()
{
    int id_mach=ui->id_mach_sup->text().toInt();
    bool test=Machtmp.supprimermach(id_mach);

    //refresh
    ui->tableView->setModel(Machtmp.affichermach());
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
void gestionemployes::on_chercher_textChanged(const QString &arg1)
{
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM MACHINES WHERE ID_MACH  LIKE'"+arg1+"%' or TYPE  LIKE'"+arg1+"%' or ETAT_MACH  LIKE'"+arg1+"%' or FAB LIKE'"+arg1+"%' or NUM_FAB  LIKE'"+arg1+"%' or ID_PROD  LIKE'"+arg1+"%'  ");
        query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->tableView->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !!\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->chercher->clear();}
    }
}

void gestionemployes::on_trifab_clicked()
{

        ui->tableView->setModel(Machtmp.tri_fab());

}

void gestionemployes::on_tritype_clicked()
{
    ui->tableView->setModel(Machtmp.tri_type());
}

void gestionemployes::on_trietat_clicked()
{
    ui->tableView->setModel(Machtmp.tri_etat());
}

void gestionemployes::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void gestionemployes::on_retourbrahym_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

//boutons miguel (commandes)




void gestionemployes::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void gestionemployes::on_pushButton_29_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

void gestionemployes::on_pushButton_27_clicked()
{
    /*QSqlQuery query;
    QString nouveauNbPoints,idClient;
    int nbPoints;

    nouveauNbPoints=ui->label_38->text();
    idClient=ui->label_11->text();
    nbPoints=ui->label_36->text().toInt();

    QByteArray toArduino = QByteArray::number(nbPoints);

   // Mise a jour du nombre de points
    query.prepare("update abonnement set nb_pntfid='"+nouveauNbPoints+"' where id_client='"+idClient+"'");
    if(query.exec())
    {
        if(A.write_to_arduino(toArduino)!=-1)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("POINTS ATTRIBUE AVEC SUCCES\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }*/
}

void gestionemployes::on_Boutton_Afiche_Commades_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void gestionemployes::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void gestionemployes::on_pushButton_13_clicked()
{
   ui->stackedWidget->setCurrentIndex(6);
}


void gestionemployes::on_modifier_3_clicked()
{

    int id_livr=ui->lineEdit_3->text().toInt();
    QString etat_livr=ui->lineEdit_4->text();
    QString num_livr=ui->lineEdit_17->text();
    QString adresse_livr=ui->lineEdit_19->text();
    QDate date_livr=ui->dateEdit->date();
    int id_commande=ui->lineEdit_18->text().toInt();

          livraison l(id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande);
        bool test=l.modifier(id_livr);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier une livraison"),
                                     QObject::tr("  Livraison Modifiée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tab_livraison->setModel(l.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier une livraison"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void gestionemployes::on_supprimer_3_clicked()
{
    livraison bs;
    bs.setID_LIVR(ui->lineEdit_20->text().toInt());
    bool test2=bs.supprimer(bs.getID_LIVR());
    if(test2)
  {

  QMessageBox::information(nullptr, QObject::tr("supprimer une livraison"),
                    QObject::tr("livraison supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  ui->tab_livraison->setModel(bs.afficher());

  }
    else
  {
              QMessageBox::critical(nullptr, QObject::tr("supprimer une livraison"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  }
}
