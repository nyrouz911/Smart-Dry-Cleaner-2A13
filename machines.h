#ifndef MACHINES_H
#define MACHINES_H

#include <QDialog>
#include "machine.h"
#include <QVBoxLayout>
#include "smtp.h"
#include <QBarSet>
#include <QBarSeries>

namespace Ui {
class Machines;
}

class Machines: public QDialog
{
    Q_OBJECT
public:
    explicit Machines(QWidget *parent = nullptr);
    ~Machines();

 private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_chercher_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_intervention_clicked();

    void on_pushButton_2_clicked();

    //void on_chercher_textChanged(QString &arg1);

    void on_cbsearch_activated(const QString &arg1);

    void on_envoyer_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_trifab_clicked();

    void on_tritype_clicked();

    void on_trietat_clicked();

    void on_clear_clicked();

private:
    Ui::Machines *ui;
    Machine_f Machtmp;
};

#endif // MACHINES_H
