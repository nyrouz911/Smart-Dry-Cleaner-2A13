#include "gestionmachine.h"
#include "ui_gestionmachine.h"
#include "machine.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QTimer>
#include "interventions.h"
#include "smtp.h"



gestionmachine::~gestionmachine()
{
    delete ui;
}


gestionmachine::gestionmachine(QWidget *parent):
    QDialog(parent),
    ui(new Ui::gestionmachine)
{
    ui->setupUi(this);
    ui->tableView->setModel(Machtmp.affichermach());

    ui->id_mach_mod->setValidator( new QIntValidator(0, 999999, this));
    ui->num_fab->setValidator( new QIntValidator(0, 99999999, this));
    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->type_mach->setValidator(new QRegularExpressionValidator(rx, this));
    QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->fab->setValidator(new QRegularExpressionValidator(rx1, this));
    QRegularExpression rx3("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
    QRegularExpression::CaseInsensitiveOption);

    //connexion arduino

//    int ret=t.connect_Arduino();
//    switch(ret){
//    case(0):qDebug()<< "arduino is available and connected to : "<< t.getarduino_port_name();
//        break;
//    case(1):qDebug() << "arduino is available but not connected to :" <<t.getarduino_port_name();
//       break;
//    case(-1):qDebug() << "arduino is not available";
//    }
//     QObject::connect(t.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

//     //temp checking
//     QMessageBox msgBox;

//     data=t.read_from_arduino();

//     qDebug() <<"data="<<data;

//     if(data=="1")
//     {

//     msgBox.setText("Une température anormale a été détectée !");
//     msgBox.setInformativeText("Voulez-vous activer le moteur de refroidissement?");
//     msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
//     msgBox.setDefaultButton(QMessageBox::Ok);
//     int res = msgBox.exec();
//     if (res==QMessageBox::Ok)

//        t.write_to_arduino("1");

//    else
//      {
//        t.write_to_arduino("0");
//      }
//     }
//   else if(data=="0")
//     {
//         t.write_to_arduino("0");
//         qDebug() << "Couldn't read from serial!";

//    }
}



void gestionmachine::on_ajouter_clicked()
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
        ui->tableView->setModel(Machtmp.affichermach());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}



void gestionmachine::on_supprimer_clicked()
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


void gestionmachine::on_modifier_clicked()
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




//gestion intervention open winodw



void gestionmachine::on_intervention_clicked()
{
    interventions inter;
    inter.setModal(true);
    inter.exec();
}


void gestionmachine::on_chercher_textChanged(const QString &arg1)
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

void gestionmachine::on_trifab_clicked()
{

        ui->tableView->setModel(Machtmp.tri_fab());

}

void gestionmachine::on_tritype_clicked()
{
    ui->tableView->setModel(Machtmp.tri_type());
}

void gestionmachine::on_trietat_clicked()
{
    ui->tableView->setModel(Machtmp.tri_etat());
}


void gestionmachine::on_clear_clicked()
{
    ui->tableView->setModel(Machtmp.affichermach());

}

