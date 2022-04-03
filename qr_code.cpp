#include "qr_code.h"

#include <fstream>

using std::cout; using std::ofstream;
using std::endl; using std::string;
using std::fstream;



QR_Code::QR_Code()
{

}


static std::string toSvgString(const QrCode &qr, int border) {
    if (border < 0)
        throw std::domain_error("Border must be non-negative");
    if (border > INT_MAX / 2 || border * 2 > INT_MAX - qr.getSize())
        throw std::overflow_error("Border too large");

    std::ostringstream sb;
    sb << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    sb << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    sb << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 ";
    sb << (qr.getSize() + border * 2) << " " << (qr.getSize() + border * 2) << "\" stroke=\"none\">\n";
    sb << "\t<rect width=\"100%\" height=\"100%\" fill=\"#FFFFFF\"/>\n";
    sb << "\t<path d=\"";
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            if (qr.getModule(x, y)) {
                if (x != 0 || y != 0)
                    sb << " ";
                sb << "M" << (x + border) << "," << (y + border) << "h1v1h-1z";
            }
        }
    }
    sb << "\" fill=\"#000000\"/>\n";
    sb << "</svg>\n";
    return sb.str();
}


// Prints the given QrCode object to the console.
void QR_Code::printQr(const QrCode &qr) {

    string filename("nouveauRecu.txt");
    ofstream outfile(filename.c_str());

    int border = 4;
    for (int y = -border; y < qr.getSize() + border; y++) {
        for (int x = -border; x < qr.getSize() + border; x++) {
            outfile << (qr.getModule(x, y) ? "■■" : "  ");
        }
        outfile<<endl;
    }
    outfile<<endl;
}

void QR_Code::printRecu(const QrCode &qr,std::string idCommande,std::string montant,std::string nbpieces,std::string idEmploye,std::string idClient,std::string dateRetrait,std::string dateDepot) {

    string filename("nouveauRecu.txt");
    ofstream outfile(filename.c_str());

    int border = 1;

    outfile<<"ID COMMANDE:"<<idCommande<<endl;
    outfile<<qr.getSize()<<"ID CLIENT:"<<idClient<<endl;
    outfile<<"ID EMPLOYE:"<<idEmploye<<endl;
    outfile<<"NOMBRE DE PIECES:"<<nbpieces<<endl;
    outfile<<"MONTANT:"<<montant<<endl;
    outfile<<"DATE DEPOT:"<<dateDepot<<endl;
    outfile<<"DATE RETRAIT:"<<dateRetrait<<endl;

    for (int y = -border; y < qr.getSize() + border; y++) {
        for (int x = -border; x < qr.getSize() + border; x++) {
            outfile << (qr.getModule(x, y) ? "■■" : "  ");
        }
        outfile<<endl;
    }
    outfile<<endl;
}
