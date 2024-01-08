#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "Livre.h"
#include "connexion_sqlite3.h"

bool save_livre(Livre livre){
    if (is_connexion_db()) {
        if (livre.code.isEmpty() || livre.nom.isEmpty() || livre.auteur.isEmpty() || livre.date_parution.isEmpty() || livre.quantite < 1) {
            box_message("Veuillez renseigner tous les champs.");
            return false;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO livre (code, nom, auteur, date_parution, quantite) VALUES (:code, :nom, :auteur, :date_parution, :quantite)");
        query.bindValue(":code", livre.code);
        query.bindValue(":nom", livre.nom);
        query.bindValue(":auteur", livre.auteur);
        query.bindValue(":date_parution", livre.date_parution);
        query.bindValue(":quantite", livre.quantite);

        if (query.exec()) {
            return true;
        } else {
            // Error handling
            qDebug() << "Error: " << query.lastError().text();
        }
    }
    return false;
}


//Livre requests
QList<Livre> get_all_livres(){
    QList<Livre> livres;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre");
        while (query.next()) {
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            int quantite = query.value("quantite").toInt();

            Livre livre = Livre(code, nom, auteur, date_parution, quantite);
            livres.append(livre);
        }

    }
    return livres;
}

QList<Livre> get_like_livres_by_columns(QString txt){
    QList<Livre> livres;

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre WHERE code LIKE '%:code%' OR nom LIKE '%:nom%' OR auteur LIKE '%:auteur%' OR date_parution LIKE '%:date_parution%'");
        query.bindValue(":code", txt);
        query.bindValue(":nom", txt);
        query.bindValue(":auteur", txt);
        query.bindValue(":date_parution", txt);
        while (query.next()) {
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
