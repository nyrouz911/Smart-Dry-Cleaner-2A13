#include "temp.h"
#include "arduino.h"
#include "ui_temp.h"

temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{
    ui->setupUi(this);
    ui->afficher_temp->setModel(t.affichertemp());
}

temp::~temp()
{
    delete ui;
}
