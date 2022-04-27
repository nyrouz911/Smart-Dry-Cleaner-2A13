#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>
#include "connection.h"
#include "arduino.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator t;
    QTranslator guiTranslator;
    QStringList languages ;
   languages <<"Francais"<<"Anglais";
   QString lang = QInputDialog::getItem(NULL,"Selectionnez une langue","langues",languages);





   if (lang =="Anglais")
   {

   t.load(":/english.qm") ;
}
    if (lang !="Francais")
   {
       a.installTranslator(&t) ;
       a.installTranslator(&guiTranslator);
   }
    Connection c;
    bool test=c.createconnect();
        MainWindow w;
    if(test)
    { w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
