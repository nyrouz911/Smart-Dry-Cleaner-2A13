#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpproduit.afficher());
    ui->lineEdit->setValidator( new QIntValidator(0, 999999, this));
    ui->lineEdit_4->setValidator( new QIntValidator(0, 999999, this));
    ui->lineEdit_3->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
            QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fournisseur,type_machine;
        int id_produit , quantite,prix_unitaire;



    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty()|| ui->lineEdit_4->text().isEmpty()|| ui->lineEdit_5->text().isEmpty())
    {
        ui->tableView ->setModel(tmpproduit.afficher());//refresh
        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                             QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else{
        id_produit=ui->lineEdit->text().toInt();
        fournisseur=ui->lineEdit_2->text();
        quantite=ui->lineEdit_3->text().toInt();
        prix_unitaire=ui->lineEdit_4->text().toInt();
        type_machine=ui->lineEdit_5->text();





 produit p(id_produit,fournisseur, quantite , prix_unitaire, type_machine);

     bool test= p.ajouter();

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                                     QObject::tr("  produit ajouté.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpproduit.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un  produit"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}



void MainWindow::on_pushButton_2_clicked()
{
    QString  fournisseur,type_machine;
        int id_produit,quantite,prix_unitaire;

        id_produit=ui->lineEdit->text().toInt();
        fournisseur=ui->lineEdit_2->text();
        quantite=ui->lineEdit_3->text().toInt();
        prix_unitaire=ui->lineEdit_4->text().toInt();
        type_machine=ui->lineEdit_5->text();



         produit p (id_produit,fournisseur,quantite,prix_unitaire,type_machine);


         bool test =p.modifier(p.getid_produit(),p.getfournisseur(), p.getquantite(), p.getprix_unitaire(), p.gettype_machine());

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                                     QObject::tr("  produit Modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpproduit.afficher());//refresh
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier un produit"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}




void MainWindow::on_pushButton_3_clicked()
{ int id_produit=ui->lineEdit->text().toInt();
    produit p;
    bool test=p.supprimer(id_produit);
    ui->tableView->setModel(tmpproduit.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer produit"),
                                 QObject::tr("produit supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
