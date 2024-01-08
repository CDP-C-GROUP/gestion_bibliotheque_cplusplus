#include <QMessageBox>
#include "QString"

static void box_message(QString txt){
    /*
     * Fonction permet d'afficher en écran un message passé en paramètre
    */
    QMessageBox info;
    info.setText(txt);
    info.setIcon(QMessageBox::Information);
    info.setStandardButtons(QMessageBox::Ok);

    // Affichage de la boîte de dialogue
    info.exec();

}
