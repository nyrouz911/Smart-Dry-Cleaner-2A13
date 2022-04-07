#include "mainwindow.h"
#include "connection.h"
#include "livraison.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;

    QStringList languages;
    languages << "Français" << "Anglais" ;
    const QString lang = QInputDialog::getItem(NULL,
                                        "Language" ,
                                        "Select a language" ,
                                        languages);

    if (lang == "Français")
    {
        t.load(":/french.qm");

    } else if(lang == "Anglais")
    {
        t.load(":/english.qm");
    }
    /*if (lang != "Français") {
        a.installTranslator(&t);
    }*/

    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
      {
        w.show();
          QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connection sucessful.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    w.show();
    w.title();

    return a.exec();
}
                                                                                            #include "mainwindow.h"
#include "connection.h"
#include "livraison.h"
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;

    QStringList languages;
    languages << "Français" << "Anglais" ;
    const QString lang = QInputDialog::getItem(NULL,
                                        "Language" ,
                                        "Select a language" ,
                                        languages);

    if (lang == "Français")
    {
        t.load(":/french.qm");

    } else if(lang == "Anglais")
    {
        t.load(":/english.qm");
    }
    /*if (lang != "Français") {
        a.installTranslator(&t);
    }*/

    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
      {
        w.show();
          QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("connection sucessful.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),QObject::tr("connection failed.\n""click cancel to exist."), QMessageBox::Cancel);
    }
    w.show();
    w.title();

    return a.exec();
}
