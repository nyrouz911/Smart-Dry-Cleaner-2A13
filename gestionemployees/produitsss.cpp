#include "produitsss.h"
#include "ui_produitsss.h"
#include <QMessageBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include "arduino.h"
#include "qDebug";
#include <QFileDialog>

produitsss::produitsss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitsss)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpproduit.afficher());
    ui->lineEdit->setValidator( new QIntValidator(0, 999999, this));
    ui->lineEdit_4->setValidator( new QIntValidator(0, 999999, this));
    ui->lineEdit_3->setValidator( new QIntValidator(0, 999999, this));
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new
            QRegExpValidator(rx,this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);

    ard.connectArduino();
}

void produitsss::responseToArduino() {
    QByteArray data = ard.readFromArduino();
    qDebug() << data;
}

produitsss::~produitsss()
{
    delete ui;
}


void produitsss::on_pushButton_clicked()
{
    QString fournisseur,type_machine,image;
        int id_produit , quantite,prix_unitaire;



    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty()|| ui->lineEdit_4->text().isEmpty()|| ui->lineEdit_5->text().isEmpty() || ui->lineEdit_6->text().isEmpty())
    {
        ui->tableView ->setModel(tmpproduit.afficher());//refresh
        QMessageBox::warning(nullptr, QObject::tr("Attention"),
                             QObject::tr("Veuillez remplir tout les champs.\n"), QMessageBox::Ok);
    }
    else{
        id_produit=ui->lineEdit->text().toInt();
        fournisseur=ui->lineEdit_2->text();
        quantite=ui->lineEdit_3->text().toInt();
        prix_unitaire=ui->lineEdit_4->text().toInt();
        type_machine=ui->lineEdit_5->text();
        image=ui->lineEdit_6->text();








 produit p(id_produit,fournisseur, quantite , prix_unitaire, type_machine,image);

     bool test= p.ajouter();

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                                     QObject::tr("  produit ajout??.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpproduit.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un  produit"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }

}



void produitsss::on_pushButton_2_clicked() {
    qDebug() << "Selecting";
    QString  fournisseur,type_machine,image ;
        int id_produit,quantite,prix_unitaire;


        id_produit=ui->lineEdit->text().toInt();
        fournisseur=ui->lineEdit_2->text();
        quantite=ui->lineEdit_3->text().toInt();
        prix_unitaire=ui->lineEdit_4->text().toInt();
        type_machine=ui->lineEdit_5->text();
        image=ui->lineEdit_6->text();



         produit p (id_produit,fournisseur,quantite,prix_unitaire,type_machine,image);


         bool test =p.modifier(p.getid_produit());

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                                     QObject::tr("  produit Modifi??.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tmpproduit.afficher());//refresh
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modifier un produit"),
                                     QObject::tr("  ERREUR.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
}




void produitsss::on_pushButton_3_clicked()
{
    int id_produit=ui->lineEdit->text().toInt();
    produit p;
    bool test=p.supprimer(id_produit);
    ui->tableView->setModel(tmpproduit.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer produit"),
                                 QObject::tr("produit supprim??.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void produitsss::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString id_produit= ui->tableView->model()->data(index).toString() ;
    qDebug() << id_produit;
    QSqlQuery query ;
    query.prepare("SELECT ID_PROD,FOURNISS,QTE,PRIX_UNIT,TYPE_MACHINE,IMAGE from PRODUITS");
    if (query.exec())
    {
        while (query.next())
        {
            ui->lineEdit->setText(id_produit);
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
        }
    }

}





void produitsss::on_lineEdit_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherche(arg1));
}


void produitsss::on_lineEdit_2_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherchefournisseur(arg1));
}

void produitsss::on_lineEdit_3_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherchequantite(arg1));
}

void produitsss::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tableView->setModel(tmpproduit.rechercheprix(arg1));
}

void produitsss::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->tableView->setModel(tmpproduit.recherchetype(arg1));
}





/*void produitsss::on_pushButton_5_clicked()
{
    qDebug() << "Showing Stats";
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from PRODUITS where  PRIX_UNIT>= 200");
        float dispo1=model->rowCount();

        model->setQuery("select * from PRODUITS where PRIX_UNIT <200");
        float dispo=model->rowCount();

        float total=dispo1+dispo;
            QString a=QString("inf a 200 . " +QString::number((dispo1*100)/total,'f',2)+"%" );
            QString b=QString("supp a 200 .  "+QString::number((dispo*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,dispo1);
            series->append(b,dispo);
        if (dispo1!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( dispo!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();


        chart->addSeries(series);
        chart->setTitle("Prix unitaire des produits :Nb produits: "+ QString::number(total));
        chart->legend()->hide();


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        qDebug() << "Showing Stats";
        chartView->show();
}*/


