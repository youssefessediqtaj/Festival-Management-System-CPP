#ifndef FESTIVALMANAGER_H
#define FESTIVALMANAGER_H

#include "Scene.h"
#include <vector>

class FestivalManager {
private:
  vector<Scene> scenes;

public:
  // Méthodes requises
  bool sceneExiste(string code) const;
  void ajouterScene(const Scene &s);
  void modifierScene(string code);
  void supprimerScene(string code);
  void afficherToutesLesScenes() const;
  vector<Scene> scenesPlusDe5Ans() const;
  void scenesParTechnicien(int idTechnicien) const;

  // Helper pour le menu
  Scene *getScenePtr(string code);
};

#endif // FESTIVALMANAGER_H
