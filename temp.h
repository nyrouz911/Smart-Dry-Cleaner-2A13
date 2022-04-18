#ifndef TEMP_H
#define TEMP_H

#include <QDialog>
#include <QMessageBox>
#include "connection.h"
#include "QSqlDatabase"
#include "arduino.h"


namespace Ui {
class temp;
}

class temp : public QDialog
{
    Q_OBJECT

public:
    explicit temp(QWidget *parent = nullptr);
    ~temp();

private slots:
    void on_actualiser_clicked();

private:
    Ui::temp *ui;
    Arduino t;
};

#endif // TEMP_H
