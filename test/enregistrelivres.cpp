
//nous allons importer l'entête de notre fenêtre d'enregsitrement des livres
#include "enregistrelivres.h"

//nous appellons ici la fenêtre d'enregistrement des livres pour pouvoir avoir accès aux champs de saisie
#include "ui_enregistrelivres.h"

//nous faisons appelle ici à la librairie qui nous permet d'utiliser la date
#include "datetimeapi.h"

//nous appellons la bibliothèque pour utiliser une boite de dialogue
#include "QMessageBox"

//nous appellons la bibliothèque pour utiliser les string
#include "QString"
#include <iostream>
#include <string>
#include "query_livre.h"

enregistrelivres::enregistrelivres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistrelivres)
{
    ui->setupUi(this);
    //nous voulons qu'à l'ouverture de l'interface l'action là s'exécute
    enregistrelivres::on_BTNNouveau_clicked();
    //nous allons afficher la liste des livres
    enregistrelivres::tableaffichelistelivre();
}

enregistrelivres::~enregistrelivres()
{
    delete ui;
}

// lorsque l'utilisateur va cliquer sur le bouton validé
void enregistrelivres::on_BTNValider_clicked()
{

    //Ajouter un livre saisie par l'utilisateur
    ajouterlivre();

    //afficher la liste des livres dans la table
    tableaffichelistelivre();

    //déclaration de la variable de type string
    QString valeursaisie;

    //nous allons prendre les valeurs saisies par l'utilisateur dans chaque champs de saisie
    valeursaisie = "Voici vos informations saisies: "
                       "\ncode du livre: "+ui->SAICodeduLivre->text()+
                       "\nnom du livre: "+ui->SAINomduLivre->text()+
                       "\nAuteur du livre: "+ui->SAIAuteurduLivre->text()+
                        "\nQuantité du livre: "+ui->SAIQuantiteLivre->text()+
                       "\nDate de parution: "+ui->SAIdateParition->text()+
                        "\nNombre de livre enregistré : "+QString::number(nombreligne_livre_enreg());

    //nous allons afficher dans le label "infolivre" les valeurs saisies par l'utilisateur
    ui->infolivre->setText(valeursaisie);

}

// lorsque l'utilisateur va cliquer sur le bouton nouveau
void enregistrelivres::on_BTNNouveau_clicked()
{
    initialisechampsaisielivre();
}


void enregistrelivres::on_enregistrelivres_windowTitleChanged(const QString &title)
{
    QMessageBox::information(this,title,"","");

}

//implémentation de la procédure qui permet d'initialiser les champs de saisie
void enregistrelivres::initialisechampsaisielivre(){

    //nous allons rendre certains bouttons inactifs
    ui->BTNModifier->setEnabled(false);
    ui->BTNSupprimer->setEnabled(false);
    ui->BTNValider->setEnabled(true);

    //nous déclarons ici une date
    QDate date;

    //nous affectons aux champs de saisie des valeurs vides
    ui->SAICodeduLivre->setText("");
    ui->SAINomduLivre->setText("");
    ui->SAIAuteurduLivre->setText("");
    ui->SAIQuantiteLivre->setValue(0);

    //nous allons afficher par défaut dans le champs de saisie date : la date courante ou la date de la machine
    ui->SAIdateParition->setDate(date.currentDate());

    //Nous allons donner le focus au code du livre
    ui->SAICodeduLivre->setFocus();

}

//implémentation de la fonction qui permet d'ajouter un livre
void enregistrelivres::ajouterlivre(){

    if(ui->SAIQuantiteLivre->value() < 1){
        QMessageBox::warning(this,"Erreur de saisie de la quantité du livre","La quantité minimum du livre doit être supérieure à 0");
        ui->SAIQuantiteLivre->setFocus();
    }
    else{
        if(ui->SAICodeduLivre->text() == ""){
            QMessageBox::warning(this,"Erreur de saisie du code livre","Veuillez renseigner le code du livre");
            ui->SAICodeduLivre->setFocus();
        }
        else{
            if(ui->SAINomduLivre->text() == ""){
                QMessageBox::warning(this,"Erreur de saisie du nom du livre","Veuillez renseigner le nom du livre");
                ui->SAINomduLivre->setFocus();
            }
            else{
                if(ui->SAIAuteurduLivre->text() ==""){
                    QMessageBox::warning(this,"Erreur de saisie de l'Auteur","Veuillez renseigner l'auteur du livre");
                    ui->SAIAuteurduLivre->setFocus();
                }
                else{
                    Livre livre = Livre(
                                ui->SAICodeduLivre->text(), ui->SAINomduLivre->text(),
                                ui->SAIAuteurduLivre->text(), ui->SAIdateParition->text(),
                                ui->SAIQuantiteLivre->text()
                    );
                    save_livre((livre)); //Enregistrer le livre dans la base de données
                    box_message("Livre enregistré avec succès");

                    //remettre les champs de saisie à vide
                    //nous appellons la procédure qui nous permet de mettre les champs de saisie à vide
                    initialisechampsaisielivre();
                 }
             }

         }
     }
}


