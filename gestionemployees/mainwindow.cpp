#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionemployes.h"
#include "gestionmachine.h"
#include "gestionclient.h"
#include "gestionlivraison.h"

#include "produitsss.h"
#include "gestionscommandes.h"
//#include "employes.h"
#include <QMessageBox>
//#include "ui_gestionemployes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    //Mayssen
    if((username=="responsableRH")&&(password=="RH"))
    {
      gestionemployes e1;
      e1.setModal(true);
      e1.exec();


    }
    //Nour
    else if
            ((username=="agent")&&(password=="agent"))
                {
                  gestionclient cl1;
                  cl1.setModal(true);
                  cl1.exec();


                }
    //Miguel
    else if
            ((username=="agentC")&&(password=="agentC"))
                {

                  gestionscommandes c1;
                  c1.setModal(true);
                  c1.exec();


                }


    //Nayrouz
    else if
            ((username=="technicienM")&&(password=="machine"))
                {
                  gestionmachine m1;
                  m1.setModal(true);
                  m1.exec();


                }
    //Achref
    else if
            ((username=="technicienP")&&(password=="produit"))
                {
                  produitsss p1;
                  p1.setModal(true);
                  p1.exec();


                }
    //Brahym

    else if
            ((username=="livreur")&&(password=="livreur"))
                {
                  gestionlivraison l1;
                  l1.setModal(true);
                  l1.exec();


                }

    else
        QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);


}
