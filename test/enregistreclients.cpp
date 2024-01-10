
//nous allons importer l'entête de notre fenêtre d'enregsitrement des clients
#include "enregistreclients.h"

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


    //nous allons afficher dans le label "infoclient" les valeurs saisies par l'utilisateur
    ui->infoclient->setText(valeursaisie);

    //Appel de la fonction Box personnalisée en passant le message
    box_message(valeursaisie+"\n\nPAR LA GRACE DE PAPA AU CIEL ON VA Y ARRIVER COURAGE !!!");

}

// lorsque l'utilisateur va cliquer sur le bouton nouveau
void enregistreclients::on_BTNNouveau_clicked()
{

    //nous affectons aux champs de saisie des valeurs vides
    ui->SAINomduClient->setText("");
    ui->SAIPrenomduClient->setText("");
    ui->SAITelephone->setText("");


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


