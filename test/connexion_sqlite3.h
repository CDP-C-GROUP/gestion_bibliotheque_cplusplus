#ifndef CONNEXIOON_SQLITE_H
#define CONNEXIOON_SQLITE_H

#include "QSqlDatabase"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

static bool is_connexion_db(){
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE"); //Spécification de la DB
    database.setDatabaseName("library.db"); //Créer ou appeler la DB sqlite3 sous le nom "library.db"

    if (!database.open()) {
        //QMessageBox::critical(this, "Error", "Failed to open the database: " + database.lastError().text());
        return false;
    }

    //Création des tables livre, client et emprunt
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS livre (id INTEGER PRIMARY KEY, code TEXT, nom TEXT, auteur TEXT, date_parution TEXT, quante INTEGER)");
    query.exec("CREATE TABLE IF NOT EXISTS client (id INTEGER PRIMARY KEY, nom TEXT, prenom TEXT, tel TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS emprunt (id INTEGER PRIMARY KEY, livre_id INTEGER, client_id INTEGER, date_emprunt TEXT, date_retour TEXT)");

    return true;
}

#endif //CONNEXIOON_SQLITE_H