//implémentation de la procédure qui permet d'afficher la liste des livres dans une table
void enregistrelivres::tableaffichelistelivre(){

    //nous initialisons le nombre de ligne à 0
    int row(0);

    QList<Livre> livres = get_all_livres();

    //nous allons initialiser le modèle de table de livre que nous avons déclarer dans le .h
    //notre modèle de table doit avoir exactement le total des attributs de la table livre comme nbre de colonnes
    //le totale des enregistrements comme nombre de lignes
    modeleTableLivre = new QStandardItemModel(livres.length(),5);

    //nous allons ouvrir la connexion à la base de données
    /*if (is_connexion_db()) {

        //nous allons sélectionner tous les livres enregistrer
        QSqlQuery query("SELECT code, nom, auteur, date_parution, quantite FROM livre ORDER BY (id) DESC");

        //tanque nous pouvons lire les lignes de la requête
        while (query.next()) {

            //nous allons parcourir les colonnes et renvoyer la valeur à l'intersection de la ligne et de la colonne
            //la ligne représente le row et la colonne représente i
            for(int i=0;i<5;i++){
                   QStandardItem *item = new QStandardItem(query.value(i).toString());
                   modeleTableLivre->setItem(row,i,item);
            }
            row++;
         }
      }*/

    for (Livre livre : livres) {
        modeleTableLivre->setItem(row,0, new QStandardItem(livre.code));
        modeleTableLivre->setItem(row,1, new QStandardItem(livre.nom));
        modeleTableLivre->setItem(row,2, new QStandardItem(livre.auteur));
        modeleTableLivre->setItem(row,3, new QStandardItem(livre.date_parution));
        modeleTableLivre->setItem(row,4, new QStandardItem(livre.quantite));
        row++;
    }

    //nous allons donc ajouter à notre modèle, les libelles des colonnes de notre table livre
    modeleTableLivre->setHeaderData(0,Qt::Horizontal,"Code Livre");
    modeleTableLivre->setHeaderData(1,Qt::Horizontal,"Nom du livre");
    modeleTableLivre->setHeaderData(2,Qt::Horizontal,"Auteur");
    modeleTableLivre->setHeaderData(3,Qt::Horizontal,"Date parution");
    modeleTableLivre->setHeaderData(4,Qt::Horizontal,"Qté");

     //affecter notre modèle à la tableview
     ui->tableViewLivre->setModel(modeleTableLivre);

}

//implémentons la fonction qui nous permet d'affecter la ligne d'un livre sélectionné

void enregistrelivres::afficher_une_ligne_de_la_table_livre(const QModelIndex &index){
    //nous allons déclarer une variable qui prend la valeur de la cellule sélectionnée
    QString val;
    val = ui->tableViewLivre->model()->data(index).toString();

    //nous allons donc rechercher la valeur sélectionnée par l'utilisateur dans la table livre et renvoyer ces informtions
    //nous allons ouvrir la connexion à la base de données
    if (is_connexion_db()) {

        //nous allons sélectionner tous les livres enregistrer
        QSqlQuery query("SELECT * FROM livre WHERE code = '"+val+"' or nom = '"+val+"' or auteur = '"+val+"' or date_parution = '"+val+"' or quantite = '"+val+"' ");

        //tanque nous pouvons lire les lignes de la requête
        while (query.next()) {
            //nous allons renvoyer les informations dans les champs de saisie
            ui->SAICodeduLivre->setText(query.value(1).toString());
            ui->SAINomduLivre->setText(query.value(2).toString());
            ui->SAIAuteurduLivre->setText(query.value(3).toString());
            ui->SAIdateParition->setDate(query.value(4).toDate());
            ui->SAIQuantiteLivre->setValue(query.value(5).toInt());
         }
      }

    //nous allons rendre certains bouttons inactifs
    ui->BTNModifier->setEnabled(true);
    ui->BTNSupprimer->setEnabled(true);
    ui->BTNValider->setEnabled(false);
}

void enregistrelivres::on_tableViewLivre_doubleClicked(const QModelIndex &index)
{
    afficher_une_ligne_de_la_table_livre(index);
}


void enregistrelivres::on_tableViewLivre_clicked(const QModelIndex &index)
{
    afficher_une_ligne_de_la_table_livre(index);
}


void enregistrelivres::on_BTNModifier_clicked()
{

    //nous allons donc rechercher la valeur sélectionnée par l'utilisateur dans la table livre et renvoyer ces informtions
    //nous allons ouvrir la connexion à la base de données
    if (is_connexion_db()) {

        //nous allons sélectionner tous les livres enregistrer
        QSqlQuery query("UPDATE livre SET nom = '"+ui->SAINomduLivre->text()+"', auteur = '"+ui->SAIAuteurduLivre->text()+"', date_parution = '"+ui->SAIdateParition->date().DateFormat+"', quantite = '"+ui->SAIQuantiteLivre->value()+"' WHERE code = '"+ui->SAICodeduLivre->text()+"'  ");

        //nous allons exécuter la requête
        query.executedQuery();

        box_message("Livre modifié avec succès");

        //nous allons raffraîchir la liste des livres après modification
        tableaffichelistelivre();

        //nous allons réinitialiser les champs
        initialisechampsaisielivre();

      }
}

