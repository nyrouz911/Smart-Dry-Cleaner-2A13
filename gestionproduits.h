/*#ifndef GESTIONPRODUITS_H
#define GESTIONPRODUITS_H
#include <QMainWindow>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QDialog>
#include "produit.h"
#include "ui_gestionproduit.h"
//#include "arduino.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class GestionProduits;
}
QT_END_NAMESPACE




class GestionProduits : public QDialog
{
    Q_OBJECT

public:
    explicit GestionProduits(QWidget *parent = nullptr);
    //GestionProduits(QWidget *parent = nullptr);
    ~GestionProduits();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

private:
    Ui::GestionProduits *ui;
    produit tmpproduit;
    //Arduino ard;
};

#endif // GESTIONPRODUITS_H
*/
