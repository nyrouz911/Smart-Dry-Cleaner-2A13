#include "interventions.h"
#include "intervention.h"
#include "connection.h"
#include "QSqlDatabase"
#include "ui_interventions.h"
#include "mail.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QTimer>


interventions::interventions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::interventions)
{
    ui->setupUi(this);
    ui->afficher_main->setModel(intertmp.affichermain());
    ui->id_main->setValidator( new QIntValidator(0, 999999, this));
    ui->id_mach->setValidator( new QIntValidator(0, 99999999, this));
    QRegularExpression rx("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
    QRegularExpression::CaseInsensitiveOption);
    ui->date_main->setValidator( new QIntValidator(0, 99999999, this));
    ui->type_main->setValidator(new QRegularExpressionValidator(rx, this));
    QRegularExpression rx1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",
    QRegularExpression::CaseInsensitiveOption);

}

interventions::~interventions()
{
    delete ui;
}




void interventions::on_ajouter_main_clicked()
{
    int id_main=ui->id_main->text().toInt();
    QString type_main=ui->type_main->text();
    int etat_main=ui->etat_main->currentIndex();

    QString descr_main=ui->descr_main->text();
    QString date_main=ui->date_main->text();
    int id_mach=ui->id_mach->text().toInt();

    intervention intertmp(id_main,type_main,etat_main,descr_main,date_main,id_mach);

   bool test=intertmp.ajoutermain();

    if(test)
    {
        //refresh
        ui->afficher_main->setModel(intertmp.affichermain());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

}

void interventions::on_supprimer_main_clicked()
{
    int id_main=ui->id_main_sup->text().toInt();
    bool test=intertmp.supprimermain(id_main);

    //refresh
    ui->afficher_main->setModel(intertmp.affichermain());
    if (test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void interventions::on_modifier_main_clicked()
{
    int id_main=ui->id_main->text().toInt();
    QString type_main=ui->type_main->text();
    int etat_main=ui->etat_main->currentIndex();
    QString date_main=ui->date_main->text();
    QString descr_main=ui->descr_main->text();
    int id_mach=ui->id_mach->text().toInt();


    intervention i(id_main,type_main,etat_main,descr_main,date_main,id_mach);
    bool test = i.modifiermain(id_main);

    //refresh
    ui->afficher_main->setModel(i.affichermain());

    if(test){
        QMessageBox::information(nullptr, QObject::tr("update status"),QObject::tr("Machine updated.\nClick Cancel to exit."), QMessageBox::Cancel,QMessageBox::NoIcon);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("update status"),QObject::tr("Machine not updated.\nClick Cancel to exit."), QMessageBox::Cancel);
    }
}

void interventions::on_mail_clicked()
{
    mail m;
    m.setModal(true);
    m.exec();
}

void interventions::on_chercher_textChanged(const QString &arg1)
{
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM INTERVENTIONS WHERE ID_MAIN  LIKE'"+arg1+"%' or TYPE_MAIN  LIKE'"+arg1+"%' or ETAT_MAIN  LIKE'"+arg1+"%' or DESCR_MAIN LIKE'"+arg1+"%' or DATE_MAIN  LIKE'"+arg1+"%' or ID_MACH  LIKE'"+arg1+"%'  ");
        query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->afficher_main->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !!\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->chercher->clear();}
    }
}
