#ifndef ENREGISTRECLIENTS_H
#define ENREGISTRECLIENTS_H


#include <QWidget>
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui { class enregistreclients; }
QT_END_NAMESPACE

class enregistreclients : public QWidget
{
    Q_OBJECT

public:
    enregistreclients(QWidget *parent = nullptr);
    ~enregistreclients();

private slots:
    void on_BTNValider_clicked();

    void on_BTNNouveau_clicked();

    void on_enregistreclients_windowTitleChanged(const QString &title);

    void tableaffichelisteclient();

private:
    Ui::enregistreclients *ui;
    //nous allons créer le modèle de table de client
    QStandardItemModel *modeleTableClient;
};




#endif // ENREGISTRECLIENTS_H
