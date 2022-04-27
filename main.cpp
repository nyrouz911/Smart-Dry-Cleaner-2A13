#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    QStringList languages;
    languages<<"English"<<"Françcais";

    QString lang= QInputDialog::getItem(NULL,"Select Language","Language",languages);

    if(lang=="English")
    {
        t.load(":/english.qm");
    }
    if (lang!="English")
    {
        a.installTranslator(&t);
    }
    MainWindow w;
    w.show();
    Connection c;
    bool test=c.createconnect();
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successfuly.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}



