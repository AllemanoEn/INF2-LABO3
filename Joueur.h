#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>

#include "Carte.h"

class Joueur {
public:
    Joueur(std::string nom, std::vector<Carte> cartes) : strNom(nom), vCarteEnMain(cartes) {};
    void demanderCarte();
    void detecterFamille();
    friend void echangerCarte();

private:
    const std::string strNom;
    std::vector<Carte> vCarteEnMain;
    std::vector<Carte> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
