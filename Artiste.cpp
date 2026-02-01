#include "Artiste.h"
#include <limits>

// Constructeur par défaut
Artiste::Artiste()
    : identifiant(0), nomScene("Inconnu"), genreMusical("Inconnu"),
      paysOrigine("Inconnu"), cachet(0.0) {}

// Constructeur paramétré
Artiste::Artiste(int id, string nom, string genre, string pays, double c,
                 Date date)
    : identifiant(id), nomScene(nom), genreMusical(genre), paysOrigine(pays),
      cachet(c), dateInscription(date) {}

// Méthode saisir
void Artiste::saisir() {
  cout << "--- Saisie Artiste ---" << endl;
  cout << "Identifiant: ";
  while (!(cin >> identifiant)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Identifiant: ";
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vider le buffer

  cout << "Nom de scène: ";
  getline(cin, nomScene);
  cout << "Genre musical: ";
  getline(cin, genreMusical);
  cout << "Pays d'origine: ";
  getline(cin, paysOrigine);

  cout << "Cachet: ";
  while (!(cin >> cachet)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Cachet: ";
  }
  cout << "Date d'inscription: " << endl;
  dateInscription.saisir();
}

// Méthode afficher
void Artiste::afficher() const {
  cout << "--- Détails Artiste ---" << endl;
  cout << "Identifiant: " << identifiant << endl;
  cout << "Nom de scène: " << nomScene << endl;
  cout << "Genre: " << genreMusical << endl;
  cout << "Pays: " << paysOrigine << endl;
  cout << "Cachet: " << cachet << endl;
  cout << "Date Inscription: ";
  dateInscription.afficher();
  cout << endl;
}

// Getters
int Artiste::getIdentifiant() const { return identifiant; }
string Artiste::getNomScene() const { return nomScene; }
string Artiste::getGenreMusical() const { return genreMusical; }
string Artiste::getPaysOrigine() const { return paysOrigine; }
double Artiste::getCachet() const { return cachet; }
Date Artiste::getDateInscription() const { return dateInscription; }

// Setters
void Artiste::setIdentifiant(int id) { identifiant = id; }
void Artiste::setNomScene(string nom) { nomScene = nom; }
void Artiste::setGenreMusical(string genre) { genreMusical = genre; }
void Artiste::setPaysOrigine(string pays) { paysOrigine = pays; }
void Artiste::setCachet(double c) { cachet = c; }
void Artiste::setDateInscription(const Date &date) { dateInscription = date; }
