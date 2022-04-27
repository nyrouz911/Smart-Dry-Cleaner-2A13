#include "arduino.h"
#include <QDebug>

Arduino::Arduino()
{

}


int Arduino::connectArduino()
{
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier() == arduinoUnoVendorID && serial_port_info.productIdentifier() == arduinoUnoProducyID)
            {
                arduinoIsAvailable=true;
                arduinoPortName=serial_port_info.portName();
            }
        }
    }
    qDebug() <<"arduino_port_name is :"<< arduinoPortName;
    if(arduinoIsAvailable)
    {qDebug() << "0";
        this->serial = new QSerialPort();
        this->serial->setPortName(arduinoPortName);
        qDebug() << "1";
        if(this->serial->open(QSerialPort::ReadWrite))
        {
            qDebug() << "2";
            this->serial->setBaudRate(QSerialPort::Baud9600);
            qDebug() << "3";
            this->serial->setDataBits(QSerialPort::Data8);
            qDebug() << "4";
            this->serial->setParity(QSerialPort::NoParity);
            qDebug() << "5";
            this->serial->setStopBits(QSerialPort::OneStop);
            qDebug() << "6";
            this->serial->setFlowControl(QSerialPort::NoFlowControl);
            qDebug() << "7";
            return 0;
        }
        return 1;
    }
    return -1;
}

int Arduino::closeArduino()
{
    if(this->serial->isOpen())
    {
        this->serial->close();
        return 0;
    }
    return 1;
}

QByteArray Arduino::readFromArduino()
{
    if(this->serial->isReadable())
    {
        data= this->serial->readAll();

        return data;
    }
}

int Arduino::writeToArduino(QByteArray d)
{
    if(serial->isWritable())
        serial->write(d);
    else
        qDebug() <<"Couldn't write to serial!";
}
