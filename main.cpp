
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QStringList Langues;
    QTranslator Langue;
    QTranslator traductionInterface;
    Langues<<"Francais"<<"English";
    QString langueChoisi= QInputDialog::getItem(NULL,"Choisissez Une Langue","Langue",Langues);


    if(langueChoisi=="English")
    {
        Langue.load(":/english.qm");
        traductionInterface.load("C:\Qt\Qt5.9.9\5.9.9\mingw53_32\translations/qtbase_en.qm");
    }
    if(langueChoisi!="Francais")
    {
        a.installTranslator(&Langue);
        a.installTranslator(&traductionInterface);
    }

    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
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
