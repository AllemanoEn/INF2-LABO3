#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>

#include "Parametre.h"
#include "Joueur.h"


class Partie {
public:
    Partie(unsigned short nbrFamille,
           unsigned short nbrCarteParFamille,
           unsigned short nbrJoueurs,
           unsigned short nbrCarteParJoueurs,
           const std::string nomJoueurs[]);
    
    std::vector<Carte> slice(const std::vector<Carte>& v, int m, int n)
    {
        auto first = v.cbegin() + m;
        auto last = v.cbegin() + n + 1;

        std::vector<Carte> vec(first, last);
        return vec;
    }

    // TODO: Fonction piocher
    // TODO: Fonctions getTour, jouerTour, terminerPartie

private:
    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    // TODO: Stocker le no de tour
    // TODO: Vecteur familles, avec une fonction familleComplete

};


#endif //INF2_LABO3_PARTIE_H