/* void produitsss::on_pushButton_61_clicked()+
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/marie/OneDrive/Bureau/Photos", tr("Image Files (*.png *.jpg *.bmp)"));
//to select and show the picture
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        image=image.scaledToWidth(ui->label_image->width(),Qt::SmoothTransformation);
            ui->label_image->setPixmap(QPixmap::fromImage(image));
}
} */

void produitsss::on_pushButton_8_clicked()
{
        QString plan;

        QString file_name= QFileDialog::getOpenFileName(this,"open a file","c://");
       // QFile file("c://");
        ui->lineEdit_6->insert(file_name);
        ui->label_7->setPixmap(file_name);
        QImage image(file_name);
                image=image.scaledToWidth(ui->label_7->width(),Qt::SmoothTransformation);
                    ui->label_7->setPixmap(QPixmap::fromImage(image));

}

void produitsss::on_pushButton_6_clicked()
{
     ui->tableView->setModel(tmpproduit.AfficherTriquantite());
}

void produitsss::on_pushButton_7_clicked()
{
  ui->tableView->setModel(tmpproduit.AfficherTriID());
}
void produitsss::on_pushButton_4_clicked()
{

    ui->tableView->setModel(tmpproduit.AfficherTriprix());
        QByteArray data = ard.readFromArduino();
        float value = data.split(',')[0].toFloat();

        //qDebug() << value;
        if ( data != "" ){

            if(value < 2.30){
                ui->label_8->setStyleSheet("QLabel { color : green; }");
                ui->label_8->setText("Niveau Bas");
            }
            else if(value >= 2.30 && value <= 2.90 ){
                ui->label_8->setStyleSheet("QLabel { color : orange; }");
                ui->label_8->setText("Niveau Moyen");
            }else{
                ui->label_8->setStyleSheet("QLabel { color : red; }");
                ui->label_8->setText("Niveau Haut");
            }
        }



}

void produitsss::on_comboBox_activated(const QString &arg1)
{
    int value=ui->comboBox->currentIndex();

            //qDebug()<<value;
            if (value==1)
            {
                ui->tableView->setModel(tmpproduit.AfficherTriprix());
            }
            if (value==2)
            {
            ui->tableView->setModel(tmpproduit.AfficherTriquantite());
            }
            if (value==3)
            {
            ui->tableView->setModel(tmpproduit.AfficherTriID());
            }

}

void produitsss::on_lineEdit_6_textChanged(const QString &arg1)
{
    ui->label_7->setPixmap(ui->lineEdit_6->text());
}

void produitsss::on_pushButton_5_clicked() {
    qDebug() << "Showing Stats";
    QWidget * chartWindow = new QWidget(0);
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from PRODUITS where  PRIX_UNIT>= 200");
        float dispo1=model->rowCount();

        model->setQuery("select * from PRODUITS where PRIX_UNIT <200");
        float dispo=model->rowCount();

        float total=dispo1+dispo;
            QString a=QString("inf a 200 . " +QString::number((dispo1*100)/total,'f',2)+"%" );
            QString b=QString("supp a 200 .  "+QString::number((dispo*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,dispo1);
            series->append(b,dispo);
        if (dispo1!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( dispo!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();


        chart->addSeries(series);
        chart->setTitle("Prix unitaire des produits :Nb produits: "+ QString::number(total));
        chart->legend()->hide();



        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->activateWindow();
        chartView->raise();
        chartView->show();
}

void produitsss::on_statBtn_clicked() {
    qDebug() << "Showing Stats";
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from PRODUITS where  PRIX_UNIT>= 200");
        float dispo1=model->rowCount();

        model->setQuery("select * from PRODUITS where PRIX_UNIT <200");
        float dispo=model->rowCount();

        float total=dispo1+dispo;
            QString a=QString("inf a 200 . " +QString::number((dispo1*100)/total,'f',2)+"%" );
            QString b=QString("supp a 200 .  "+QString::number((dispo*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,dispo1);
            series->append(b,dispo);
        if (dispo1!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( dispo!=0)
        {
            QPieSlice *slice1 = series->slices().at(1);
            slice1->setLabelVisible();
        }

        QChart *chart = new QChart();


        chart->addSeries(series);
        chart->setTitle("Prix unitaire des produits :Nb produits: "+ QString::number(total));
        chart->legend()->hide();


        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        qDebug() << "Showing Stats";
        chartView->show();

}

void produitsss::on_testBtn_clicked() {
    ard.writeToArduino("1");
}
