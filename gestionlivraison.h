/*#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H

#include <QDialog>

namespace Ui {
class gestionlivraison;
}

class gestionlivraison : public QDialog
{
    Q_OBJECT

public:
    explicit gestionlivraison(QWidget *parent = nullptr);
    ~gestionlivraison();

private:
    Ui::gestionlivraison *ui;
};

#endif // GESTIONLIVRAISON_H  */


#ifndef GESTIONLIVRAISON_H
#define GESTIONLIVRAISON_H

#include <QDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QMainWindow>
#include "livraison.h"

QT_BEGIN_NAMESPACE
namespace Ui { class gestionlivraison; }
QT_END_NAMESPACE

class gestionlivraison : public QDialog
{
    Q_OBJECT

public:
    gestionlivraison(QWidget *parent = nullptr);
    ~gestionlivraison();
     void title();

private slots:
     //void on_pushButton_clicked();

     void on_ajouter_clicked();

     void on_supprimer_clicked();

     void on_modifier_clicked();

     void on_chercherid_clicked();

     void on_cherchedate_clicked();

     void on_cherchernum_clicked();

     void on_trierid_clicked();

     void on_trierdate_clicked();

     void on_triernum_clicked();

     void on_generer_clicked();

     void on_Francais_clicked();

     void on_Anglais_clicked();

     void on_Excel_clicked();

private:
    Ui::gestionlivraison *ui;
    livraison l;
    //livraison inslivraison;
     //QStringList files;
};
#endif // GESTIONLIVRAISON_H
