QT       += core gui charts sql

QT += printsupport
QT       += core gui
QT       += core gui sql
QT += core gui network
QT       += charts serialport multimedia multimediawidgets  widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = mail
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

CONFIG += console
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
    connection.cpp \
    intervention.cpp \
    interventions.cpp \
    machine.cpp \
    machines.cpp \
    mail.cpp \
    main.cpp \
    smtp.cpp

HEADERS += \
    connection.h \
    intervention.h \
    interventions.h \
    machine.h \
    machines.h \
    mail.h \
    smtp.h

FORMS += \
    interventions.ui \
    machines.ui \
    mail.ui \
    mail.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    translations.qrc
