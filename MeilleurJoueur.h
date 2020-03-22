/// \file MeilleurJoueur.h
/// \authors Enzo Allemano, David Pellissier, Michael Ruckstuhl
/// \date 22.03.2020
///
/// \brief \b Laboratoire \b 03
/// \brief Contient la classe MeilleurJoueur dérivée de la classe Joueur
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#ifndef INF2_LABO3_MEILLEURJOUEUR_H
#define INF2_LABO3_MEILLEURJOUEUR_H

#include "Joueur.h"

class MeilleurJoueur : public Joueur{
public:
    /**
     * Constructeur pour la classe MeilleurJoueur
     * @param nom nom du joueur
     * @param cartes vecteur de cartes
     */
    MeilleurJoueur(std::string nom, std::vector<Carte> cartes) : Joueur(nom, cartes) { }

    /**
     * Décide d'une carte à demander de manière plus intelligente
     * @param vFamilles vecteur de bool indiquant quelles sont les familles déjà complétées
     * @return la carte que le joueur veut demander
     * @details La fonction décide d'une carte selon les cartes qu'il a déjà en main.
     * La famille de la carte choisie est la famille dont le joueur possède actuellement le plus de cartes.
     */
    Carte decideCarte(const std::vector<bool>& vFamilles) const;
};


#endif //INF2_LABO3_MEILLEURJOUEUR_H
