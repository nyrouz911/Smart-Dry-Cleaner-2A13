#include "livraison.h"
#include <QSqlQuery>
#include <QDate>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QPrinter>
#include <QMessageBox>

livraison::livraison()
{
id_livr=0;
etat_livr="";
num_livr="";
adresse_livr="";
id_commande=0;
}
livraison::livraison(int id_livr,QString etat_livr,QString num_livr,QString adresse_livr,QDate date_livr,int id_commande)

{
    this->id_livr=id_livr;
    this->etat_livr=etat_livr;
    this->num_livr=num_livr;
    this->adresse_livr=adresse_livr;
    this->date_livr=date_livr;
    this->id_commande=id_commande;

}
    int livraison::getID_LIVR(){return id_livr;}
    QString livraison::getETAT_LIVR(){return etat_livr;}
    QString livraison::getNUM_LIVR(){return num_livr;}
    QString livraison::getADRESSE_LIVR(){return adresse_livr;}
    QDate livraison::getDATE_LIVR(){return date_livr;}
    int livraison::getID_COMMANDE(){return id_commande;}



    void livraison::setID_LIVR(int id_livr){this->id_livr=id_livr;}
    void livraison::setETAT_LIVR(QString etat_livr){this->etat_livr=etat_livr;}
    void livraison::setNUM_LIVR(QString num_livr){this->num_livr=num_livr;}
    void livraison::setADRESSE_LIVR(QString adresse_livr){this->adresse_livr=adresse_livr;}
    void livraison::setDATE_LIVR(QDate date_livr){this->date_livr=date_livr;}
    void livraison::setID_COMMANDE(int id_commande){this->id_commande=id_commande;}



    bool livraison::ajouter()
    {

    QSqlQuery query;
    query.prepare("INSERT INTO LIVRAISONS (id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande) "
                  "VALUES (:id_livr, :etat_livr, :num_livr, :adresse_livr, :date_livr, :id_commande)");
    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);

    return    query.exec();
    }

    QSqlQueryModel* livraison::afficher()
    {

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM LIVRAISONS");

    return model;
    }

    bool livraison::supprimer(int)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM LIVRAISONS WHERE id_livr=:id_livr");
        query.bindValue(0, id_livr);
        return query.exec();
    }

    bool livraison::modifier(int id_livr)
    {
     QSqlQuery query;



    query.prepare("update  LIVRAISONS set etat_livr=:etat_livr, num_livr=:num_livr, adresse_livr=:adresse_livr, date_livr=:date_livr,id_commande=:id_commande where id_livr=:id_livr ");


    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);



     return query.exec();
    }




    QSqlQueryModel * livraison::recherche_id(const QString &id_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(id_livr LIKE '"+id_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }

    QSqlQueryModel * livraison::recherche_date(const QString &date_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(date_livr LIKE '"+date_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }


    QSqlQueryModel * livraison::recherche_numlivreur(const QString &num_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(num_livr LIKE '"+num_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }





    QSqlQueryModel * livraison::trier_id()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY id_livr ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }


    QSqlQueryModel * livraison::trier_date()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY date_livr");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }


    QSqlQueryModel * livraison::trier_numlivreur()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY num_livr ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }



    void livraison::exporterpdf(QTextBrowser *text)
    {
      // QString tt;
        QSqlQuery qry;
        std::list<QString> tt;
        qry.exec("select * from LIVRAISONS");
        while(qry.next())
        {
            tt.push_back("ID Livraison: "+qry.value(0).toString()+"\n"+"Etat Livraison: "+qry.value(1).toString()+"\n"+"Num Livreur: "+qry.value(2).toString()+"\n"+"Adresse Livraison: "+qry.value(3).toString()+"\n"+"Date Livraison: "+qry.value(4).toString()+"\n"+"ID Commande: "+qry.value(5).toString()+"\n");

        }

        for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
        {
            text->setText(text->toPlainText()+*it + "----------------------------------------------------------\n");
        }

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        text->print(&printer);
        QMessageBox::information(nullptr, QObject::tr("Export PDF"),
                                  QObject::tr("Export avec succes .\n"
                                              "Click OK to exit."), QMessageBox::Ok);
    }
                                                                                                                                                                                                                                                                                                                                                                                                                    #include "livraison.h"
#include <QSqlQuery>
#include <QDate>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QPrinter>
#include <QMessageBox>

livraison::livraison()
{
id_livr=0;
etat_livr="";
num_livr="";
adresse_livr="";
id_commande=0;
}
livraison::livraison(int id_livr,QString etat_livr,QString num_livr,QString adresse_livr,QDate date_livr,int id_commande)

{
    this->id_livr=id_livr;
    this->etat_livr=etat_livr;
    this->num_livr=num_livr;
    this->adresse_livr=adresse_livr;
    this->date_livr=date_livr;
    this->id_commande=id_commande;

}
    int livraison::getID_LIVR(){return id_livr;}
    QString livraison::getETAT_LIVR(){return etat_livr;}
    QString livraison::getNUM_LIVR(){return num_livr;}
    QString livraison::getADRESSE_LIVR(){return adresse_livr;}
    QDate livraison::getDATE_LIVR(){return date_livr;}
    int livraison::getID_COMMANDE(){return id_commande;}



    void livraison::setID_LIVR(int id_livr){this->id_livr=id_livr;}
    void livraison::setETAT_LIVR(QString etat_livr){this->etat_livr=etat_livr;}
    void livraison::setNUM_LIVR(QString num_livr){this->num_livr=num_livr;}
    void livraison::setADRESSE_LIVR(QString adresse_livr){this->adresse_livr=adresse_livr;}
    void livraison::setDATE_LIVR(QDate date_livr){this->date_livr=date_livr;}
    void livraison::setID_COMMANDE(int id_commande){this->id_commande=id_commande;}



    bool livraison::ajouter()
    {

    QSqlQuery query;
    query.prepare("INSERT INTO LIVRAISONS (id_livr,etat_livr,num_livr,adresse_livr,date_livr,id_commande) "
                  "VALUES (:id_livr, :etat_livr, :num_livr, :adresse_livr, :date_livr, :id_commande)");
    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);

    return    query.exec();
    }

    QSqlQueryModel* livraison::afficher()
    {

    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM LIVRAISONS");

    return model;
    }

    bool livraison::supprimer(int)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM LIVRAISONS WHERE id_livr=:id_livr");
        query.bindValue(0, id_livr);
        return query.exec();
    }

    bool livraison::modifier(int id_livr)
    {
     QSqlQuery query;



    query.prepare("update  LIVRAISONS set etat_livr=:etat_livr, num_livr=:num_livr, adresse_livr=:adresse_livr, date_livr=:date_livr,id_commande=:id_commande where id_livr=:id_livr ");


    query.bindValue(":id_livr", id_livr);
    query.bindValue(":etat_livr", etat_livr);
    query.bindValue(":num_livr", num_livr);
    query.bindValue(":adresse_livr", adresse_livr);
    query.bindValue(":date_livr", date_livr);
    query.bindValue(":id_commande", id_commande);



     return query.exec();
    }




    QSqlQueryModel * livraison::recherche_id(const QString &id_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(id_livr LIKE '"+id_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }

    QSqlQueryModel * livraison::recherche_date(const QString &date_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(date_livr LIKE '"+date_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }


    QSqlQueryModel * livraison::recherche_numlivreur(const QString &num_livr)
    {

        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS where(num_livr LIKE '"+num_livr+"%')");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

            return model;

    }





    QSqlQueryModel * livraison::trier_id()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY id_livr ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }


    QSqlQueryModel * livraison::trier_date()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY date_livr");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }


    QSqlQueryModel * livraison::trier_numlivreur()
    {
        QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("select * from LIVRAISONS ORDER BY num_livr ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_livr"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_livr"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_livr"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse_livr"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_livr"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_commande"));

        return model;
    }



    void livraison::exporterpdf(QTextBrowser *text)
    {
      // QString tt;
        QSqlQuery qry;
        std::list<QString> tt;
        qry.exec("select * from LIVRAISONS");
        while(qry.next())
        {
            tt.push_back("ID Livraison: "+qry.value(0).toString()+"\n"+"Etat Livraison: "+qry.value(1).toString()+"\n"+"Num Livreur: "+qry.value(2).toString()+"\n"+"Adresse Livraison: "+qry.value(3).toString()+"\n"+"Date Livraison: "+qry.value(4).toString()+"\n"+"ID Commande: "+qry.value(5).toString()+"\n");

        }

        for(std::list<QString>::iterator it =tt.begin();it!=tt.end();++it)
        {
            text->setText(text->toPlainText()+*it + "----------------------------------------------------------\n");
        }

        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);
        text->print(&printer);
        QMessageBox::information(nullptr, QObject::tr("Export PDF"),
                                  QObject::tr("Export avec succes .\n"
                                              "Click OK to exit."), QMessageBox::Ok);
    }
