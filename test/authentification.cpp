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

    //initialiser les champs de saisie
    nouvelleauthentification();


}

authentification::~authentification()
{
    delete ptrmainwindows;
    delete ui;
}

void authentification::on_pushButtonValider_clicked()
{
    validerauthentification();
}

void authentification::nouvelleauthentification(){
    ui->SAI_Motdepasse->setText("");
    ui->SAI_UserName->setText("");
}


void authentification::on_pushButtonAnnuler_clicked()
{
    nouvelleauthentification();
}


void authentification::validerauthentification(){


    if(ui->SAI_Motdepasse->text() ==""){
        QMessageBox::warning(this,"Authentification","Veuillez renseigner votre mot de passe");
    }
    else
    {
        if(ui->SAI_UserName->text() ==""){
            QMessageBox::warning(this,"Authentification","Veuillez renseigner votre nom d'utilisateur");
        }
        else
        {
            if(ui->SAI_Motdepasse->text() =="ks" && ui->SAI_UserName->text() =="ks" ){

                QMessageBox::information(this,"Authentification","Authentification réussie");
                //nous pouvons afficher la fenêtre du menu principal de notre application
                ptrmainwindows->show();

            }
            else
            {
                 QMessageBox::warning(this,"Authentification","Nom d'utilisateur ou mot de passe incorrecte");
            }
        }
    }
}
