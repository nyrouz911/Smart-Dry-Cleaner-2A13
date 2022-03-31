#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString fournisseur,type_machine,image;
        int id_produit , quantite,prix_unitaire;



    if( ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()|| ui->lineEdit_3->text().isEmpty()|| ui->lineEdit_4->text().isEmpty()|| ui->lineEdit_5->text().isEmpty()|| ui->lineEdit_6->text().isEmpty())
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
                                     QObject::tr("  produit ajouté.\n"
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



void MainWindow::on_pushButton_2_clicked()
{
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
                                     QObject::tr("  produit Modifié.\n"
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




void MainWindow::on_pushButton_3_clicked()
{ int id_produit=ui->lineEdit->text().toInt();
    produit p;
    bool test=p.supprimer(id_produit);
    ui->tableView->setModel(tmpproduit.afficher());//refresh
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer produit"),
                                 QObject::tr("produit supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString id_produit= ui->tableView->model()->data(index).toString() ;
    QSqlQuery query ;
    query.prepare("SELECT FOURNISS,QTE,PRIX_UNIT,TYPE_MACHINE,IMAGE from PRODUITS");
    if (query.exec())
    {
        while (query.next())
        {
            ui->lineEdit->setText(id_produit);
            ui->lineEdit_2->setText(query.value(0).toString());
            ui->lineEdit_3->setText(query.value(1).toString());
            ui->lineEdit_4->setText(query.value(2).toString());
            ui->lineEdit_5->setText(query.value(3).toString());
        }
    }

}





void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherche(arg1));
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherchefournisseur(arg1));
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
     ui->tableView->setModel(tmpproduit.recherchequantite(arg1));
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    ui->tableView->setModel(tmpproduit.rechercheprix(arg1));
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    ui->tableView->setModel(tmpproduit.recherchetype(arg1));
}

void MainWindow::on_pushButton_4_clicked()
{


        ui->tableView->setModel(tmpproduit.AfficherTriprix());

         }



void MainWindow::on_pushButton_5_clicked()
{
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
        chartView->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setText("ID_produit");
    ui->label_2->setText("fournisseur");
    ui->label_3->setText("quantite");
    ui->label_4->setText("prix unitaire");
    ui->label_5->setText("type_machine");
    ui->label_6->setText("image");
    ui->pushButton->setText("Ajouter");
    ui->pushButton_2->setText("Modifer");
    ui->pushButton_3->setText("Supprimer");
    ui->pushButton_6->setText("Français");
    ui->pushButton_7->setText("Anglais");
    ui->pushButton_4->setText("Trier");
    ui->pushButton_5->setText("statistique");





}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText("Id");
    ui->label_2->setText("supplier");
    ui->label_3->setText("quantity");
    ui->label_4->setText("unit price");
    ui->label_5->setText("machine type");
    ui->pushButton->setText("Add");
    ui->pushButton_2->setText("Modify");
    ui->pushButton_3->setText("Remove");
    ui->pushButton_6->setText("French");
    ui->pushButton_7->setText("English");
    ui->pushButton_4->setText("Sort");
    ui->pushButton_5->setText("statistics");


}
/* void MainWindow::on_pushButton_61_clicked()
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

void MainWindow::on_pushButton_8_clicked()
{
        QString plan;
        QString file_name= QFileDialog::getOpenFileName(this,"open a file","c://");
       // QFile file("c://");
        ui->lineEdit_6->insert(file_name);

}
