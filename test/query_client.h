#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "ClientClass.h"
#include "connexion_sqlite3.h"

bool save_client(Client client){
    if (is_connexion_db()) {
        if (client.nom.isEmpty() || client.prenom.isEmpty() || client.tel.isEmpty()) {
            box_message("Veuillez renseigner tous les champs.");
            return false;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO client (nom, prenom, tel) VALUES (:nom, :prenom, :tel)");
        query.bindValue(":nom", client.nom);
        query.bindValue(":prenom", client.prenom);
        query.bindValue(":tel", client.tel);

        if (query.exec()) {
            return true;
        } else {
            // Error handling
            qDebug() << "Error: " << query.lastError().text();
        }
    }
    return false;
}


QList<Client> get_all_clients(){
    QList<Client> clients;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM client");
        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            QString tel = query.value("tel").toString();

            Client client = Client(nom, prenom, tel);
            client.id = id;
            clients.append(client);
        }

    }
    return clients;
}

QList<Client> get_like_clients_by_columns(QString txt){
    QList<Client> clients;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM client WHERE nom LIKE '%:nom%' OR prenom LIKE '%:prenom%' OR tel LIKE '%:tel%'");
        query.bindValue(":nom", txt);
        query.bindValue(":prenom", txt);
        query.bindValue(":tel", txt);
        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            QString tel = query.value("tel").toString();

            Client client = Client(nom, prenom, tel);
            client.id = id;
            clients.append(client);
        }

    }
    return clients;
}

Client get_client_by_code(QString tel){
    Client cleint = Client("", "", "");
    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM client WHERE tel = :tel");
        query.bindValue(":tel", tel);
        if (query.exec() && query.next()) {
            int id = query.value("id").toString().toInt();
            QString nom = query.value("nom").toString();
            QString prenom = query.value("prenom").toString();
            QString tel = query.value("tel").toString();

            Client client = Client(nom, prenom, tel);
            client.id = id;
            return client;
        }

    }
    return cleint;
}


bool delete_client_by_tel(QString tel){
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE tel = :tel");
    query.bindValue(":tel", tel);

    return query.exec();
}

bool delete_client_by_id(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id = :id");
    query.bindValue(":id", id);

    return query.exec();
}
