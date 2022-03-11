#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraison.h"
#include <QDate>
#include <QString>
#include <QDateEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include "connection.h"
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
    QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit->setValidator(new QIntValidator(0,999999.,this));
    ui->tab_livraison->setModel(l.affi#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraison.h"
#include <QDate>
#include <QString>
#include <QDateEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include "connection.h"
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
    QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit->setValidator(new QIntValidator(0,999999.,this));
    ui->tab_livraison->setModel(l.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::title()
{
    setWindowTitle("Smart CleanApp");
}


void MainWindow::on_ajouter_clicked()
{
    int id_livr=ui->lineEdit->text().toInt();
    QString etat_livr=ui->lineEdit_2->text();
    QString num_livr=ui->lineEdit_3->text();
    QString adresse_livr=ui->lineEdit_4->text();
    QDate date_livr=ui->dateEdit->date();
    int id_commande=ui->lineEdit_5->text().toInt();

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



void MainWindow::on_supprimer_clicked()
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




void MainWindow::on_modifier_clicked()
{
    int id_livr=ui->lineEdit->text().toInt();
    QString etat_livr=ui->lineEdit_2->text();
    QString num_livr=ui->lineEdit_3->text();
    QString adresse_livr=ui->lineEdit_4->text();
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




