#include "gestionlivraison.h"
#include "ui_gestionlivraison.h"
#include "livraison.h"
#include <QDate>
#include <QString>
#include <QDateEdit>
#include <QPdfWriter>
#include <QPainter>
#include <QFontDialog>
#include <QMessageBox>
#include "connection.h"
#include <QIntValidator>
#include <QTextBrowser>
#include <QTextEdit>
#include <QTextStream>


gestionlivraison::gestionlivraison(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionlivraison)
{

    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
    QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(new QIntValidator(0,99999999.,this));
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit->setValidator(new QIntValidator(0,999999.,this));
    ui->tab_livraison->setModel(l.afficher());
    ui->textBrowser->hide();
}

gestionlivraison::~gestionlivraison()
{
    delete ui;
}
void gestionlivraison::title()
{
    setWindowTitle("Smart CleanApp");
}


void gestionlivraison::on_ajouter_clicked()
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



void gestionlivraison::on_supprimer_clicked()
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




void gestionlivraison::on_modifier_clicked()
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





void gestionlivraison::on_chercherid_clicked()
{
    ui->tab_livraison->setModel(l.recherche_id(ui->tttt->text()));
}

void gestionlivraison::on_cherchedate_clicked()
{
    ui->tab_livraison->setModel(l.recherche_date(ui->tttt->text()));
}

void gestionlivraison::on_cherchernum_clicked()
{
    ui->tab_livraison->setModel(l.recherche_numlivreur(ui->tttt->text()));
}

void gestionlivraison::on_trierid_clicked()
{
    ui->tab_livraison->setModel(l.trier_id());
}

void gestionlivraison::on_trierdate_clicked()
{
    ui->tab_livraison->setModel(l.trier_date());
}

void gestionlivraison::on_triernum_clicked()
{
    ui->tab_livraison->setModel(l.trier_numlivreur());
}

void gestionlivraison::on_generer_clicked()
{
    l.exporterpdf(ui->textBrowser);
}

void gestionlivraison::on_Francais_clicked()
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
        ui->ajouter->setText("Ajouter");
        ui->modifier->setText("Modifer");
        ui->supprimer->setText("Supprimer");
        ui->trierid->setText("ID");
        ui->trierdate->setText("DATE");
        ui->triernum->setText("NUM LIVREUR");
        ui->chercherid->setText("Chercher");
        ui->generer->setText("Generer PDF");
        ui->Excel->setText("Generer EXCEL");
        ui->Francais->setText("Fr");
        ui->Anglais->setText("An");

}

void gestionlivraison::on_Anglais_clicked()
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
    ui->ajouter->setText("Add");
    ui->modifier->setText("Modify");
    ui->supprimer->setText("Delete");
    ui->trierid->setText("ID");
    ui->trierdate->setText("DATE");
    ui->triernum->setText("DELIVERY NUMBER");
    ui->chercherid->setText("Search");
    ui->generer->setText("Generate PDF");
    ui->Excel->setText("Generate EXCEL");
    ui->Francais->setText("Fr");
    ui->Anglais->setText("En");
}

void gestionlivraison::on_Excel_clicked()
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
    /*QString currDate()
   {
        QDate date = QDate::currentDate();
        return date.toString("dd.MM.yyyy");
}*/




