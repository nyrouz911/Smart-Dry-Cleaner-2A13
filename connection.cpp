#include "connection.h"

Connection::Co#include "connection.h"

Connection::Connection()
{

}
bool Connection::createconnect()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_qt");
db.setUserName("Brahim1");
db.setPassword("Brahim1");

if (db.open()) test=true;


 return test;
}
