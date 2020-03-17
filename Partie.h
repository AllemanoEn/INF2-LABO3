#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>

#include "Joueur.h"
#include "Parametre.h"


class Partie {
public:
    Partie(unsigned short nbrFamille,
           unsigned short nbrCarteParFamille,
           unsigned short nbrJoueurs,

           unsigned short nbrCarteParJoueurs,
           const std::string nomJoueurs[]);

    unsigned int getiNoTour();
    void jouerTour(Joueur j);
    void jouerPartie();
    bool checkFinDePartie();

private:
    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    std::vector<bool> vFamilles;

    unsigned int iNoTour;

};


#endif //INF2_LABO3_PARTIE_H
