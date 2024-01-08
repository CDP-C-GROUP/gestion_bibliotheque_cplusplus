
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

enregistrelivres::enregistrelivres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistrelivres)
{
    ui->setupUi(this);
}

enregistrelivres::~enregistrelivres()
{
    delete ui;
}

// lorsque l'utilisateur va cliquer sur le bouton validé
void enregistrelivres::on_BTNValider_clicked()
{
    //déclaration de ka variable de type string
    QString valeursaisie;

    //nous allons prendre les valeurs saisies par l'utilisateur dans chaque champs de saisie
    valeursaisie = "Vous venez de saisir code du livre: "+ui->SAICodeduLivre->text()+
                   ", nom du livre: "+ui->SAINomduLivre->text()+
                   ", Auteur du livre: "+ui->SAIAuteurduLivre->text()+
                   ", Date de parution: "+ui->SAIdateParition->text();

    //nous allons afficher dans le label "infolivre" les valeurs saisies par l'utilisateur
    ui->infolivre->setText(valeursaisie);

    //nous allons aussi afficher ce que l'utilisateur à saisie dans une boite de dialogue
    QMessageBox info;
    info.setText(valeursaisie+" PAR LA GRACE DE PAPA AU CIEL ON VA Y ARRIVER COURAGE !!!");
    info.setIcon(QMessageBox::Information);
    info.setStandardButtons(QMessageBox::Ok);

    // Affichage de la boîte de dialogue
    info.exec();

}

// lorsque l'utilisateur va cliquer sur le bouton nouveau
void enregistrelivres::on_BTNNouveau_clicked()
{
    //nous déclarons ici une date
    QDate date;

    //nous affectons aux champs de saisie des valeurs vides
    ui->SAICodeduLivre->setText("");
    ui->SAINomduLivre->setText("");
    ui->SAIAuteurduLivre->setText("");

    //nous allons afficher par défaut dans le champs de saisie date : la date courante ou la date de la machine
    ui->SAIdateParition->setDate(date.currentDate());

    //Nous allons donner le focus au code du livre
    ui->SAICodeduLivre->setFocus();
}


void enregistrelivres::on_enregistrelivres_windowTitleChanged(const QString &title)
{
    QMessageBox info;
    info.setText(title);
    info.setIcon(QMessageBox::Information);
    info.setStandardButtons(QMessageBox::Ok);

    // Affichage de la boîte de dialogue
    info.exec();
}

