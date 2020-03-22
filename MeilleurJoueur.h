/// \file MeilleurJoueur.h
/// \authors Enzo Allemano, David Pellissier, Michael Ruckstuhl
/// \date 22.03.2020
///
/// \brief \b Laboratoire \b 03
/// \brief Contient la classe MeilleurJoueur
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#ifndef INF2_LABO3_MEILLEURJOUEUR_H
#define INF2_LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur{
public:
    MeilleurJoueur(std::string nom, std::vector<Carte> cartes) : Joueur(nom, cartes) { }
    Carte decideCarte(const std::vector<bool>& vFamilles) const;
};


#endif //INF2_LABO3_MEILLEURJOUEUR_H
