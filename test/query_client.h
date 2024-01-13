//cette classe nous permet de faire toutes les opérations de CRUD sur le client
#ifndef CLASS_CLIENT_QUERY_H
#define CLASS_CLIENT_QUERY_H

#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "ClientClass.h"
#include "connexion_sqlite3.h"

//renvoyer l'identifiant d'un client à partir du nom, prenom et du numero de téléphone du client
int renvoyer_idclient_par_nom_prenom_tel_client(QString param_nom, QString param_prenom, QString param_tel){

    int idclient(0);

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM client WHERE nom =':nom' AND  prenom = ':prenom' AND tel =':tel' ");
        query.bindValue(":nom", param_nom);
        query.bindValue(":prenom", param_prenom);
        query.bindValue(":tel", param_tel);

        while (query.next()) {
            //retourner la valeur de l'idclient
            idclient = query.value("id").toString().toInt();
        }

    }

    return idclient;
}

//pour ajouter un client dans la base de données
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

//pour modifier un client à partir de son identifiant
bool update_client(Client client){
    if (is_connexion_db()) {
        if ( client.nom.isEmpty() || client.prenom.isEmpty() || client.tel.isEmpty() ) {
            box_message("Veuillez renseigner tous les champs.");
            return false;
        }

        QSqlQuery query;
        query.prepare("UPDATE client SET nom = :nom, prenom = :prenom, tel = :tel WHERE nom = :name ");
        query.bindValue(":name", client.nom);
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

// pour renvoyer la liste de tous les clients
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

//pour trier la liste des clients à partir du nom
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

//Rechercher un client à partir de son numero de téléphone
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

//supprimer un client à partir de son numero de téléphone
bool delete_client_by_tel(QString tel){
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE tel = :tel");
    query.bindValue(":tel", tel);

    return query.exec();
}

//supprimer un client à partir de son identifiant
bool delete_client_by_id(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE id = :id");
    query.bindValue(":id", id);

    return query.exec();
}

#endif // CLASS_CLIENT_QUERY_H
