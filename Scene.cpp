#include "Scene.h"
#include <ctime>

// Constructeur par défaut
Scene::Scene()
    : code("UNK"), nom("Inconnu"), nbMaxArtistes(0), dateMiseEnService(Date()) {
}

// Constructeur paramétré
Scene::Scene(string c, string n, Technicien t, int nbMax, Date date)
    : code(c), nom(n), technicienResponsable(t), nbMaxArtistes(nbMax),
      dateMiseEnService(date) {}

// Vérifier si un artiste existe par ID
bool Scene::artisteExiste(int idArtiste) const {
  for (const auto &artiste : artistes) {
    if (artiste.getIdentifiant() == idArtiste) {
      return true;
    }
  }
  return false;
}

// Ajouter un artiste
bool Scene::ajouterArtiste(const Artiste &a) {
  if (artistes.size() >= nbMaxArtistes) {
    cout << "Erreur: Capacité maximale atteinte (" << nbMaxArtistes << ")."
         << endl;
    return false;
  }
  if (artisteExiste(a.getIdentifiant())) {
    cout << "Erreur: Artiste avec ID " << a.getIdentifiant()
         << " existe déjà sur cette scène." << endl;
    return false;
  }
  artistes.push_back(a);
  cout << "Artiste " << a.getNomScene() << " ajouté avec succès." << endl;
  return true;
}

// Modifier le nom de la scène
void Scene::modifierNom(string nouveauNom) { nom = nouveauNom; }

// Afficher les artistes inscrits depuis moins de 1 an
void Scene::afficherArtistesRecents() const {
  // Obtenir la date actuelle (approximative pour l'exemple)
  time_t t = time(0);
  tm *now = localtime(&t);
  Date dateActuelle(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);

  cout << "--- Artistes récents (moins de 1 an) ---" << endl;
  bool found = false;
  for (const auto &artiste : artistes) {
    if (dateActuelle.differenceAnnees(artiste.getDateInscription()) < 1) {
      artiste.afficher();
      found = true;
    }
  }
  if (!found)
    cout << "Aucun artiste récent." << endl;
}

// Calculer l'ancienneté de la scène
int Scene::calculerAnciennete() const {
  time_t t = time(0);
  tm *now = localtime(&t);
  Date dateActuelle(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
  return dateActuelle.differenceAnnees(dateMiseEnService);
}

// Supprimer un artiste
bool Scene::supprimerArtiste(int idArtiste) {
  for (size_t i = 0; i < artistes.size(); ++i) {
    if (artistes[i].getIdentifiant() == idArtiste) {
      artistes.erase(artistes.begin() + i);
      cout << "Artiste supprimé avec succès." << endl;
      return true;
    }
  }
  cout << "Erreur: Artiste non trouvé." << endl;
  return false;
}

// Afficher la scène
void Scene::afficherScene() const {
  cout << "========================================" << endl;
  cout << "Code: " << code << " | Nom: " << nom << endl;
  cout << "Mise en service: ";
  dateMiseEnService.afficher();
  cout << endl;
  cout << "Ancienneté: " << calculerAnciennete() << " ans" << endl;
  cout << "Capacité: " << artistes.size() << "/" << nbMaxArtistes << endl;
  cout << "Responsable: " << technicienResponsable.getPrenom() << " "
       << technicienResponsable.getNom() << endl;

  cout << "--- Liste des Artistes ---" << endl;
  if (artistes.empty()) {
    cout << "Aucun artiste." << endl;
  } else {
    for (const auto &artiste : artistes) {
      artiste.afficher();
    }
  }
  cout << "========================================" << endl;
}

// Getters
string Scene::getCode() const { return code; }
string Scene::getNom() const { return nom; }
Technicien Scene::getTechnicienResponsable() const {
  return technicienResponsable;
}
int Scene::getNbMaxArtistes() const { return nbMaxArtistes; }
vector<Artiste> Scene::getArtistes() const { return artistes; }
Date Scene::getDateMiseEnService() const { return dateMiseEnService; }

// Setters
void Scene::setCode(string c) { code = c; }
void Scene::setNom(string n) { nom = n; }
void Scene::setTechnicienResponsable(const Technicien &t) {
  technicienResponsable = t;
}
void Scene::setNbMaxArtistes(int nb) { nbMaxArtistes = nb; }
void Scene::setDateMiseEnService(const Date &date) { dateMiseEnService = date; }
