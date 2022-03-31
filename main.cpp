#include "mainwindow.h"
#include "connection.h"
#include "employee.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    c.createconnect();
    MainWindow w;
    w.show();
    return a.exec();
}
