#include "Date.h"
#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

// Constructeur par défaut
Date::Date() : jour(1), mois(1), annee(2000) {}

// Constructeur paramétré
Date::Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

// Méthode saisir
void Date::saisir() {
  cout << "Entrer le jour: ";
  while (!(cin >> jour)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Jour: ";
  }
  cout << "Entrer le mois: ";
  while (!(cin >> mois)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Mois: ";
  }
  cout << "Entrer l'année: ";
  while (!(cin >> annee)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Entrée invalide. Année: ";
  }
}

// Méthode afficher
void Date::afficher() const {
  cout << (jour < 10 ? "0" : "") << jour << "/" << (mois < 10 ? "0" : "")
       << mois << "/" << annee;
}

// Getters
int Date::getJour() const { return jour; }
int Date::getMois() const { return mois; }
int Date::getAnnee() const { return annee; }

// Setters
void Date::setJour(int j) { jour = j; }
void Date::setMois(int m) { mois = m; }
void Date::setAnnee(int a) { annee = a; }

// Différence en années (approximation simple pour l'exercice)
int Date::differenceAnnees(const Date &autreDate) const {
  return abs(annee - autreDate.getAnnee());
}
