#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "commandes.h"


#include <QTranslator>
#include <QFontDialog>

#include "arduino.h"

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
    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

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

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void update_label();   // slot permettant la mise à jour de la partie "Attribuer des Points de Fidelite" Quand des donnes sont recu de la carte Arduino,
        // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Commandes Etmp;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
