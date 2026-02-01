#include "FestivalManager.h"

// Vérifier si une scène existe
bool FestivalManager::sceneExiste(string code) const {
  for (const auto &scene : scenes) {
    if (scene.getCode() == code) {
      return true;
    }
  }
  return false;
}

// Ajouter une scène
void FestivalManager::ajouterScene(const Scene &s) {
  if (sceneExiste(s.getCode())) {
    cout << "Erreur: Une scène avec le code " << s.getCode() << " existe déjà."
         << endl;
    return;
  }
  scenes.push_back(s);
  cout << "Scène ajoutée avec succès." << endl;
}

// Modifier une scène
void FestivalManager::modifierScene(string code) {
  for (auto &scene : scenes) {
    if (scene.getCode() == code) {
      cout << "Modification de la scène " << code << endl;

      // Modifier Nom
      string nouveauNom;
      cout << "Nouveau nom (laisser vide pour ne pas changer): ";
      cin.ignore();
      getline(cin, nouveauNom);
      if (!nouveauNom.empty())
        scene.setNom(nouveauNom);

      // Modifier Technicien
      char rep;
      cout << "Modifier le technicien responsable? (o/n): ";
      cin >> rep;
      if (rep == 'o' || rep == 'O') {
        Technicien t;
        t.saisir();
        scene.setTechnicienResponsable(t);
      }

      // Modifier Capacité
      cout << "Modifier capacité max? (o/n): ";
      cin >> rep;
      if (rep == 'o' || rep == 'O') {
        int cap;
        cout << "Nouvelle capacité: ";
        cin >> cap;
        scene.setNbMaxArtistes(cap);
      }

      cout << "Scène modifiée." << endl;
      return;
    }
  }
  cout << "Erreur: Scène non trouvée." << endl;
}

// Supprimer une scène
void FestivalManager::supprimerScene(string code) {
  for (size_t i = 0; i < scenes.size(); ++i) {
    if (scenes[i].getCode() == code) {
      scenes.erase(scenes.begin() + i);
      cout << "Scène supprimée avec succès." << endl;
      return;
    }
  }
  cout << "Erreur: Scène non trouvée." << endl;
}

// Afficher toutes les scènes
void FestivalManager::afficherToutesLesScenes() const {
  if (scenes.empty()) {
    cout << "Aucune scène enregistrée." << endl;
    return;
  }
  for (const auto &scene : scenes) {
    scene.afficherScene();
    // L'ancienneté est affichée dans afficherScene()
  }
}

// Scènes de plus de 5 ans
vector<Scene> FestivalManager::scenesPlusDe5Ans() const {
  vector<Scene> result;
  for (const auto &scene : scenes) {
    if (scene.calculerAnciennete() > 5) {
      result.push_back(scene);
    }
  }
  return result;
}

// Scènes par technicien
void FestivalManager::scenesParTechnicien(int idTechnicien) const {
  cout << "--- Scènes gérées par le technicien ID " << idTechnicien << " ---"
       << endl;
  bool found = false;
  for (const auto &scene : scenes) {
    if (scene.getTechnicienResponsable().getIdentifiant() == idTechnicien) {
      scene.afficherScene();
      found = true;
    }
  }
  if (!found)
    cout << "Aucune scène trouvée pour ce technicien." << endl;
}

// Helper pour récupérer un pointeur vers une scène
Scene *FestivalManager::getScenePtr(string code) {
  for (auto &scene : scenes) {
    if (scene.getCode() == code) {
      return &scene;
    }
  }
  return nullptr;
}
