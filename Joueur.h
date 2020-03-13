#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>

#include "Carte.h"

class Joueur {
public:
    Joueur(std::string nom, std::vector<Carte> cartes) : strNom(nom), vCarteEnMain(cartes) {};

    friend void echangerCarte(Joueur& j1,  Joueur& j2);
    Carte decideCarte() const;
    std::vector<Carte>::iterator demanderCarte(const Carte& carte);
    void detecterFamille();

    //Accesseur pour la main du joueur
    void setvCartEnMain(Carte c);

    void piocher(std::vector<Carte>& vTasDePioche);

private:
    const std::string strNom;
    std::vector<Carte> vCarteEnMain;
    std::vector<Carte> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
