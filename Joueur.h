#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>
#include <algorithm>

#include "Carte.h"

class Joueur {
public:
    Joueur(std::string nom, std::vector<Carte> cartes) : strNom(nom), vCarteEnMain(cartes) {};

    friend void echangerCarte(Joueur& j1, Joueur& j2, const Carte& carteAEchanger, std::vector<Carte>::iterator carteAutreJoueur);
    Carte decideCarte(std::vector<bool> vFamilles) ;
    std::vector<Carte>::iterator demanderCarte(const Carte& carte) ;

    void insererCarteEnMain(Carte& carte);
    void trierCartesEnMain();

    void detecterFamille(std::vector<bool>& vFamilles);

    // Accesseurs pour la main du joueur
    const std::vector<Carte> &getVCarteEnMain() const;
    const std::string &getStrNom() const;


    void piocher(std::vector<Carte>& vTasDePioche);
    std::vector<Carte> vCarteEnMain;

    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);
private:
    const std::string strNom;

    std::vector<unsigned> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
