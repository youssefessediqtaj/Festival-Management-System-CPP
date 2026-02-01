#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class Technicien {
private:
  int identifiant;
  string nom;
  string prenom;
  string specialite;
  double salaire;
  Date dateEmbauche;

public:
  // Constructeurs
  Technicien();
  Technicien(int id, string n, string p, string s, double sal, Date date);

  // Méthodes
  void saisir();
  void afficher() const;

  // Getters
  int getIdentifiant() const;
  string getNom() const;
  string getPrenom() const;
  string getSpecialite() const;
  double getSalaire() const;
  Date getDateEmbauche() const;

  // Setters
  void setIdentifiant(int id);
  void setNom(string n);
  void setPrenom(string p);
  void setSpecialite(string s);
  void setSalaire(double sal);
  void setDateEmbauche(const Date &date);
};

#endif // TECHNICIEN_H
