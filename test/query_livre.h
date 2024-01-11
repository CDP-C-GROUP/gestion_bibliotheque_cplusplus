#include "QSqlDatabase"
#include <QSqlQuery>
#include <QSqlError>
#include "QString"
#include <QDebug>
#include "Livre.h"
#include "connexion_sqlite3.h"

bool save_livre(Livre livre){
    if (is_connexion_db()) {
        if (livre.code.isEmpty() || livre.nom.isEmpty() || livre.auteur.isEmpty() || livre.date_parution.isEmpty() || livre.get_quantite() < 1) {
            box_message("Veuillez renseigner tous les champs.");
            return false;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO livre (code, nom, auteur, date_parution, quantite) VALUES (:code, :nom, :auteur, :date_parution, :quantite)");
        query.bindValue(":code", livre.code);
        query.bindValue(":nom", livre.nom);
        query.bindValue(":auteur", livre.auteur);
        query.bindValue(":date_parution", livre.date_parution);
        query.bindValue(":quantite", livre.get_quantite());

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
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            QString quantite = query.value("quantite").toString();

            Livre livre = Livre(code, nom, auteur, date_parution, quantite);
            livre.id = id;
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
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            QString quantite = query.value("quantite").toString();

            Livre livre(code, nom, auteur, date_parution, quantite);
            livre.id = id;
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
            QString quantite = query.value("quantite").toString();

            Livre livre = Livre(code, nom, auteur, date_parution, quantite);
            livre.id = id;
            return livre;
        }

    }
    return livre;
}

Livre get_livre_by_id(int id){
    Livre livre = Livre("", "", "", "", 0);
    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre WHERE id = :id");
        query.bindValue(":id", id);
        if (query.exec() && query.next()) {
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            QString quantite = query.value("quantite").toString();

            Livre livre = Livre(code, nom, auteur, date_parution, quantite);
            livre.id = id;
            return livre;
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

bool delete_livre_by_id(int code){
    QSqlQuery query;
    query.prepare("DELETE FROM livre WHERE id = :code");
    query.bindValue(":code", code);

    return query.exec();
}

//renvoyer le nombre de lignes enregistrer
qint32 nombreligne_livre_enreg(){

    //déclaration de la variable qui va contenir le nombre de ligne de livre enregistrer et initialisé à 0
    qint32 nblivreenreg(0);

    if (is_connexion_db()) {
        //la requête qui permet d'enregistrerle nombre de ligne de livres enregistres
        QSqlQuery query("SELECT count(*) FROM livre");
        while (query.next()) {
            nblivreenreg = query.value(0).toInt();
        }

    }
    return nblivreenreg;
}
