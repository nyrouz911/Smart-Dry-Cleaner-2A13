#include "connection.h"

//test
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet");
db.setUserName("achraf");//inserer nom de l'utilisateur
db.setPassword("achraf");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
