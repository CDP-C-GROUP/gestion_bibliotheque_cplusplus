#ifndef ENREGISTRELIVRES_H
#define ENREGISTRELIVRES_H

#include <QWidget>
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui { class enregistrelivres; }
QT_END_NAMESPACE

class enregistrelivres : public QWidget
{
    Q_OBJECT

public:
    enregistrelivres(QWidget *parent = nullptr);
    ~enregistrelivres();

private slots:

    void on_BTNValider_clicked();

    void on_BTNNouveau_clicked();

    void on_enregistrelivres_windowTitleChanged(const QString &title);

    //déclaration de la fonction qui permet d'initialiser les champs de saisie
    void initialisechampsaisielivre();

    //déclaration de la fonction qui permet d'enregistrer un livre
    void ajouterlivre();

    //déclaration de la fonction qui permet d'afficher la liste des livres
    void tableaffichelistelivre();

    //déclaration de la fonction qui affiche les valeurs de la ligne d'une table
    void afficher_une_ligne_de_la_table_livre(const QModelIndex &index);

    void on_tableViewLivre_doubleClicked(const QModelIndex &index);

    void on_tableViewLivre_clicked(const QModelIndex &index);

    void on_BTNModifier_clicked();

    void on_BTNSupprimer_clicked();

private:
    Ui::enregistrelivres *ui;
    //nous allons créer le modèle de table de livre
    QStandardItemModel *modeleTableLivre;
};
#endif // ENREGISTRELIVRES_H
