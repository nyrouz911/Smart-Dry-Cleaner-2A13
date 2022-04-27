#include "notification.h"

Notification::Notification()
{

}

void Notification::notification_ajoutab()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client ","un nouveau abonnement est ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimerab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client ","un abonnement est supprimé",QSystemTrayIcon::Information,15000);
}


void Notification::notification_modifierab(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client ","un nouveau abonnement est modifié",QSystemTrayIcon::Information,15000);

}
void Notification::notification_ajoutc()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client "," un nouveau client est ajouté ",QSystemTrayIcon::Information,15000);
}

void Notification::notification_supprimerc(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client "," un client a été supprimé",QSystemTrayIcon::Information,15000);
}


void Notification::notification_modifierc(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des client "," un client a été modifié",QSystemTrayIcon::Information,15000);

}
