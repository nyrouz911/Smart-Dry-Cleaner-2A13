#include "gestionproduitss.h"
#include "ui_gestionproduitss.h"

gestionproduitss::gestionproduitss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionproduitss)
{
    ui->setupUi(this);
}

gestionproduitss::~gestionproduitss()
{
    delete ui;
}
