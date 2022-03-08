#include "connection.h"

//test tutorialgit
connection::connection()


{

}

bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase ("QODBC");
        db.setDatabaseName("test_bd");
        db.setUserName("Nour");
        db.setPassword("Nour");

        if( db.open())
            test=true;
        return test;

}
