/*#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>

namespace Ui {
class gestionclient;
}

class gestionclient : public QDialog
{
    Q_OBJECT

public:
    explicit gestionclient(QWidget *parent = nullptr);
    ~gestionclient();

private:
    Ui::gestionclient *ui;
};

#endif // GESTIONCLIENT_H*/

#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H
#include "client.h"
#include"notification.h"
#include"abonnement.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class gestionclient; }
QT_END_NAMESPACE

class gestionclient : public QDialog
{
    Q_OBJECT

public:
   explicit gestionclient(QWidget *parent = nullptr);
   // ~gestionclient();


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
   // Ui::MainWindow *ui;
     Ui::gestionclient *ui;
   client cl;
   Notification n;
   abonnement a;
  client insclient;
   QStringList files;
};
#endif // GESTIONCLIENT_H
