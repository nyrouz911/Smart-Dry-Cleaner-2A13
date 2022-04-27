#ifndef INTERVENTIONS_H
#define INTERVENTIONS_H

#include "intervention.h"
#include <QVBoxLayout>


#include <QDialog>

namespace Ui {
class interventions;
}

class interventions : public QDialog
{
    Q_OBJECT

public:
    explicit interventions(QWidget *parent = nullptr);
    ~interventions();

private slots:
    void on_ajouter_main_clicked();

    void on_supprimer_main_clicked();

    void on_modifier_main_clicked();



    void on_mail_clicked();

    void on_chercher_textChanged(const QString &arg1);

private:
    Ui::interventions *ui;
    intervention intertmp;
};

#endif // INTERVENTIONS_H
