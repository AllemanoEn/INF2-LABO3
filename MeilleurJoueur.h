//
// Created by david on 22.03.20.
//

#ifndef INF2_LABO3_MEILLEURJOUEUR_H
#define INF2_LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur{
public:
    MeilleurJoueur(std::string nom, std::vector<Carte> cartes) : Joueur(nom, cartes) { }
    Carte decideCarte(std::vector<bool> vFamilles);
};


#endif //INF2_LABO3_MEILLEURJOUEUR_H
