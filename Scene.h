#ifndef SCENE_H
#define SCENE_H

#include "Artiste.h"
#include "Date.h"
#include "Technicien.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Scene {
private:
  string code;
  string nom;
  Technicien technicienResponsable;
  int nbMaxArtistes;
  vector<Artiste> artistes;
  Date dateMiseEnService;

public:
  // Constructeurs
  Scene();
  Scene(string c, string n, Technicien t, int nbMax, Date date);

  // Méthodes
  bool artisteExiste(int idArtiste) const;
  bool ajouterArtiste(const Artiste &a);
  void modifierNom(string nouveauNom);
  void afficherArtistesRecents() const;
  int calculerAnciennete() const;
  bool supprimerArtiste(int idArtiste);
  void afficherScene() const;

  // Getters
  string getCode() const;
  string getNom() const;
  Technicien getTechnicienResponsable() const;
  int getNbMaxArtistes() const;
  vector<Artiste> getArtistes() const;
  Date getDateMiseEnService() const;

  // Setters
  void setCode(string c);
  void setNom(string n);
  void setTechnicienResponsable(const Technicien &t);
  void setNbMaxArtistes(int nb);
  void setDateMiseEnService(const Date &date);
};

#endif // SCENE_H
