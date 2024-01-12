#ifndef CLASS_EMPRUNT_QUERY_H
#define CLASS_EMPRUNT_QUERY_H

#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "Emprunt.h"
#include "connexion_sqlite3.h"


Livre get_livre_by_id(QList<Livre> livres, int id){
    Livre l = Livre("", "", "", "", "0");
    for(Livre livre: livres){
        if(livre.id == id){
           return livre;
        }
    }
    return l;
}

Client get_client_by_id(QList<Client> clients, int id){
   Client c = Client("", "", "");
   for(Client client: clients){
       if(client.id == id){
          return client;
       }
   }
   return c;
}


bool save_emprunt(Emprunt emprunt){
    if (is_connexion_db()) {
        if (emprunt.livre.code.isEmpty() || emprunt.client.nom.isEmpty() || emprunt.date_emprunt.isEmpty() || emprunt.date_retour.isEmpty()) {
            box_message("Veuillez renseigner tous les champs.");
            return false;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO emprunt (livre_id, client_id, date_emprunt, date_retour) VALUES (:livre_id, :client_id, :date_emprunt, :date_retour)");
        query.bindValue(":livre_id", emprunt.livre.id);
        query.bindValue(":client_id", emprunt.client.id);
        query.bindValue(":date_emprunt", emprunt.date_emprunt);
        query.bindValue(":date_retour", emprunt.date_retour);

        if (query.exec()) {
            return true;
        } else {
            // Error handling
            qDebug() << "Error: " << query.lastError().text();
        }
    }
    return false;
}


QList<Emprunt> get_all_emprunts(){
    QList<Emprunt> emprunts;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM emprunt");

        QList<Livre> livres;
        QList<Client> clients;
        QSqlQuery queryLivre("SELECT * FROM livre");
        while (queryLivre.next()) {
            int id = queryLivre.value("id").toString().toInt();
            QString code = queryLivre.value("code").toString();
            QString nom = queryLivre.value("nom").toString();
            QString auteur = queryLivre.value("auteur").toString();
            QString date_parution = queryLivre.value("date_parution").toString();
            QString quantite = queryLivre.value("quantite").toString();

            Livre livre = Livre(code, nom, auteur, date_parution, quantite);
            livre.id = id;
            livres.append(livre);
        }

        QSqlQuery queryClient("SELECT * FROM client");
        while (queryClient.next()) {
            int idClient = queryClient.value("id").toString().toInt();
            QString nom = queryClient.value("nom").toString();
            QString prenom = queryClient.value("prenom").toString();
            QString tel = queryClient.value("tel").toString();

            Client client = Client(nom, prenom, tel);
            client.id = idClient;
            clients.append(client);
        }



        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString livre_id = query.value("livre_id").toString();
            QString client_id = query.value("client_id").toString();
            QString date_emprunt = query.value("date_emprunt").toString();
            QString date_retour = query.value("date_retour").toString();
            qDebug() << "Error livre_id : " << livre_id;
            qDebug() << "Error client_id : " << client_id;
            Livre livre = Livre("", "", "", "", "0");

            Emprunt emprunt = Emprunt(get_livre_by_id(livres, livre_id.toInt()), get_client_by_id(clients, client_id.toInt()), date_emprunt, date_retour);
            emprunts.append(emprunt);
        }

    }
    return emprunts;
}
/*
QList<Livre> get_like_livres_by_columns(QString txt){
    QList<Livre> livres;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre WHERE code LIKE '%:code%' OR nom LIKE '%:nom%' OR auteur LIKE '%:auteur%' OR date_parution LIKE '%:date_parution%'");
        query.bindValue(":code", txt);
        query.bindValue(":nom", txt);
        query.bindValue(":auteur", txt);
        query.bindValue(":date_parution", txt);
        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            int quantite = query.value("quantite").toInt();

            Livre livre(code, nom, auteur, date_parution, quantite);
            livres.append(livre);
        }

    }
    return livres;
}


Livre get_livre_by_code(QString code){
    Livre livre = Livre("", "", "", "", 0);
    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre WHERE code = :code");
        query.bindValue(":code", code);
        if (query.exec() && query.next()) {
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            int quantite = query.value("quantite").toInt();

            return Livre(code, nom, auteur, date_parution, quantite);
        }

    }
    return livre;
}


bool delete_livre_by_code(QString code){
    QSqlQuery query;
    query.prepare("DELETE FROM livre WHERE code = :code");
    query.bindValue(":code", code);

    return query.exec();
}
*/

#endif // CLASS_EMPRUNT_QUERY_H
