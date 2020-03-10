#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>

#include "Carte.h"

class Joueur {
    friend void echangerCarte();
public:
    void demanderCarte();
    void detecterFamille();
private:
    std::string strNom;
    std::vector<Carte> vCarteEnMain;
    std::vector<Carte> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
