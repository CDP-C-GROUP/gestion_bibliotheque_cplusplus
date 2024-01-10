#include <QString>

class client {
public:
    QString nom;
    QString prenom;
    QString tel;

    // Add other properties as needed

    client(
        const QString& n, const QString& p, const QString& t

        ) :  nom(n), prenom(p), tel(t) {}
};
