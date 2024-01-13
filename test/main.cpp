#include "authentification.h"

#include <QApplication>
#include "connexion_sqlite3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion_db(); //Appel du fichier de la connexion au DB
    authentification auth;
    auth.show();
    return a.exec();
}
