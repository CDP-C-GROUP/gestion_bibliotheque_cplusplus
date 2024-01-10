#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "enregistrelivres.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionEnregistrer_Livre_changed();

    void on_PBEnregistrelivre_clicked();

    void on_PBEnregistreclient_clicked();

private:
    Ui::MainWindow *ui;
    //créer un pointeur sur la tête (.h) de notre fenêtre d'enregistrement des livres
    enregistrelivres *ptrenregistrelivre;

};
#endif // MAINWINDOW_H
