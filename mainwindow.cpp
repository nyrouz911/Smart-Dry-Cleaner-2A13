#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include<QDebug>
#include<QApplication>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_id->setValidator( new QIntValidator(0, 999999, this));
     ui->lineEdit_num->setValidator( new QIntValidator(0, 99999999, this));



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


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int ID_CL=ui->lineEdit_id->text().toInt();
    QString NOM_CL=ui->lineEdit_nom->text();
     QString PRENOM_CL=ui->lineEdit_prenom->text();
    QString ADRESSE=ui->lineEdit_adresse->text();
    int TEL_CL=ui->lineEdit_num->text().toInt();

    client cl(ID_CL,NOM_CL,PRENOM_CL,ADRESSE,TEL_CL);
    bool test=cl.ajouter();
    if (test)

    {

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

void MainWindow::on_pushButton_supprimer_clicked()
{
    int ID_CL=ui->lineEdit_id->text().toInt();
    bool test1=cl.supprimer(ID_CL);

          if(test1)
         {

            ui->tableView_interface->setModel(cl.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("supprimer effectuer\n"),QObject::tr("click cancel to exit"));
        }
         else
        {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("supprimer non effectuer"),QObject::tr("click cancel to exit"));
         }


}

void MainWindow::on_pushButton_modifer_clicked()
{
    int ID_CL =ui->lineEdit_id->text().toInt();
    QString NOM_CL=ui->lineEdit_nom->text();
     QString PRENOM_CL=ui->lineEdit_prenom->text();
    QString ADRESSE=ui->lineEdit_adresse->text();
     int TEL_CL=ui->lineEdit_num->text().toInt();
        bool  test2=cl.modifier(ID_CL);

        if(test2)
        {
            //Refresh affichage
            ui->tableView_interface->setModel(cl.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("modifier effectuer\n"),QObject::tr("click cancel to exit"));
        }else
        {
            QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("modifier non effectuer"),QObject::tr("click cancel to exit"));
        }
}

void MainWindow::on_pushButton_afficher_clicked()
{
      ui->tableView_interface->setModel(cl.afficher());
}
