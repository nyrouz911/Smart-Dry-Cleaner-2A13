#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include"notification.h"
#include"abonnement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
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

private :
    Ui::MainWindow *ui;
   client cl;
   Notification n;
   abonnement a;
};
#endif // MAINWINDOW_H
