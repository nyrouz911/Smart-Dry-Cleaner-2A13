#ifndef GESTIONMACHINE_H
#define GESTIONMACHINE_H


#include <QDialog>
#include <QMessageBox>
#include "machine.h"
#include <QVBoxLayout>
#include "smtp.h"
//#include "arduino.h"


namespace Ui {
class gestionmachine;
}

class gestionmachine: public QDialog
{
    Q_OBJECT
public:
    explicit gestionmachine(QWidget *parent = nullptr);
     ~gestionmachine();

 private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_intervention_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_trifab_clicked();

    void on_tritype_clicked();

    void on_trietat_clicked();

    void on_clear_clicked();



private:
    Ui::gestionmachine *ui;
    Machine_f Machtmp;


    //Arduino t;
    QByteArray data;
};

#endif // MACHINES_H
