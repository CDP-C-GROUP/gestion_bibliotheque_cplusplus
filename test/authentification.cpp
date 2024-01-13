#include "mainwindow.h"

#include "authentification.h"
#include "ui_authentification.h"

#include "QMessageBox"

authentification::authentification(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
    //créer une instance de notre pointeur sur la fenêtre main windows
    ptrmainwindows = new MainWindow();

    //initialiser les champs de saisie au démarrage de notre fenêtre
    nouvelleauthentification();


}

authentification::~authentification()
{
    delete ptrmainwindows;
    delete ui;
}

void authentification::on_pushButtonValider_clicked()
{
    //nous appellons la fonction qui nous permet de nous connecter au menu principal de notre application
    validerauthentification();
}

//nous implémentons la fonction qui nous permet d'initialiser les champs nom d'utilisateur et mot de passe
void authentification::nouvelleauthentification(){

    ui->SAI_Motdepasse->setText("");
    ui->SAI_UserName->setText("");
    ui->SAI_UserName->setFocus();
}


void authentification::on_pushButtonAnnuler_clicked()
{
    //nous permet de réinitialiser les champs quand le client décide d'annuler la connexion
    nouvelleauthentification();
}


void authentification::validerauthentification(){

    //si l'utilisateur n'a pas saisie de mot de passe il faudra informer l'utlisateur
    if(ui->SAI_Motdepasse->text() ==""){
        QMessageBox::warning(this,"Authentification","Veuillez renseigner votre mot de passe");
    }
    else
    {
        //si l'utilisateur n'a saisie le nom d'utilisateur il faudra informer l'utlisateur
        if(ui->SAI_UserName->text() ==""){
            QMessageBox::warning(this,"Authentification","Veuillez renseigner votre nom d'utilisateur");
        }
        else
        {
            //ici nous mettons les paramètres de connexion qui nous permet d'accéder au menu principal de notre application
            if(ui->SAI_Motdepasse->text() =="ks" && ui->SAI_UserName->text() =="ks" ){

                QMessageBox::information(this,"Authentification","Authentification réussie");

                //nous pouvons afficher la fenêtre du menu principal de notre application
                //le pointeur sur la fenêtre "mainwindows" déclaré depuis la classe "authentification.h"
                //nous permet d'afficher le menu principal de notre application
                ptrmainwindows->show();

            }
            else
            {
                //lorsque les vrais valeurs de paramètres de connexions ne sont pas envoyer nous allons informer l'utilisateur
                 QMessageBox::warning(this,"Authentification","Nom d'utilisateur ou mot de passe incorrecte");
            }
        }
    }
}
