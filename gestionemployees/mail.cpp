#include "mail.h"
#include "ui_mail.h"
#include "smtp.h"

mail::mail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mail)
{
    ui->setupUi(this);
}

mail::~mail()
{
    delete ui;
}

void mail::sendMail()
{
    Smtp* smtp = new Smtp("nay090236@gmail.com", "xzoxyxkgpuspbpve","smtp.gmail.com",465,30000);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("promotion", ui->lineEdit_10->text() , ui->lineEdit_9->text(),ui->textEdit->toPlainText());
}



void mail::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void mail::on_envoyer_clicked()
{
    connect(ui->envoyer, SIGNAL(clicked()),this, SLOT(sendMail()));
}

