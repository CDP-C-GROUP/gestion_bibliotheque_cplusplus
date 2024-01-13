#ifndef CLASS_CLIENT_CPP_H
#define CLASS_CLIENT_CPP_H

//nous allons importer l'entête de notre fenêtre d'enregsitrement des clients
#include "enregistreclients.h"
#include "ui_enregistreclients.h"
//nous appellons ici la fenêtre d'enregistrement des clients pour pouvoir avoir accès aux champs de saisie


//nous appellons la bibliothèque pour utiliser une boite de dialogue
#include "QMessageBox"

//nous appellons la bibliothèque pour utiliser les string
#include "QString"


#include "query_client.h"



enregistreclients::enregistreclients(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistreclients)
{
    ui->setupUi(this);

    //initialiser les champs onload de l'application
    enregistreclients::initialisechampclient();

    //nous allons afficher la liste des clients
    enregistreclients::tableaffichelisteclient();
}

enregistreclients::~enregistreclients()
{
    delete ui;
}

// lorsque l'utilisateur va cliquer sur le bouton validé
void enregistreclients::on_BTNValider_clicked()
{
    //déclaration de ka variable de type string
    QString valeursaisie;


        //nous allons prendre les valeurs saisies par l'utilisateur dans chaque champs de saisie
        valeursaisie = "Voici vos informations saisies: "

                       "\nnom du client: "+ui->SAINomduClient->text()+
                       "\nPrenom du client: "+ui->SAIPrenomduClient->text()+
                       "\nTelephone du client: "+ui->SAITelephone->text();

        Client client = Client(
               ui->SAINomduClient->text(), ui->SAIPrenomduClient->text(),
               ui->SAITelephone->text()
            );
        save_client((client)); //Enregistrer le client dans la base de données

        //afficher la liste des livres dans la table
        tableaffichelisteclient();


    //nous allons afficher dans le label "infoclient" les valeurs saisies par l'utilisateur
    ui->infoclient->setText(valeursaisie);

    //Appel de la fonction Box personnalisée en passant le message
    box_message("Client ajouté avec succès");

}

// lorsque l'utilisateur va cliquer sur le bouton nouveau
void enregistreclients::on_BTNNouveau_clicked()
{
    initialisechampclient();
}


void enregistreclients::on_enregistreclients_windowTitleChanged(const QString &title)
{
    QMessageBox info;
    info.setText(title);
    info.setIcon(QMessageBox::Information);
    info.setStandardButtons(QMessageBox::Ok);

    // Affichage de la boîte de dialogue
    info.exec();
}


//implémentation de la procédure qui permet d'afficher la liste des clients dans une table
void enregistreclients::tableaffichelisteclient(){

    //nous initialisons le nombre de ligne à 0
    int row(0);

    QList<Client> clients = get_all_clients();

    //nous allons initialiser le modèle de table de client que nous avons déclarer dans le .h
    //notre modèle de table doit avoir exactement le total des attributs de la table client comme nbre de colonnes
    //le totale des enregistrements comme nombre de lignes
    modeleTableClient = new QStandardItemModel(clients.length(),3);

    for (Client client : clients) {
        modeleTableClient->setItem(row,0, new QStandardItem(client.nom));
        modeleTableClient->setItem(row,1, new QStandardItem(client.prenom));
        modeleTableClient->setItem(row,2, new QStandardItem(client.tel));
        row++;
    }

    //nous allons donc ajouter à notre modèle, les libelles des colonnes de notre table client
    modeleTableClient->setHeaderData(0,Qt::Horizontal,"Nom");
    modeleTableClient->setHeaderData(1,Qt::Horizontal,"Prénom");
    modeleTableClient->setHeaderData(2,Qt::Horizontal,"Téléphone");

     //affecter notre modèle à la tableview
     ui->tableViewClient->setModel(modeleTableClient);

}

#endif // CLASS_CLIENT_CPP_H

void enregistreclients::on_tableViewClient_clicked(const QModelIndex &index)
{
    //nous appellons la fonction implémenté ici
    affiche_une_ligne_table_client(index);
}

//cette fonction que nous avons déclarer dans le .h est implémenté ici
//elle nous permet d'afficher dans les champs de saisie  les valeurs contenues dans la TableView
void enregistreclients::affiche_une_ligne_table_client(const QModelIndex &index){

    //nous allons déclarer une variable qui prend la valeur de la cellule sélectionnée
    QString val;
    val = ui->tableViewClient->model()->data(index).toString();

    //nous allons donc rechercher la valeur sélectionnée par l'utilisateur dans la table livre et renvoyer ces informtions
    //nous allons ouvrir la connexion à la base de données
    if (is_connexion_db()) {

        //nous allons sélectionner tous les livres enregistrer
        QSqlQuery query("SELECT * FROM client WHERE nom = '"+val+"' or prenom = '"+val+"' or tel = '"+val+"' ");

        //tanque nous pouvons lire les lignes de la requête
        while (query.next()) {
            //nous allons renvoyer les informations dans les champs de saisie
            ui->SAI_IDClient->setText(query.value(0).toString());
            ui->SAINomduClient->setText(query.value(1).toString());
            ui->SAIPrenomduClient->setText(query.value(2).toString());
            ui->SAITelephone->setText(query.value(3).toString());
         }
      }

    //nous allons rendre certains bouttons inactifs
    ui->BTNModifier->setEnabled(true);
    ui->BTNSupprimer->setEnabled(true);
    ui->BTNValider->setEnabled(false);

}


void enregistreclients::on_BTNModifier_clicked()
{
    modifier_client();
}

void enregistreclients::initialisechampclient(){
    //nous affectons aux champs de saisie des valeurs vides
    ui->SAINomduClient->setText("");
    ui->SAIPrenomduClient->setText("");
    ui->SAITelephone->setText("");
    ui->SAINomduClient->setFocus();
}

void enregistreclients::modifier_client(){

    //créer une instance de la classe client en prenant les valeurs saisies par l'utilisateur
    Client client(
                ui->SAINomduClient->text(),
                ui->SAIPrenomduClient->text(),ui->SAITelephone->text()

    );

    // ici nous appellons la fonction qui permet de faire la modification d'un client que nous avons créer dans
    // la classe "query_client"
    if (update_client(client) == true){

        box_message("Le client sélectionné a été modifier avec succès");

        //raffraichir la liste des livres
        tableaffichelisteclient();
    }
}


void enregistreclients::on_BTNSupprimer_clicked()
{
    //instancié la classe client avec les valeurs saisie par le client
    Client client(
                ui->SAINomduClient->text(), ui->SAIPrenomduClient->text(),
                ui->SAITelephone->text()
    );


    //nous allons appeller qui nous permet de supprimer le client
    if (delete_client_by_tel(client.tel) == true){

        box_message("Le client sélectionné a été supprimé avec succès");

        //raffraichir la liste des client
        tableaffichelisteclient();

        //réinitialiser tous les champs en vue d'accueillir un nouvel enregistrement
        initialisechampclient();
    }
}

