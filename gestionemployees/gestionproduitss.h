#ifndef GESTIONPRODUITSS_H
#define GESTIONPRODUITSS_H

#include <QDialog>

namespace Ui {
class gestionproduitss;
}

class gestionproduitss : public QDialog
{
    Q_OBJECT

public:
    explicit gestionproduitss(QWidget *parent = nullptr);
    ~gestionproduitss();

private:
    Ui::gestionproduitss *ui;
};

#endif // GESTIONPRODUITSS_H
