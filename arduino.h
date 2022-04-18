#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include <QSqlQuery>
#include <QSqlQueryModel>

class Arduino
{
public:
    Arduino();
    int connect_Arduino();
    int close_Arduino();
    int write_to_arduino(QByteArray);
    QSerialPort* getserial();
    QString getarduino_port_name();
    QSqlQueryModel * affichertemp();

private:
    QSerialPort * serial;

    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data;


};

#endif // ARDUINO_H