#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class authentification;
}

class authentification : public QWidget
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::authentification *ui;
    void nouvelleauthentification();
    void validerauthentification();

    //créer un pointeur sur la tête (.h) de notre menu principal
    MainWindow *ptrmainwindows;
};

#endif // AUTHENTIFICATION_H
