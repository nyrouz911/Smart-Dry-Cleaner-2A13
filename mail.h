#ifndef MAIL_H
#define MAIL_H

#include <QDialog>

namespace Ui {
class mail;
}

class mail : public QDialog
{
    Q_OBJECT

public:
    explicit mail(QWidget *parent = nullptr);
    ~mail();

private slots:
    void sendMail();
        void mailSent(QString) ;

        //void on_mailing_clicked();

        void on_envoyer_clicked();

private:
    Ui::mail *ui;
};

#endif // MAIL_H

