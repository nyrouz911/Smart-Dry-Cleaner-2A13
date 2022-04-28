QT       += core gui sql
QT       +=  printsupport
QT       += core gui
QT += core gui network
QT       += serialport
QT       += core gui sql

QT       += core gui sql printsupport network serialport charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnement.cpp \
    arduino.cpp \
    client.cpp \
    commandes.cpp \
    connection.cpp \
    employes.cpp \
    gestionclient.cpp \
    gestionemployes.cpp \
    gestionlivraison.cpp \
    gestionmachine.cpp \
    gestionproduitss.cpp \
    gestionscommandes.cpp \
    intervention.cpp \
    interventions.cpp \
    livraison.cpp \
    machine.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    notification.cpp \
    produit.cpp \
    produitsss.cpp \
    qr_code.cpp \
    qrcodegen.cpp \
    smtp.cpp

HEADERS += \
    abonnement.h \
    arduino.h \
    client.h \
    commandes.h \
    connection.h \
    employes.h \
    gestionclient.h \
    gestionemployes.h \
    gestionlivraison.h \
    gestionmachine.h \
    gestionproduitss.h \
    gestionscommandes.h \
    intervention.h \
    interventions.h \
    livraison.h \
    machine.h \
    mail.h \
    mainwindow.h \
    message.h \
    notification.h \
    produit.h \
    produitsss.h \
    qr_code.h \
    qrcodegen.h \
    smtp.h

FORMS += \
    gestionclient.ui \
    gestionemployes.ui \
    gestionlivraison.ui \
    gestionmachine.ui \
    gestionproduitss.ui \
    gestionscommandes.ui \
    interventions.ui \
    mail.ui \
    mainwindow.ui \
    produitsss.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    traduction.qrc
