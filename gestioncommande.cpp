/*#include "gestioncommande.h"
#include "ui_gestioncommande.h"

gestioncommande::gestioncommande(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestioncommande)
{
    ui->setupUi(this);
}

gestioncommande::~gestioncommande()
{
    delete ui;
}
*/

#include "gestioncommande.h"
#include "ui_gestioncommande.h"
//#include "commandes.h"
#include <QMessageBox>
#include <QTranslator>

#include <string>

/* Pour l'envoi de SMS*/

#include <QtNetwork/QNetworkAccessManager>
#include <iostream>
#include <string>
#include <memory>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include "arduino.h"



gestioncommande::gestioncommande(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::gestioncommande)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficherCommande());
    ui->comboBox->setModel(Etmp.remplirComboBoxClient());//remplir la comboBox Client sur la page ajouter
    ui->comboBox_5->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Employe sur la page ajouter
    ui->comboBox_4->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Employe sur la page Modifier
    ui->comboBox_6->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Client sur la page Modifier

    /*Connection a la Carte Arduino*/
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
    //le slot update_label suite à la reception du signal readyRead (reception des données).

}

gestioncommande::~gestioncommande()
{
    delete ui;
}
/*
void MainWindow::on_checkBox_clicked()
{

}

*/
void gestioncommande::on_pushButton_3_clicked()//click sur le boutton ajouter
{
    bool IdEmploye_ok=true;
    bool IdClient_ok=true;
    bool nbPieces_ok=true;
    bool montant_ok=true;
    bool livrable_ok=true;
    bool paye_ok=true;

    ui->label_8->setText("");//Id Client
    ui->label_22->setText("");//Id Employe
    ui->label_23->setText("");//Nombre de pieces
    ui->label_26->setText("");//Montant
    ui->label_24->setText("");//parametre de livraison
    ui->label_25->setText("");//paye

    if(ui->comboBox->currentText().length()<=0)
        ui->label_8->setText("Id Client Invalide");
    else if(ui->comboBox_5->currentText().length()<=0)
        ui->label_22->setText("Id Employe Invalide");
    else if(ui->spinBox->text().toInt()==0)
        ui->label_23->setText("Nombre de pieces Invalide");
    else if(ui->lineEdit_7->text().toInt()<=0 || ui->lineEdit_7->text().length()<=0)
        ui->label_26->setText("Montant Invalide");
    else if((ui->checkBox->isChecked() && ui->checkBox_2->isChecked()) || (!ui->checkBox->isChecked() && !ui->checkBox_2->isChecked()))
        ui->label_24->setText("parametre de livraison Invalide");
    else if((ui->checkBox_5->isChecked() && ui->checkBox_6->isChecked()) || (!ui->checkBox_5->isChecked() && !ui->checkBox_6->isChecked()))
        ui->label_25->setText("Invalide");
    else
    {

        int nbPieces= ui->spinBox->text().toInt();
        float montant= ui->lineEdit_7->text().toInt();
        int IdEmploye=ui->comboBox_5->currentText().toInt();
        int IdClient=ui->comboBox->currentText().toInt();

        bool livrable=false;
        if(ui->checkBox->isChecked())
            livrable=true;
        else if(ui->checkBox_2->isChecked())
            livrable=false;

        bool paye=false;
        if(ui->checkBox_5->isChecked())
            paye=true;
        else if(ui->checkBox_6->isChecked())
            paye=false;

        Commandes nouvelleCommande(nbPieces,IdClient,livrable,montant,IdEmploye);
        bool confirmationAjout = nouvelleCommande.ajouterCommande();


        if(confirmationAjout)
        {
            ui->tableView->setModel(Etmp.afficherCommande());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("AJOUT EFFECTUE\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectue.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*
void MainWindow::on_checkBox_stateChanged(int arg1)
{

}
*/

void gestioncommande::on_pushButton_5_clicked()//appuie sur le boutton supprimer
{
    QModelIndex index= ui->tableView->currentIndex();
    int data= ui->tableView->model()->data(index).toInt();
    bool confirmationSuppression=Etmp.supprimerCommande(data);

    if(confirmationSuppression)
    {
        ui->tableView->setModel(Etmp.afficherCommande());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("SUPPRESSION EFFECTUE\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("SUPPRESSION non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestioncommande::on_tableView_activated(const QModelIndex &index)
{

}

void gestioncommande::on_tableView_doubleClicked(const QModelIndex &index)//lorque double click sur l'index d'une commande dans le tableau
{
    QString idcommande= ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("Select montant,nbpieces,livrable,statut,date_retrait,idEmploye,idClient from commandes where  idcommande='"+idcommande+"'");
    if(query.exec())
    {
        //remplissage des champs avec les donnees de la commande selectionne
        while(query.next())
        {
            ui->lineEdit_6->setText(idcommande);
            ui->lineEdit_3->setText(query.value(0).toString());
            ui->lineEdit_5->setText(query.value(1).toString());

            if(query.value(2).toString()=="Oui")
                ui->comboBox_2->setCurrentIndex(1);
            else if(query.value(2).toString()=="Non")
                ui->comboBox_2->setCurrentIndex(2);
            else
                ui->comboBox_2->setCurrentIndex(0);

            if(query.value(3).toString()=="Paye")
                ui->comboBox_3->setCurrentIndex(1);
            else if(query.value(3).toString()=="Non-Paye")
                ui->comboBox_3->setCurrentIndex(2);
            else
                ui->comboBox_3->setCurrentIndex(0);

            //ui->dateEdit_2->setDate(query.value(4).toDate());
            ui->dateEdit_2->setDateTime(query.value(4).toDateTime());
            ui->comboBox_4->setCurrentText(query.value(5).toString());
            ui->comboBox_6->setCurrentText(query.value(6).toString());
        }
    }
}

void gestioncommande::on_pushButton_clicked()//appuie sur le boutton modifier
{
    float montant=ui->lineEdit_3->text().toFloat();
    int nbPieces=ui->lineEdit_5->text().toUInt();
    int idEmploye=ui->comboBox_4->currentText().toInt();
    QString livrable=ui->comboBox_2->currentText();
    //QDate dateDepot=ui->dateEdit->date();
    QDate dateRetrait=ui->dateEdit_2->date();
    QString statut=ui->comboBox_3->currentText();
    int idCommande=ui->lineEdit_6->text().toInt();
    int idClient=ui->comboBox_6->currentText().toInt();
    bool confirmationModification=Etmp.modifierCommande(nbPieces,idEmploye,livrable,montant,dateRetrait,statut,idCommande,idClient);

    ui->lineEdit_6->setReadOnly(true);//on met de la commande en mode lecture uniquement

    if(confirmationModification)
    {
        ui->tableView->setModel(Etmp.afficherCommande());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("MODIFICATION EFFECTUE\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("MODIFICATION non effectue.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_Boutton_Afiche_Commades_clicked()//Boutton Afficher Commandes pour se deplacer dans la partie afficher Commandes
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_Boutton_aller_a_ajouterCommande_clicked()
{
    ui->comboBox->setModel(Etmp.remplirComboBoxClient());//remplir la comboBox Client sur la page ajouter
    ui->comboBox_5->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Employe sur la page ajouter
    ui->comboBox_4->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Employe sur la page Modifier
    ui->comboBox_6->setModel(Etmp.remplirComboBoxEmploye());//remplir la comboBox Client sur la page Modifier

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_comboBox_4_activated(int index)
{
    QSqlQuery query;
    query.prepare("select id_emp from Employes");
    if(query.exec())
    {
        while(query.next())
        {
            ui->comboBox_4->addItem(query.value(0).toString());
        }
    }
}

void MainWindow::on_tableWidget_2_cellChanged(int row, int column)
{
    //calcule des prix
    //float montantCouette=ui->tableWidget_2->item(1,0)->text().toFloat() * ui->tableWidget_2->item(1,1)->text().toFloat();
    //float montantDrap=ui->tableWidget_2->item(2,0)->text().toFloat() * ui->tableWidget_2->item(2,1)->text().toFloat();
    //float montantVeste=ui->tableWidget_2->item(row,column)->text().toFloat() * ui->tableWidget_2->item(row,column+1)->text().toFloat();
    //ui->tableWidget_2->item(row,column+2)->setText("ca fonctione");
    /*float montantPantalon=ui->tableWidget_2->item(4,0)->text().toFloat() * ui->tableWidget_2->item(4,1)->text().toFloat();
    float montantRobe=ui->tableWidget_2->item(5,0)->text().toFloat() * ui->tableWidget_2->item(5,1)->text().toFloat();
    float montantCostume=ui->tableWidget_2->item(6,0)->text().toFloat() * ui->tableWidget_2->item(6,1)->text().toFloat();
    float montantChaussure=ui->tableWidget_2->item(7,0)->text().toFloat() * ui->tableWidget_2->item(7,1)->text().toFloat();
*/

}
/*
void MainWindow::on_tableWidget_2_itemChanged(QTableWidgetItem *item)
{

}
*/

void MainWindow::on_checkBox_8_stateChanged(int arg1)//etat du checkbox montant croissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(montantCroissant && !montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("montantCroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_9_stateChanged(int arg1)//etat du checkbox montant decroissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("montantDecroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_10_stateChanged(int arg1)//etat du checkbox datedepot croissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("dateDepotCroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_11_stateChanged(int arg1)//etat du checkbox datedepot decroissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && !dateDepotCroissant && dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("dateDepotDecroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_12_stateChanged(int arg1)//etat du checkbox dateRetrait croissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("dateRetraitCroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_13_stateChanged(int arg1)//etat du checkbox dateRetrait decroissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && dateRetraitDecroissant && !nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("dateRetraitDecroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_14_stateChanged(int arg1)//etat du checkbox nbpieces croissant change
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && nbPiecesCroissant && !nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("nbpiecesCroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_15_stateChanged(int arg1)
{
    bool montantCroissant=ui->checkBox_8->isChecked();
    bool montantDecroissant=ui->checkBox_9->isChecked();
    bool dateDepotCroissant=ui->checkBox_10->isChecked();
    bool dateDepotDecroissant=ui->checkBox_11->isChecked();
    bool dateRetraitCroissant=ui->checkBox_12->isChecked();
    bool dateRetraitDecroissant=ui->checkBox_13->isChecked();
    bool nbPiecesCroissant=ui->checkBox_14->isChecked();
    bool nbPiecesDecroissant=ui->checkBox_15->isChecked();

    if(!montantCroissant && !montantDecroissant && !dateDepotCroissant && !dateDepotDecroissant && !dateRetraitCroissant && !dateRetraitDecroissant && !nbPiecesCroissant && nbPiecesDecroissant)
        ui->tableView->setModel(Etmp.TrierCommande("nbpiecesDecroissant"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    QString query=ui->lineEdit_4->text();
    if(query.length()>0)
        ui->tableView->setModel(Etmp.Rechercher(query));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)//l'etat de la case livrable change
{
    bool livrable=ui->checkBox_3->isChecked();
    bool nonLivrable=ui->checkBox_16->isChecked();
    bool paye=ui->checkBox_4->isChecked();
    bool nonPaye=ui->checkBox_7->isChecked();

    if(livrable && !nonLivrable && !paye && !nonPaye)
        ui->tableView->setModel(Etmp.Filtrer("livrable"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_16_stateChanged(int arg1)//l'etat de la case nonlivrable change
{
    bool livrable=ui->checkBox_3->isChecked();
    bool nonLivrable=ui->checkBox_16->isChecked();
    bool paye=ui->checkBox_4->isChecked();
    bool nonPaye=ui->checkBox_7->isChecked();

    if(!livrable && nonLivrable && !paye && !nonPaye)
        ui->tableView->setModel(Etmp.Filtrer("nonLivrable"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)//l'etat de la case paye change
{
    bool livrable=ui->checkBox_3->isChecked();
    bool nonLivrable=ui->checkBox_16->isChecked();
    bool paye=ui->checkBox_4->isChecked();
    bool nonPaye=ui->checkBox_7->isChecked();

    if(!livrable && !nonLivrable && paye && !nonPaye)
        ui->tableView->setModel(Etmp.Filtrer("paye"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_checkBox_7_stateChanged(int arg1)//l'etat de la case nonPaye change
{
    bool livrable=ui->checkBox_3->isChecked();
    bool nonLivrable=ui->checkBox_16->isChecked();
    bool paye=ui->checkBox_4->isChecked();
    bool nonPaye=ui->checkBox_7->isChecked();

    if(!livrable && !nonLivrable && !paye && nonPaye)
        ui->tableView->setModel(Etmp.Filtrer("nonPaye"));
    else
        ui->tableView->setModel(Etmp.afficherCommande());
}

void MainWindow::on_pushButton_7_clicked()//click sur le boutton imprimer Recu
{
    //recuperer l'identifiant de la commande
    QModelIndex index= ui->tableView->currentIndex();
    QString data= ui->tableView->model()->data(index).toString();

    QString idCommande,montant,nbpieces,idEmploye,idClient,dateRetrait,dateDepot;

    QSqlQuery query;
    query.prepare("Select montant,nbpieces,date_retrait,idEmploye,idClient,date_depot from commandes where  idcommande='"+data+"'");
    if(query.exec())
    {
        //remplissage des champs avec les donnees de la commande selectionne
        while(query.next())
        {

            /*string s = "geeksforgeeks";

                int n = s.length();

                // declaring character array
                char char_array[n + 1];

                // copying the contents of the
                // string to char array
                strcpy(char_array, s.c_str());*/



            std::string idCommandeQr=""+data.toStdString();

            int n = idCommandeQr.length();
            char char_array[n + 1];  //chaine qui va contenir l'identifiant a etre encode
            strcpy(char_array, idCommandeQr.c_str());//copie de la chaine qui va contenir l'identifiant a etre encode

            montant=query.value(0).toString();
            nbpieces=query.value(1).toString();
            dateRetrait=query.value(2).toDateTime().toString();
            idEmploye=query.value(3).toString();
            idClient=query.value(4).toString();
            dateDepot=query.value(5).toDateTime().toString();

            if(dateRetrait.length()<=0)//on affecte la date actuel au recu si la date de retrait est vide
            {
                QDate dateCourrante;dateCourrante.currentDate();
                dateRetrait=dateCourrante.currentDate().toString();
            }


            //generation du code QR
            std::vector<uint8_t> bytes(char_array, char_array + std::strlen(char_array));
            const QrCode qr = QrCode::encodeSegments(
            {QrSegment::makeBytes(bytes)},
                        QrCode::Ecc::HIGH);


            Etmp.qrCode.printRecu(qr,idCommandeQr,montant.toStdString(),nbpieces.toStdString(),idEmploye.toStdString(),idClient.toStdString(),dateRetrait.toStdString(),dateDepot.toStdString());

        }
    }
}

void MainWindow::on_pushButton_2_clicked()//Pour calculer le total
{
    QString temp;

    float montantCouette=ui->tableWidget_2->item(1,0)->text().toFloat() * ui->tableWidget_2->item(1,1)->text().toFloat();

    float montantDrap=ui->tableWidget_2->item(2,0)->text().toFloat() * ui->tableWidget_2->item(2,1)->text().toFloat();
    float montantVeste=ui->tableWidget_2->item(3,0)->text().toFloat() * ui->tableWidget_2->item(3,1)->text().toFloat();
    float montantPantalon=ui->tableWidget_2->item(4,0)->text().toFloat() * ui->tableWidget_2->item(4,1)->text().toFloat();
    float montantRobe=ui->tableWidget_2->item(5,0)->text().toFloat() * ui->tableWidget_2->item(5,1)->text().toFloat();
    float montantCostume=ui->tableWidget_2->item(6,0)->text().toFloat() * ui->tableWidget_2->item(6,1)->text().toFloat();
    float montantChaussure=ui->tableWidget_2->item(7,0)->text().toFloat() * ui->tableWidget_2->item(7,1)->text().toFloat();

    float total = montantCouette+montantDrap+montantVeste+montantPantalon+montantRobe+montantCostume+montantChaussure;
    temp.setNum(total);

    ui->lineEdit_7->setText(temp);
    ui->lineEdit_6->setReadOnly(true);

}

void MainWindow::on_pushButton_10_clicked()//Clique sur le boutton Pour envoyer un SMS au client pour qu'il vienne retirer sa commande
{
    //recuperer l'identifiant de la commande
    QModelIndex index= ui->tableView->currentIndex();
    QString data= ui->tableView->model()->data(index).toString();

    QString idCommande,idClient,dateDepot,telephoneClient,nomCLient,prenomClient;

    QSqlQuery query;
    query.prepare("Select idClient,date_depot from commandes where  idcommande='"+data+"'");


    /*Collect des deifferntes informations necessaires a l'envoi du SMS*/
    if(query.exec())
    {
        while(query.next())
        {
            idClient=query.value(0).toString();
            dateDepot=query.value(1).toDateTime().toString();

            QSqlQuery query2;
            query2.prepare("Select NOM_CL,PRENOM_CL,TEL_CL from CLIENT where  ID_CL='"+idClient+"'");
            if(query2.exec())
            {
                while(query2.next())
                {
                    nomCLient=query2.value(0).toString();
                    prenomClient=query2.value(1).toString();
                    telephoneClient=query2.value(2).toString();
                }
            }
        }
    }


    /* Test avec Twilio*/

    //    std::string account_sid;
    //            std::string auth_token="0c0628d5afc7bcb4879c6b6213027905";
    //            std::string message_body="test";
    //            std::string from_number="+17752568912";
    //            std::string to_number="+21650953183";
    //            std::string picture_url;
    //            bool verbose = false;


    //            CURL *curl;
    //                    curl_global_init(CURL_GLOBAL_ALL);
    //                    curl = curl_easy_init();

    //                    // Percent encode special characters
    //                    char *message_body_escaped = curl_easy_escape(
    //                            curl,
    //                            message_body.c_str(),
    //                            0
    //                    );

    //                    std::stringstream url;
    //                            std::string url_string;
    //                            url << "https://api.twilio.com/2010-04-01/Accounts/" << account_sid
    //                                    << "/Messages";
    //                            url_string = url.str();


    //                            std::stringstream parameters;
    //                            std::string parameter_string;
    //                            parameters << "To=" << to_number << "&From=" << from_number
    //                                    << "&Body=" << message_body_escaped;

    //                            if (!picture_url.empty()) {
    //                                            parameters << "&MediaUrl=" << picture_url;
    //                                    }
    //                                    parameter_string = parameters.str();

    //                                    curl_easy_setopt(curl, CURLOPT_POST, 1);
    //                                            curl_easy_setopt(curl, CURLOPT_URL, url_string.c_str());
    //                                            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, parameter_string.c_str());
    //                                            curl_easy_setopt(curl, CURLOPT_USERNAME, account_sid.c_str());
    //                                            curl_easy_setopt(curl, CURLOPT_PASSWORD, auth_token.c_str());

    //                                            CURLcode res = curl_easy_perform(curl);

    //                                            curl_free(message_body_escaped);
    //                                                    curl_easy_cleanup(curl);




}


/* Test avec Twilio*/
// Envoi du Message

//*Twilio Acconut Informations*/
//std::string  account_sid="AC3049195d11d3126225e8777d49f94f40",
//        auth_token="0c0628d5afc7bcb4879c6b6213027905";
//std::string twilioNumber= "+17752568912";

//bool verbose = false;
//std::string response;
//std::string emptyImageURL;
//std::string message="Cher(e) "+prenomClient.toStdString()+" "+nomCLient.toStdString()+", votre Commande numero: "+idCommande.toStdString()+" deposé le "+dateDepot.toStdString()+" est prete. Vous Pouvez desormais passer la recuperer";

//        // Instantiate a twilio object and call send_message
//        auto twilio = std::make_shared<twilio::Twilio>(
//            account_sid,
//            auth_token
//        );


//        /*std::string account_sid;
//                std::string auth_token;*/
//                //std::string message;
//                std::string from_number;
//                std::string to_number;
//                std::string picture_url;
//                //bool verbose = false;



//        //const std::string t=""+telephoneClient.toStdString(),tw=""+twilioNumber,m=""+message,r=""+reponse,eu=""+emptyImageURL;
//        /*bool message_success = twilio->send_message(
//                telephoneClient.toStdString(), //numero du client
//                twilioNumber,
//                message,
//                reponse,
//                emptyImageURL,
//                verbose
//        );*/
//                bool message_success = twilio->send_message(
//                                to_number,
//                                from_number,
//                                message,
//                                response,
//                                picture_url,
//                                verbose
//                        );


//        // Report success or failure. Rapport sur l'envoi du message
//                if (!message_success) {
//                        if (verbose) {
//                                /*std::cout << "Message send failed." << std::endl;
//                                 if (!response.empty()) {
//                                        std::cout << "Response:" << std::endl
//                                                << response << std::endl;
//                                }*/

//                            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
//                                                  QObject::tr("Le SMS n'a pas pu etre envoyé.\n"
//                                                              "Click Cancel to exit."), QMessageBox::Cancel);

//                        }
//                } else if (verbose) {
//                        /*std::cout << "SMS sent successfully!" << std::endl;
//                        std::cout << "Response:" << std::endl << response
//                                << std::endl;*/

//                    QMessageBox::information(nullptr,QObject::tr("OK"),
//                                             QObject::tr("SMS envoyé avec succes\n"
//                                                         "Click Cancel to exit."), QMessageBox::Cancel);

//                }




/*QString url="https://api.twilio.com/2010-04-01/Accounts/AC3049195d11d3126225e8777d49f94f40/Messages.json";
QString auth = "AC3049195d11d3126225e8777d49f94f40:0c0628d5afc7bcb4879c6b6213027905";

QNetworkAccessManager *netManager;
QNetworkReply *netReply;
QNetworkReply *repoReply;
QByteArray dataBuffer;
QPixmap *img;

QString body="test";
QString Sender="+17752568912";

/*https://api.twilio.com/2010-04-01/Accounts/{AccountSid}/Messages.json*/

//https://username:password@api.twilio.com/2010-04-01/your_desired_path


/*QNetworkRequest requete{QUrl(QString("https://api.twilio.com/2010-04-01/Accounts/AC3049195d11d3126225e8777d49f94f40/Messages.json?to").arg(telephoneClient,Sender,body))};
netReply=netManager->get(requete);*/



void MainWindow::on_pushButton_11_clicked()//Clique sur le boutton Definir Langue
{
    bool ok;
    QTranslator Langue;
    QTranslator traductionInterface;
    QString LangueChoisi= ui->comboBox_7->currentText();

    /*
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok)
    {
        //on met linterface dans la langue choisi
    }
    else
    {
        //on met l'interface dans la langue par defaut
    }*/

    if(LangueChoisi=="Anglais" || LangueChoisi=="English")
    {
        Langue.load(":/english.qm");
        traductionInterface.load("C:\Qt\Qt5.9.9\5.9.9\mingw53_32\translations/qtbase_en.qm");
        this->show();
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("You Are Now In English\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::update_label()//Mise a jour de la partie "Attribuer des Points de Fidelite" Quand des donnes sont recu de la carte Arduino
{
    data=A.read_from_arduino();//recuperation de L'id de la commande envoye a partir de la carte Arduino
    QString idCommande= data;
    ui->label_35->setText(data);

    QString idClient,IdAbonnement,nbPointsActuels,nbPointsGagne,montant;

    QSqlQuery query;
    query.prepare("Select montant,idClient from commandes where  idcommande='"+idCommande+"'");
    if(query.exec())
    {
        //remplissage des champs avec les donnees de la commande selectionne
        while(query.next())
        {
            montant=query.value(0).toString();
            idClient=query.value(1).toString();

        }

        ui->label_11->setText(idClient);
    }

    /*Calcul du nombre de Point de Fidelite*/
    int nbPoints = montant.toInt()/10;
    nbPointsGagne = QString::number(nbPoints);
    ui->label_36->setText(nbPointsGagne);


    /*Recuperation des Information de L'abonnement*/
    query.prepare("Select id_ab,nb_pntfid from abonnement where  id_client='"+idClient+"'");
    if(query.exec())
    {
        //remplissage des champs avec les donnees de la commande selectionne
        while(query.next())
        {
            IdAbonnement=query.value(0).toString();
            nbPointsActuels=query.value(1).toString();

        }

        ui->label_32->setText(nbPointsActuels);
        ui->label_30->setText(IdAbonnement);

    }

    /*Calcul du nouveau nombre de Points*/
    int nouveauNombrePoints = nbPointsActuels.toInt() + nbPoints;
    ui->label_38->setText(QString::number(nouveauNombrePoints));
    //QString nouveauNbPoints=QString::number(nouveauNombrePoints);




}

void MainWindow::on_pushButton_9_clicked()//Pour aller a la partie "afficher les commandes" apartir de "attribuer point de fidelite"
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_13_clicked()//Pour aller a la partie "ajouter une nouvelle commande" apartir de "attribuer point de fidelite"
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()//Pour aller a la partie "attribuer point de fidelite" apartir de "ajouter une nouvelle commande"
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_15_clicked()//Pour aller a la partie "attribuer point de fidelite" apartir de "ajouter une nouvelle commande"
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery query;
    QString nouveauNbPoints,idClient;
    int nbPoints;

    nouveauNbPoints=ui->label_38->text();
    idClient=ui->label_11->text();
    nbPoints=ui->label_36->text().toInt();

    QByteArray toArduino = QByteArray::number(nbPoints);

    /*Mise a jour du nombre de points*/
    query.prepare("update abonnement set nb_pntfid='"+nouveauNbPoints+"' where id_client='"+idClient+"'");
    if(query.exec())
    {
        if(A.write_to_arduino(toArduino)!=-1)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("POINTS ATTRIBUE AVEC SUCCES\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}
