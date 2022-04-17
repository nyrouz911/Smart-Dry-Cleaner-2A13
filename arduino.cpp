#include "arduino.h"


Arduino::Arduino()
{

}

int Arduino::connect_Arduino()
{
    foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) // houni bsh nlawjouu aal port li connected li l arduino
    {
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if(serial_port_info.vendorIdentifier()==arduino_uno_vendor_id && serial_port_info.productIdentifier()==arduino_uno_producy_id)
            {
                arduino_is_available=true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
    qDebug() <<"arduino_port_name is :"<< arduino_port_name;

    if(arduino_is_available) // hedha lconfig
    {
        serial->setPortName(arduino_port_name);
    }
    if(serial->open(QSerialPort::ReadWrite))
    {
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        return 0;
    }
    return 1;
}

int Arduino::close_Arduino()
{
    if(serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}

int Arduino::write_to_arduino( QByteArray d)
{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }

    return (-1);
}

QSqlQueryModel * Arduino::affichertemp()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("select * from temperatures");

    return model;
}


