#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>
#include <random>

#include "Joueur.h"
#include "Parametre.h"

class Partie {
public:
    Partie();

    std::vector<Carte> slice(std::vector<Carte> const &v, int m, int n);

    void jouerPartie();
private:
    void jouerTour(Joueur j);
    bool checkFinDePartie();
    unsigned int getiNoTour();

    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    std::vector<bool> vFamilles;

    unsigned int iNoTour;

};


#endif //INF2_LABO3_PARTIE_H
