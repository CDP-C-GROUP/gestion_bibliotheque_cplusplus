#include "mainwindow.h"
#include "enregistrelivres.h"

#include <QApplication>
#include "connexion_sqlite3.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    is_connexion_db(); //Appel du fichier de la connexion au DB
    MainWindow w;
    w.show();
    return a.exec();
}
