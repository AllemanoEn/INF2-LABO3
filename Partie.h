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
    std::vector<Carte> slice(const std::vector<Carte>& v, int m, int n)
    {
        auto first = v.cbegin() + m;
        auto last = v.cbegin() + n + 1;

        std::vector<Carte> vec(first, last);
        return vec;
    }
private:
    std::vector<Carte> vTasDePioche;
};


#endif //INF2_LABO3_PARTIE_H
