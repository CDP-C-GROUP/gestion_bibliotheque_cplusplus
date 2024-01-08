#ifndef CONNEXIOON_SQLITE_H
#define CONNEXIOON_SQLITE_H

#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "utils.h"
#include "QString"
#include <QDebug>
#include <QStandardPaths>

static bool is_connexion_db(){
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE"); //Spécification de la DB

    //QString databasePath = "E:/ecole/C++/ProjectG2/maj1/maj1/library.db";
    //QString databasePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/library.db";
    QString databasePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/library.db"; //Home location
    qDebug() << "Database file location:" << databasePath;
    database.setDatabaseName(databasePath);

    //database.setDatabaseName("library.db"); //Créer ou appeler la DB sqlite3 sous le nom "library.db"

    if (!database.open()) {
        //Appel de la fonction Box personnalisée en passant le message
        box_message("Un problème est survenu lors de la connexion à la base de données");
        return false;
    }
    return true;
}

static void connexion_db(){
    if (is_connexion_db()) {
        //Création des tables livre, client et emprunt
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS livre (id INTEGER PRIMARY KEY, code TEXT, nom TEXT, auteur TEXT, date_parution TEXT, quantite INTEGER)");
        query.exec("CREATE TABLE IF NOT EXISTS client (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, tel TEXT)");
        query.exec("CREATE TABLE IF NOT EXISTS emprunt (id INTEGER PRIMARY KEY, livre_id INTEGER, client_id INTEGER, date_emprunt TEXT, date_retour TEXT)");
    }
}

#endif //CONNEXIOON_SQLITE_H
