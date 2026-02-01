#include "Technicien.h"
#include <limits>

// Constructeur par défaut
Technicien::Technicien()
    : identifiant(0), nom("Inconnu"), prenom("Inconnu"), specialite("Inconnu"),
      salaire(0.0) {}

// Constructeur paramétré
Technicien::Technicien(int id, string n, string p, string s, double sal,
                       Date date)
    : identifiant(id), nom(n), prenom(p), specialite(s), salaire(sal),
      dateEmbauche(date) {}

// Méthode saisir
void Technicien::saisir() {
  cout << "--- Saisie Technicien ---" << endl;
  cout << "Identifiant: ";
  while (!(cin >> identifiant)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Identifiant: ";
  }
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n'); // Vider le buffer après l'int

  cout << "Nom: ";
  getline(cin, nom);
  cout << "Prénom: ";
  getline(cin, prenom);
  cout << "Spécialité: ";
  getline(cin, specialite);

  cout << "Salaire: ";
  while (!(cin >> salaire)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Salaire: ";
  }
  cout << "Date d'embauche: " << endl;
  dateEmbauche.saisir();
}

// Méthode afficher
void Technicien::afficher() const {
  cout << "--- Détails Technicien ---" << endl;
  cout << "Identifiant: " << identifiant << endl;
  cout << "Nom Complet: " << prenom << " " << nom << endl;
  cout << "Spécialité: " << specialite << endl;
  cout << "Salaire: " << salaire << endl;
  cout << "Date Embauche: ";
  dateEmbauche.afficher();
  cout << endl;
}

// Getters
int Technicien::getIdentifiant() const { return identifiant; }
string Technicien::getNom() const { return nom; }
string Technicien::getPrenom() const { return prenom; }
string Technicien::getSpecialite() const { return specialite; }
double Technicien::getSalaire() const { return salaire; }
Date Technicien::getDateEmbauche() const { return dateEmbauche; }

// Setters
void Technicien::setIdentifiant(int id) { identifiant = id; }
void Technicien::setNom(string n) { nom = n; }
void Technicien::setPrenom(string p) { prenom = p; }
void Technicien::setSpecialite(string s) { specialite = s; }
void Technicien::setSalaire(double sal) { salaire = sal; }
void Technicien::setDateEmbauche(const Date &date) { dateEmbauche = date; }
