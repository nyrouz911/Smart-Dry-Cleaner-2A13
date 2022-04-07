#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("nay");
    db.setPassword("15020413");

    if (db.open())
        test=true;

    return  test;
}

void Connection::closeconnection(){db.close();}
