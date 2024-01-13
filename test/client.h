#ifndef CLASS_C
#define CLASS_C

#include <QString>

class client {
public:
    //déclaration des attributs de notre classe  conforme aux attributs de notre base de données
    QString nom;
    QString prenom;
    QString tel;

    // Add other properties as needed

    client(
        const QString& n, const QString& p, const QString& t

        ) : nom(n), prenom(p), tel(t) {}
};

#endif //CLASS_C
