#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commandes.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficherCommande());

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::on_checkBox_clicked()
{

}

*/
void MainWindow::on_pushButton_3_clicked()//click sur le boutton ajouter
{
    int nbPieces= ui->spinBox->text().toInt();
    float montant= ui->lineEdit_7->text().toInt();

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

    Commandes nouvelleCommande(nbPieces,2,livrable,montant);
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

/*
void MainWindow::on_checkBox_stateChanged(int arg1)
{

}
*/

void MainWindow::on_pushButton_5_clicked()//appuie sur le boutton supprimer
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

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)//lorque double click sur l'index d'une commande dans le tableau
{
    QString idcommande= ui->tableView->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("Select montant,nbpieces,livrable,statut,date_retrait from commandes where  idcommande='"+idcommande+"'");
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

            ui->dateEdit_2->setDate(query.value(4).toDate());
        }
    }
}

void MainWindow::on_pushButton_clicked()//appuie sur le boutton modifier
{
    float montant=ui->lineEdit_3->text().toFloat();
    int nbPieces=ui->lineEdit_5->text().toUInt();
    int idEmploye=ui->comboBox_4->currentText().toInt();
    QString livrable=ui->spinBox->text();
    //QDate dateDepot=ui->dateEdit->date();
    QDate dateRetrait=ui->dateEdit_2->date();
    QString statut=ui->comboBox_3->currentText();
    int idCommande=ui->lineEdit_6->text().toInt();
    bool confirmationModification=Etmp.modifierCommande(nbPieces,idEmploye,livrable,montant,dateRetrait,statut,idCommande);

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
