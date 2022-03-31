#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
}
message::~message()
{
    delete ui;
}

void message::on_ok_clicked()
{
    mHostname=ui->hostname->text();
    mPort=ui->port->value();
    accept();
}

void message::on_cancel_clicked()
{
    reject();
}


