#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>

#include "Carte.h"

class Joueur {
public:
    Joueur(std::string& nom, std::vector<Carte>& cartes) : strNom(nom), vCarteEnMain(cartes) {};

    bool demanderCarte(const Joueur& j2, Carte* carte);
    Carte* decideCarte() const;

    friend void echangerCarte(Joueur& j1,  Joueur& j2);
    std::vector<Carte>::iterator chercherCarte(const Carte& carte);
    void detecterFamille();


private:
    const std::string strNom;
    std::vector<Carte> vCarteEnMain;
    std::vector<Carte> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
