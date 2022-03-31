#ifndef MESSAGE_H
#define MESSAGE_H

#include <QDialog>

namespace Ui {
class message;
}

class message : public QDialog
{
    Q_OBJECT

/*public:
    explicit message(QWidget *parent = nullptr);
    ~message();

private:
    Ui::message *ui;
};

#endif // MESSAGE_H*/
public:
    explicit message(QWidget *parent = nullptr);
    ~message();
    QString hostname() const;
    quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::message *ui;
    QString mHostname;
    quint16 mPort;
};
inline QString message::hostname() const
{
    return mHostname;
}

inline quint16 message::port() const
{
    return mPort;
}

#endif // MESSENGERCONNECTION_H
