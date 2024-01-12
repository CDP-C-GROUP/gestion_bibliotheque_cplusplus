#ifndef CLASS_E
#define CLASS_E

#include <QString>
#include "ClientClass.h"
#include "Livre.h"

class Emprunt {
public:
    int id;
    Livre livre;
    Client client;
    QString date_emprunt;
    QString date_retour;

    // Add other properties as needed

    Emprunt(
         const Livre& l, const Client& c, const QString& de, const QString& dr
    ) : livre(l), client(c), date_emprunt(de), date_retour(dr) {}
};

#endif //CLASS_E
