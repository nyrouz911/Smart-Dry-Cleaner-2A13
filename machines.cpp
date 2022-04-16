#include "machines.h"
#include "ui_machines.h"
#include "machine.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QDebug>
#include <QTimer>
#include "interventions.h"
#include "smtp.h"
#include "temp.h"

Machines::Machines(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Machines)
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

}

Machines::~Machines()
{
    delete ui;
}

void Machines::on_ajouter_clicked()
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



void Machines::on_supprimer_clicked()
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


void Machines::on_modifier_clicked()
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

//void Machines::on_chercher_textEdited(const QString &arg1)

//void Machines::on_intervention_clicked()
//{
//    dialog = new interventions(this);
//        dialog->setWindowFlags(Qt::Window);
//        dialog->show();
//}



//gestion intervention open winodw



void Machines::on_intervention_clicked()
{
    interventions inter;
    inter.setModal(true);
    inter.exec();
}


//void Machines::on_chercher_textChanged(QString &arg1)
//{
//    QMessageBox msgBox;

//        QSqlQuery query;
//        QString id,prod;
//        QString fab;
//        int critere=ui->cbsearch->currentIndex();

//        if(critere==0)
//        {


//            ui->tableView->setModel(Machtmp.searchbyid(arg1));


//        }
//           else if(critere==1)
//           {
//               ui->tableView->setModel(Machtmp.searchbyfab(arg1));

//           }
//           else if(critere==2)
//           {
//               ui->tableView->setModel(Machtmp.searchbyprod(arg1));
//           }
//}


void Machines::on_cbsearch_activated(const QString &arg1)
{

}

void Machines::on_chercher_textChanged(const QString &arg1)
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

void Machines::on_trifab_clicked()
{

        ui->tableView->setModel(Machtmp.tri_fab());

}

void Machines::on_tritype_clicked()
{
    ui->tableView->setModel(Machtmp.tri_type());
}

void Machines::on_trietat_clicked()
{
    ui->tableView->setModel(Machtmp.tri_etat());
}


void Machines::on_clear_clicked()
{
    ui->tableView->setModel(Machtmp.affichermach());

}

void Machines::on_temp_clicked()
{
    temp t;
    t.setModal(true);
    t.exec();
}
