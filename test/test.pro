QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enregistreclients.cpp \
    enregistrelivres.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ClientClass.h \
    Emprunt.h \
    Livre.h \
    client.h \
    connexion_sqlite3.h \
    connexionmysql.h \
    enregistreclients.h \
    enregistrelivres.h \
    mainwindow.h \
    query_client.h \
    query_emprunt.h \
    query_livre.h \
    utils.h

FORMS += \
    connexionbasededonnee.ui \
    dialog.ui \
    enregistreEmprunt.ui \
    enregistreclients.ui \
    enregistrelivres.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
