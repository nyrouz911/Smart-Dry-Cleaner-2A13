#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "messengerconnection.h"



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

private:
    Ui::MainWindow *ui;
    Employee e;
};
#endif // MAINWINDOW_H
