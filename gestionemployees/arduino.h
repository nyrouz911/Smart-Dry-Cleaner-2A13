#ifndef ARDUINO_H
#define ARDUINO_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino
{
public:
    Arduino();
    int connectArduino();
    int closeArduino();
    int writeToArduino(QByteArray);
    QByteArray readFromArduino();
    QSerialPort getSerial();
    QString getArduinoPortName();
private:
    QSerialPort * serial;
    static const quint16 arduinoUnoVendorID=9025;
    static const quint16 arduinoUnoProducyID=67;
    QString arduinoPortName;
    bool arduinoIsAvailable;
    QByteArray data;
};


#endif // ARDUINO_H
