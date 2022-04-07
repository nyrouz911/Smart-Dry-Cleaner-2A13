#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
