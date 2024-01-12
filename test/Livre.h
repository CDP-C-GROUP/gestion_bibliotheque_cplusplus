#ifndef CLASS_LIVRE_H
#define CLASS_LIVRE_H

#include <QString>

class Livre {
public:
    int id;
    QString code;
    QString nom;
    QString auteur;
    QString date_parution;
    QString quantite; //int

    // Add other properties as needed

    Livre(
         const QString& c, const QString& n, const QString& a,
         const QString& d, const QString& q
    ) : code(c), nom(n), auteur(a), date_parution(d), quantite(q) {}

    int get_quantite(){
        return quantite.toInt();
    }
};

#endif // CLASS_LIVRE_H
