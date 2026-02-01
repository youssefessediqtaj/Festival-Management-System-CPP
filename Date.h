#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int jour;
    int mois;
    int annee;

public:
    // Constructeurs
    Date();
    Date(int j, int m, int a);

    // Méthodes
    void saisir();
    void afficher() const;

    // Getters
    int getJour() const;
    int getMois() const;
    int getAnnee() const;

    // Setters
    void setJour(int j);
    void setMois(int m);
    void setAnnee(int a);

    // Utilitaires
    int differenceAnnees(const Date& autreDate) const;
};

#endif // DATE_H
