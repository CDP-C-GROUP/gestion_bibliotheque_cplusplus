#ifndef CLASS_EMPRUNT_CPP_H
#define CLASS_EMPRUNT_CPP_H

//nous allons importer l'entête de notre fenêtre d'enregsitrement des emprunts
#include "enregistreEmprunts.h"
#include "ui_enregistreEmprunts.h"
//nous appellons ici la fenêtre d'enregistrement des emprunts pour pouvoir avoir accès aux champs de saisie


//nous appellons la bibliothèque pour utiliser une boite de dialogue
#include "QMessageBox"

//nous appellons la bibliothèque pour utiliser les string
#include "QString"
#include <iostream>
#include <string.h>
#include "query_emprunt.h"
#include <QDebug>

QList<Livre> livres;
QList<Client> clients;

Livre get_livre_by_currently_index(QString txt){
    Livre l = Livre("", "", "", "", "0");
    for(Livre livre: livres){
        if(livre.code + " - " + livre.nom == txt){
           return livre;
        }
    }
    return l;
}

Client get_client_by_currently_index(QString txt){
   Client c = Client("", "", "");
   for(Client client: clients){
       if(client.nom + " - " + client.prenom == txt){
          return client;
       }
   }
   return c;
}

enregistreEmprunts::enregistreEmprunts(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistreEmprunts)
{
    ui->setupUi(this);

    if (is_connexion_db()) {
        QSqlQuery query("SELECT * FROM livre");
        while (query.next()) {
            int id = query.value("id").toString().toInt();
            QString code = query.value("code").toString();
            QString nom = query.value("nom").toString();
            QString auteur = query.value("auteur").toString();
            QString date_parution = query.value("date_parution").toString();
            QString quantite = query.value("quantite").toString();

            ui->champNomLivre->addItem(code + " - " + nom, query.value("id").toString());


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

            ui->champNomAbonne->addItem(nom + " - " + prenom, queryClient.value("id").toString());


            Client client = Client(nom, prenom, tel);
            client.id = idClient;
            clients.append(client);
        }

    }
    QDate date;
    ui->champDateEmprunt->setDate(date.currentDate());
    ui->champDateRetour->setDate(date.currentDate());


    //nous allons afficher la liste des emprunts
    enregistreEmprunts::tableaffichelisteEmprunt();
}

enregistreEmprunts::~enregistreEmprunts()
{
    delete ui;
}

// lorsque l'utilisateur va cliquer sur le bouton validé
void enregistreEmprunts::on_BTNValider_clicked()
{
    //déclaration de ka variable de type string
    QString valeursaisie;

    Livre livre = get_livre_by_currently_index(ui->champNomLivre->itemText(ui->champNomLivre->currentIndex()));
    Client client = get_client_by_currently_index(ui->champNomAbonne->itemText(ui->champNomAbonne->currentIndex()));

    //nous allons prendre les valeurs saisies par l'utilisateur dans chaque champs de saisie
    valeursaisie = "Voici vos informations saisies: "

                   "\nLivre: "+livre.code + " - " + livre.nom +
                   "\nPClient: "+client.nom + " - " + client.prenom +
                   "\nDate d'emprunt: "+ui->champDateEmprunt->text()+
                    "\nDate de retour: "+ui->champDateRetour->text()
            ;

    Emprunt emprunt = Emprunt(livre, client, ui->champDateEmprunt->text(), ui->champDateRetour->text());

    save_emprunt((emprunt)); //Enregistrer le emprunt dans la base de données

    //afficher la liste des livres dans la table
    tableaffichelisteEmprunt();


    //nous allons afficher dans le label "infoclient" les valeurs saisies par l'utilisateur
    ui->infoEmprunt->setText(valeursaisie);

    //Appel de la fonction Box personnalisée en passant le message
    box_message(valeursaisie+"\n\nPAR LA GRACE DE PAPA AU CIEL ON VA Y ARRIVER COURAGE !!!");

}

// lorsque l'utilisateur va cliquer sur le bouton nouveau
void enregistreEmprunts::on_BTNNouveau_clicked()
{

}


void enregistreEmprunts::on_enregistreEmprunts_windowTitleChanged(const QString &title)
{
    QMessageBox info;
    info.setText(title);
    info.setIcon(QMessageBox::Information);
    info.setStandardButtons(QMessageBox::Ok);

    // Affichage de la boîte de dialogue
    info.exec();
}


//implémentation de la procédure qui permet d'afficher la liste des emprunts dans une table
void enregistreEmprunts::tableaffichelisteEmprunt(){

    //nous initialisons le nombre de ligne à 0
    int row(0);

    QList<Emprunt> emprunts = get_all_emprunts();

    //nous allons initialiser le modèle de table de emprunt que nous avons déclarer dans le .h
    //notre modèle de table doit avoir exactement le total des attributs de la table emprunt comme nbre de colonnes
    //le totale des enregistrements comme nombre de lignes
    modeleTableEmprunt = new QStandardItemModel(emprunts.length(),4);

    for (Emprunt emprunt : emprunts) {
        modeleTableEmprunt->setItem(row,0, new QStandardItem(emprunt.livre.code + " - " + emprunt.livre.nom));
        modeleTableEmprunt->setItem(row,1, new QStandardItem(emprunt.client.nom + " - " + emprunt.client.prenom));
        modeleTableEmprunt->setItem(row,2, new QStandardItem(emprunt.date_emprunt));
        modeleTableEmprunt->setItem(row,3, new QStandardItem(emprunt.date_retour));
        row++;
    }

    //nous allons donc ajouter à notre modèle, les libelles des colonnes de notre table emprunt
    modeleTableEmprunt->setHeaderData(0,Qt::Horizontal,"Livre");
    modeleTableEmprunt->setHeaderData(1,Qt::Horizontal,"Client");
    modeleTableEmprunt->setHeaderData(2,Qt::Horizontal,"Date Emprunt");
    modeleTableEmprunt->setHeaderData(3,Qt::Horizontal,"Date Retour");

     //affecter notre modèle à la tableview
     ui->tableViewEmprunt->setModel(modeleTableEmprunt);

}


#endif // CLASS_EMPRUNT_CPP_H
