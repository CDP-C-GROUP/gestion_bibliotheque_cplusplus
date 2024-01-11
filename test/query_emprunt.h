#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "Emprunt.h"
#include "connexion_sqlite3.h"
//#include "query_livre.h"
//#include "query_client.h"

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

        //QList<Livre> livres = get_all_livres();
        //QList<Client> clients = get_all_clients();

        Livre livre = Livre("", "", "", "", "0");
        Client client = Client("", "", "");

        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString livre_id = query.value("livre_id").toString();
            QString client_id = query.value("client_id").toString();
            QString date_emprunt = query.value("date_emprunt").toString();
            QString date_retour = query.value("date_retour").toString();




            //Emprunt emprunt = Emprunt(code, nom, auteur, date_parution, quantite);
            //emprunts.append(emprunt);
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
