#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>

#include "Joueur.h"


class Partie {
public:
    Partie(unsigned short nbrFamille,
           unsigned short nbrCarteParFamille,
           unsigned short nbrJoueurs,

           unsigned short nbrCarteParJoueurs,
           const std::string nomJoueurs[]);

    std::vector<Carte> slice(const std::vector<Carte>& v, int m, int n);
    void familleComplete(const unsigned iFamille);

    unsigned int getiNoTour();
    void jouerTour(Joueur j);
    void jouerPartie();

private:
    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    unsigned int iNoTour;

    std::vector<bool> vFamilles;

    // TODO: Vecteur familles, avec une fonction familleComplete

};


#endif //INF2_LABO3_PARTIE_H
