#ifndef ENREGISTREEMPRUNTS_H
#define ENREGISTREEMPRUNTS_H


#include <QWidget>
#include "QStandardItemModel"



QT_BEGIN_NAMESPACE
namespace Ui { class enregistreEmprunts; }
QT_END_NAMESPACE

class enregistreEmprunts : public QWidget
{
    Q_OBJECT

public:
    enregistreEmprunts(QWidget *parent = nullptr);
    ~enregistreEmprunts();

private slots:
    void on_BTNValider_clicked();

    void on_BTNNouveau_clicked();

    void on_enregistreEmprunts_windowTitleChanged(const QString &title);

    void tableaffichelisteEmprunt();


private:
    Ui::enregistreEmprunts *ui;
    //nous allons créer le modèle de table de emprunt
    QStandardItemModel *modeleTableEmprunt;

};




#endif // ENREGISTREEMPRUNTS_H
