#ifndef QR_CODE_H
#define QR_CODE_H



#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"


using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;




class QR_Code
{
public:
    QR_Code();
    static std::string toSvgString(const QrCode &qr, int border);
    static void printQr(const QrCode &qr);
    static void printRecu(const QrCode &qr,std::string idCommande,std::string montant,std::string nbpieces,std::string idEmploye,std::string idClient,std::string dateRetrait,std::string dateDepot);
};





#endif // QR_CODE_H
