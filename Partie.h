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


           unsigned short nbrCarteParJoueurs);

    std::vector<Carte> slice(const std::vector<Carte>& v, int m, int n) {
        auto first = v.cbegin() + m;
        auto last = v.cbegin() + n + 1;
    }
    void familleComplete(const unsigned iFamille);

    // TODO: Fonction piocher
    // TODO: Fonctions getTour, jouerTour, terminerPartie

    // TODO: Fonctions getTour, jouerTour, jouerPartie
    unsigned int getiNoTour();
    void jouerTour();

private:
    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    unsigned int iNoTour;

    std::vector<bool> vFamilles;

    // TODO: Vecteur familles, avec une fonction familleComplete

};


#endif //INF2_LABO3_PARTIE_H
