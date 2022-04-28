#ifndef MESSAGE_H
#define MESSAGE_H
#include <QString>
#include <QSqlQueryModel>

class Message
{
public:
    Message();
    Message(QString);
    //GET
    QString getMessage();


    //SET
    void setMessage (QString);


    //FN
    bool ajouterM();
    QSqlQueryModel* afficherM();


 private:
    QString message;
};


#endif // MESSAGE_H
