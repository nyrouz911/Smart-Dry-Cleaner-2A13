#ifndef GESTIONEMPLOYES_H
#define GESTIONEMPLOYES_H

#include <QMainWindow>
#include <QDialog>
#include "employes.h"
#include "message.h"
#include "mainwindow.h"

namespace Ui {
class gestionemployes;
}

class gestionemployes : public QDialog
{
    Q_OBJECT

public:
    explicit gestionemployes(QWidget *parent = nullptr);
   // ~gestionemployes();

private slots:


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

private:
    Ui::gestionemployes *ui;
   Employes e;
    Message m;
    Employes insemployes;
    QStringList files;
};
#endif // MAINWINDOW_H
