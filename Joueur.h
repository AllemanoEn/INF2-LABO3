#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>
#include <algorithm>

#include "Carte.h"

class Joueur {
public:
    Joueur(std::string nom, std::vector<Carte> cartes) : strNom(nom), vCarteEnMain(cartes) {};

    friend void echangerCarte(Joueur& j1, Joueur& j2, const Carte& carteAEchanger);
    Carte decideCarte(std::vector<bool> vFamilles) ;
    bool demanderCarte(const Carte& carte) ;
    std::vector<Carte>::iterator rechercherCarte(const Carte &carte);

    void insererCarteEnMain(Carte carte);
    void trierCartesEnMain();

    void detecterFamille(std::vector<bool>& vFamilles);

    // Accesseurs pour la main du joueur
    const std::vector<Carte> &getVCarteEnMain() const;
    const std::string &getStrNom() const;


    void piocher(std::vector<Carte>& vTasDePioche);
    std::vector<Carte> vCarteEnMain;

    friend bool operator==(const Joueur& lhs, const Joueur& rhs){
        return (lhs.strNom == rhs.strNom) && (lhs.getVCarteEnMain() == rhs.getVCarteEnMain());
    }
    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);
private:
    const std::string strNom;

    std::vector<unsigned> vFamillesSurTable;
};


#endif //INF2_LABO3_JOUEUR_H
