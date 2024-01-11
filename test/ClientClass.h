#include <QString>

class Client {
public:
    int id;
    QString nom;
    QString prenom;
    QString tel;

    // Add other properties as needed

    Client(
         const QString& n, const QString& p, const QString& t
    ) : nom(n), prenom(p), tel(t) {}
};
