#include <QString>

class Livre {
public:
    QString code;
    QString nom;
    QString auteur;
    QString date_parution;
    int quantite;

    // Add other properties as needed

    Livre(
         const QString& c, const QString& n, const QString& a,
         const QString& d, const int& q
    ) : code(c), nom(n), auteur(a), date_parution(d), quantite(q) {}
};
