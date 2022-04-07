#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionemployes.h"
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
    if((username=="admin")&&(password=="admin"))
    {
      gestionemployes e1;
      e1.setModal(true);
      e1.exec();


    }
    else QMessageBox::critical(nullptr, QObject::tr("acces refuse"),
                                QObject::tr("Vérifiez vos coordonnées."), QMessageBox::Cancel);


}
