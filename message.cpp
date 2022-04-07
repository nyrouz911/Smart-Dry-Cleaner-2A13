#include "message.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
Message::Message()
{
     message=" ";
}

Message::Message( QString message)
{
    this->message=message;
}

QString Message::getMessage(){return message;}
void Message::setMessage (QString message){this->message=message;}

bool Message::ajouterM()
{
    QSqlQuery query;

         query.prepare("INSERT INTO MESSAGE (message) "
                       "VALUES (:message)");

         query.bindValue(":message", message);
         return query.exec();
}

QSqlQueryModel* Message::afficherM()
{
    QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from MESSAGE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("message"));
        return model;
}
