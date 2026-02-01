#include "Artiste.h"
#include "Date.h"
#include "FestivalManager.h"
#include "Scene.h"
#include "Technicien.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

void afficherMenuPrincipal() {
  cout << "\n=== BOUM BOUM FESTIVAL ===" << endl;
  cout << "1. Gestion des Scènes" << endl;
  cout << "2. Gestion des Artistes (via Scène)" << endl;
  cout << "3. Affichage & Statistiques" << endl;
  cout << "0. Quitter" << endl;
  cout << "Choix: ";
}

void afficherMenuScenes() {
  cout << "\n--- Gestion des Scènes ---" << endl;
  cout << "1. Ajouter une scène" << endl;
  cout << "2. Modifier une scène" << endl;
  cout << "3. Supprimer une scène" << endl;
  cout << "0. Retour" << endl;
  cout << "Choix: ";
}

void afficherMenuArtistes() {
  cout << "\n--- Gestion des Artistes ---" << endl;
  cout << "1. Ajouter un artiste à une scène" << endl;
  cout << "2. Supprimer un artiste d'une scène" << endl;
  cout << "0. Retour" << endl;
  cout << "Choix: ";
}

void afficherMenuStats() {
  cout << "\n--- Affichage & Statistiques ---" << endl;
  cout << "1. Afficher toutes les scènes" << endl;
  cout << "2. Afficher les scènes > 5 ans" << endl;
  cout << "3. Afficher les scènes par technicien" << endl;
  cout << "4. Afficher les artistes récents d'une scène" << endl;
  cout << "0. Retour" << endl;
  cout << "Choix: ";
}

int main() {
  FestivalManager manager;
  int choixPrincipal = 0;

  do {
    afficherMenuPrincipal();
    while (!(cin >> choixPrincipal)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Entrée invalide. Choix: ";
    }

    switch (choixPrincipal) {
    case 1: { // Gestion des Scènes
      int choixScene = 0;
      do {
        afficherMenuScenes();
        while (!(cin >> choixScene)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Entrée invalide. Choix: ";
        }

        if (choixScene == 1) {
          string code, nom;
          int maxArtistes;
          Technicien tech;
          Date dateCreation;

          cout << "Code: ";
          cin >> code;
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Robust ignore

          cout << "Nom de la scène: ";
          getline(cin, nom);

          cout << "Capacité max artistes: ";
          while (!(cin >> maxArtistes)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. Capacité: ";
          }

          cout << "Technicien Responsable:" << endl;
          tech.saisir();
          cout << "Date de mise en service:" << endl;
          dateCreation.saisir();

          Scene s(code, nom, tech, maxArtistes, dateCreation);
          manager.ajouterScene(s);

        } else if (choixScene == 2) {
          string code;
          cout << "Code de la scène à modifier: ";
          cin >> code;
          manager.modifierScene(code);

        } else if (choixScene == 3) {
          string code;
          cout << "Code de la scène à supprimer: ";
          cin >> code;
          manager.supprimerScene(code);
        }
      } while (choixScene != 0);
      break;
    }
    case 2: { // Gestion des Artistes
      int choixArtiste = 0;
      do {
        afficherMenuArtistes();
        while (!(cin >> choixArtiste)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Entrée invalide. Choix: ";
        }

        if (choixArtiste == 1) {
          string code;
          cout << "Code de la scène: ";
          cin >> code;
          Scene *scene = manager.getScenePtr(code);
          if (scene) {
            Artiste art;
            art.saisir();
            scene->ajouterArtiste(art);
          } else {
            cout << "Scène introuvable." << endl;
          }

        } else if (choixArtiste == 2) {
          string code;
          int idArt;
          cout << "Code de la scène: ";
          cin >> code;
          Scene *scene = manager.getScenePtr(code);
          if (scene) {
            cout << "ID de l'artiste à supprimer: ";
            while (!(cin >> idArt)) {
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout << "Entrée invalide. ID: ";
            }
            scene->supprimerArtiste(idArt);
          } else {
            cout << "Scène introuvable." << endl;
          }
        }
      } while (choixArtiste != 0);
      break;
    }
    case 3: { // Stats
      int choixStat = 0;
      do {
        afficherMenuStats();
        while (!(cin >> choixStat)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Entrée invalide. Choix: ";
        }

        if (choixStat == 1) {
          manager.afficherToutesLesScenes();
        } else if (choixStat == 2) {
          vector<Scene> vieillesScenes = manager.scenesPlusDe5Ans();
          if (vieillesScenes.empty())
            cout << "Aucune scène > 5 ans." << endl;
          else {
            cout << "--- Scènes > 5 ans ---" << endl;
            for (const auto &s : vieillesScenes)
              s.afficherScene();
          }
        } else if (choixStat == 3) {
          int idTech;
          cout << "ID du technicien: ";
          while (!(cin >> idTech)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide. ID: ";
          }
          manager.scenesParTechnicien(idTech);
        } else if (choixStat == 4) {
          string code;
          cout << "Code de la scène: ";
          cin >> code;
          Scene *s = manager.getScenePtr(code);
          if (s)
            s->afficherArtistesRecents();
          else
            cout << "Scène introuvable." << endl;
        }
      } while (choixStat != 0);
      break;
    }
    case 0:
      cout << "Au revoir!" << endl;
      break;
    default:
      cout << "Choix invalide." << endl;
    }

  } while (choixPrincipal != 0);

  return 0;
}
