#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //créer une instance de notre pointeur
    ptrenregistrelivre = new enregistrelivres();
    ptrenregistrelivre = new enregistreclients();
}

MainWindow::~MainWindow()
{
    //détruire l'instance après l'avoir utiliser
    delete ptrenregistrelivre;
    delete ui;
}


void MainWindow::on_actionEnregistrer_Livre_changed()
{
}


void MainWindow::on_PBEnregistrelivre_clicked()
{
    //etant donné que notre pointeur pointe sur la fenêtre d'enregistrement des livres,
    //il nous permet de nous afficher notre fenêtre
    ptrenregistrelivre->show();
}


void MainWindow::on_PBEnregistreclient_clicked()
{

    //etant donné que notre pointeur pointe sur la fenêtre d'enregistrement des clients,
    //il nous permet de nous afficher notre fenêtre
    ptrenregistreclient->show();
}

