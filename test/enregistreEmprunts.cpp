
//nous allons importer l'entête de notre fenêtre d'enregsitrement des emprunts
#include "enregistreEmprunts.h"
#include "ui_enregistreEmprunts.h"
//nous appellons ici la fenêtre d'enregistrement des emprunts pour pouvoir avoir accès aux champs de saisie


//nous appellons la bibliothèque pour utiliser une boite de dialogue
#include "QMessageBox"

//nous appellons la bibliothèque pour utiliser les string
#include "QString"


#include "query_emprunt.h"



enregistreEmprunts::enregistreEmprunts(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistreEmprunts)
{
    ui->setupUi(this);
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


        //nous allons prendre les valeurs saisies par l'utilisateur dans chaque champs de saisie
        valeursaisie = "Voici vos informations saisies: "

                       /*"\nnom du client: "+ui->SAINomduClient->text()+
                       "\nPrenom du client: "+ui->SAIPrenomduClient->text()+
                       "\nTelephone du client: "+ui->SAITelephone->text()*/
                ;

        Emprunt emprunt = Emprunt(
                    Livre("", "", "", "", "0"),
                    Client("", "", ""),
                    "",
                    ""
            );
        save_emprunt((emprunt)); //Enregistrer le emprunt dans la base de données

        //afficher la liste des livres dans la table
        tableaffichelisteEmprunt();


    //nous allons afficher dans le label "infoclient" les valeurs saisies par l'utilisateur
    ui->infoemprunt->setText(valeursaisie);

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
    modeleTableEmprunt = new QStandardItemModel(emprunts.length(),3);

    for (Emprunt emprunt : emprunts) {
        modeleTableEmprunt->setItem(row,0, new QStandardItem(emprunt.livre.nom));
        modeleTableEmprunt->setItem(row,1, new QStandardItem(emprunt.client.nom));
        modeleTableEmprunt->setItem(row,2, new QStandardItem(emprunt.date_emprunt));
        modeleTableEmprunt->setItem(row,3, new QStandardItem(emprunt.date_retour));
        row++;
    }

    //nous allons donc ajouter à notre modèle, les libelles des colonnes de notre table emprunt
    modeleTableEmprunt->setHeaderData(0,Qt::Horizontal,"Livre");
    modeleTableEmprunt->setHeaderData(1,Qt::Horizontal,"Client");
    modeleTableEmprunt->setHeaderData(2,Qt::Horizontal,"Date Emprunt");
    modeleTableEmprunt->setHeaderData(2,Qt::Horizontal,"Date Retour");

     //affecter notre modèle à la tableview
     ui->tableViewEmprunt->setModel(modeleTableEmprunt);

}
