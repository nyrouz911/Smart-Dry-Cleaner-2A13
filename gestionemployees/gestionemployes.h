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
#include "machine.h"
#include "intervention.h"
#include "mail.h"
#include "smtp.h"

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


    void on_ajouter_3_clicked();

    void on_pushButton_livraison_clicked();

    void on_pushButton_retourb_clicked();

    // bouton nayrouz

    void on_intervention_clicked();

    void on_chercher_textChanged(const QString &arg1);

    void on_trifab_clicked();

    void on_tritype_clicked();

    void on_trietat_clicked();

    void on_clear_clicked();

    void on_ajouter_2_clicked();

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_12_clicked();

    void on_retourbrahym_clicked();

    void on_on_ajouter_clicked();

    // boutons miguel
   // void on_pushButton_3_clicked();

   // void on_pushButton_5_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    //void on_pushButton_clicked();

    void on_Boutton_Afiche_Commades_clicked();

    void on_Boutton_aller_a_ajouterCommande_clicked();

    void on_comboBox_4_activated(int index);

    void on_tableWidget_2_cellChanged(int row, int column);

    //void on_tableWidget_2_itemChanged(QTableWidgetItem *item);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);

    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

   // void on_pushButton_7_clicked();

   // void on_pushButton_2_clicked();

    //void on_pushButton_10_clicked();

    //void on_pushButton_11_clicked();

   // void on_pushButton_12_clicked();

    void update_label();   // slot permettant la mise à jour de la partie "Attribuer des Points de Fidelite" Quand des donnes sont recu de la carte Arduino,
        // ce slot est lancé à chaque réception d'un message de Arduino

    //void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    //void on_pushButton_15_clicked();

   // void on_pushButton_8_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_80_clicked();

    void on_modifier_3_clicked();

    void on_supprimer_3_clicked();

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
   livraison l;
   livraison inslivraison;
   Machine_f Machtmp;
   Machine_f insMachine_f;
};
#endif // MAINWINDOW_H
