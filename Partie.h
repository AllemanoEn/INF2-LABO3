#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>
#include <algorithm>

#include "Parametre.h"
#include "Joueur.h"


class Partie {
public:
    Partie(unsigned short nbrFamille,
           unsigned short nbrCarteParFamille,
           unsigned short nbrJoueurs,
           unsigned short nbrCarteParJoueurs);
private:
    std::vector<Carte> vTasDePioche;
};


#endif //INF2_LABO3_PARTIE_H
