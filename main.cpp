#include "mainwindow.h"
#include "connection.h"
#include "machines.h"
#include "ui_machines.h"
#include <QMessageBox>
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;

    QStringList languages;
    languages<< "English"<<"French";
    QString lang =QInputDialog::getItem(NULL,"Select your language","Language",languages);
    if(lang=="English")
    {
        t.load(":/English.qm");
    }
    if(lang!="French")
    {
        a.installTranslator(&t);
    }


    Connection c;

    bool test=c.createconnection();

    Machines w;

    if (test)
    {
        w.show();
       QMessageBox::information(nullptr, QObject::tr("database is open"),
       QObject::tr("connection successful.\n"
       "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
return a.exec();
    }
