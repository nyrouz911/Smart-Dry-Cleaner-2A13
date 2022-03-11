#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //afficher
    ui->setupUi(this);
    ui->tableView->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //ajouter
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    int salaire=ui->salaire->text().toFloat();
    QString role=ui->role->text();

    Employee e(nom,prenom,salaire,role);

        bool test=e.ajouter();
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("ajoute \n"
                                                 "click to cancel"), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
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
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
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
        QMessageBox::critical(nullptr, QObject::tr("not ok") , QObject::tr("non effecue"),QMessageBox::Cancel);


}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(e.afficher());
}
