#include "authentification.h"

#include <QApplication>
#include "connexion_sqlite3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Appel du fichier de la connexion au DB pour seconnecter à notre base de données dès le lancement de notre application
    connexion_db();

    //nous déclarons une variable de type authentification que nous affichons directement
    authentification auth;

    auth.show();
    return a.exec();
}
