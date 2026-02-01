#ifndef ARTISTE_H
#define ARTISTE_H

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class Artiste {
private:
  int identifiant;
  string nomScene;
  string genreMusical;
  string paysOrigine;
  double cachet;
  Date dateInscription;

public:
  // Constructeurs
  Artiste();
  Artiste(int id, string nom, string genre, string pays, double c, Date date);

  // Méthodes
  void saisir();
  void afficher() const;

  // Getters
  int getIdentifiant() const;
  string getNomScene() const;
  string getGenreMusical() const;
  string getPaysOrigine() const;
  double getCachet() const;
  Date getDateInscription() const;

  // Setters
  void setIdentifiant(int id);
  void setNomScene(string nom);
  void setGenreMusical(string genre);
  void setPaysOrigine(string pays);
  void setCachet(double c);
  void setDateInscription(const Date &date);
};

#endif // ARTISTE_H
