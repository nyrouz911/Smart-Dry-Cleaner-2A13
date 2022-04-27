#ifndef GESTIONEMPLOYES_H
#define GESTIONEMPLOYES_H

#include <QMainWindow>
#include <QDialog>
#include "employes.h"
#include "message.h"
#include "mainwindow.h"
#include "client.h"
#include"notification.h"
#include"abonnement.h"
#include"livraison.h"

namespace Ui {
class gestionemployes;
}

class gestionemployes : public QDialog
{
    Q_OBJECT

public:
    explicit gestionemployes(QWidget *parent = nullptr);
   //~gestionemployes();

private slots:


//bouton mayssen
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_rechPB_activated(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_comboRech_activated(const QString &arg1);
    void on_comboBox_currentTextChanged(const QString &arg1);



    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_send_clicked();

    void on_afficherM_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_33_clicked();

// bouttons nour
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifer_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_tri_id_clicked();

    void on_pushButton_tri_nom_clicked();

    void on_pushButton_tri_prenom_clicked();

    void on_pushButton_tri_num_clicked();

    void on_lineEdit_recherche_textChanged(const QString &arg1);

    void on_pushButton_modifer_ab_2_clicked();

    void on_pushButton_modifer_ab_clicked();

    void on_pushButton_supprimer_ab_clicked();

    void on_pushButton_afficher_ab_clicked();

    void on_pushButton_ajouter_ab_clicked();

    void on_pushButton_suivant_clicked();

    void on_pushButton_retour_ab_clicked();

    void on_pushButton_tri_id_ab_clicked();

    void on_pushButton_tri_ab_clicked();

    void on_pushButton_tri_point_ab_clicked();

    void on_lineEdit_rech_ab_textChanged(const QString &arg1);

//bouton brahym
    //void on_pushButton_clicked();

  /*  void on_ajouter_clicked();

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


    void on_ajouter_3_clicked();*/

private:
    Ui::gestionemployes *ui;
   Employes e;
    Message m;
    Employes insemployes;
    QStringList files;
   client cl;
    Notification n;
    abonnement a;
   client insclient;
   //livraison l;
   //livraison inslivraison;

};
#endif // MAINWINDOW_H
