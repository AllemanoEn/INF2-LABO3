#include "Joueur.h"
#include "Parametre.h"

using namespace std;


// Decide quelle carte demander en fonction de sa main actuelle
Carte Joueur::decideCarte(vector<bool> vFamilles) {
    // Partie 1 : Carte random à demander, que le joueur ne possède PAS, et dont la famille n'est pas complète
    // Partie Bonus: Carte selon le nombre de cartes de cette famille dans la main

    // Choisir une famille au hasard
    int iFamille = rand() % NOMBRE_FAMILLES;

    // Incrémente la famille jusqu'à trouver une famille qui n'est pas déjà complétée
    while(vFamilles.at(iFamille) == true) {
        iFamille = (iFamille + 1)%NOMBRE_FAMILLES;
    }
    iFamille++;

    // Choisir une carte au hasard
    unsigned int iMembre = rand() % CARTES_PAR_FAMILLE + 65;

    // Incrémente la carte jusqu'à trouver une carte qui n'est pas dans la main du joueur
    Carte carteATester (iFamille, iMembre);
    while(demanderCarte(carteATester)) {
        iMembre = (iMembre)%CARTES_PAR_FAMILLE + 65;

        carteATester.setMembre(iMembre);
    }

    return carteATester;
    
    // Stratégie pour la classe MeilleurJoueur
    /*// Sinon il va compter ses cartes et demander une carte qu'il ne possède pas encore de la famille la plus remplie dans sa main.

    vector<Carte>::iterator meilleurChoix;
    int count = 0;
    int countMax = 0;
    int iFamilleEnCours = 0;

    auto carte = vCarteEnMain.begin();
    for(; carte != vCarteEnMain.end(); carte++){
        if(carte->getFamille() != iFamilleEnCours){
            if(count >= countMax){
                countMax = iFamilleEnCours;
                count = 0;
            }

        }
        else {
            count++;
        }
    }*/

}


// Recherche une carte dans la main du joueur
vector<Carte>::iterator Joueur::rechercherCarte(const Carte &carte) {

    auto posCarte = vCarteEnMain.begin();
    for(; posCarte != vCarteEnMain.end(); ++posCarte){
        if(*posCarte == carte)
            break;
    }

    return posCarte;
}


void echangerCarte(Joueur& j1, Joueur& j2, const Carte& carteAEchanger) {
    auto carteJ2 = j2.rechercherCarte(carteAEchanger);
    j1.insererCarteEnMain(carteAEchanger);
    j2.vCarteEnMain.erase(carteJ2);
}

// insère une carte à sa place
void Joueur::insererCarteEnMain(Carte carte){
    bool inseree = false;
    for (int i = 0; i < vCarteEnMain.size(); ++i) {
        if(carte < this->vCarteEnMain.at(i)){
            vCarteEnMain.insert(vCarteEnMain.begin()+i, carte);
            inseree = true;
            break;
        }
    }
    if(!inseree)
        vCarteEnMain.push_back(carte);
}

// Trie les cartes de la main du joueur
void Joueur::trierCartesEnMain(){
    std::sort(vCarteEnMain.begin(), vCarteEnMain.end());
}


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille(std::vector<bool>& vFamilles) {
    unsigned int iCpt = 0,iPos = 0;

    for (unsigned short fam = 1; fam <= CARTES_PAR_FAMILLE ; fam++) {
        for (auto c = vCarteEnMain.begin(); c < vCarteEnMain.end(); c++, iPos++) {
            if (c->getFamille() == fam) {
                iCpt++;
                if (iCpt == NOMBRE_FAMILLES) {
                    iPos -= (CARTES_PAR_FAMILLE -1);
                    auto pos = vCarteEnMain.begin() + iPos;
                    cout << "Famille complete : " << pos->getFamille();
                    vFamilles.at(vCarteEnMain.at(iPos).getFamille() - 1) = true;
                    vFamillesSurTable.push_back(pos->getFamille());
                    vCarteEnMain.erase(pos, pos+CARTES_PAR_FAMILLE);
                }
            }
        }
    }

}

void Joueur::piocher(std::vector<Carte>& vTasDePioche) {
    this->vCarteEnMain.push_back(vTasDePioche.at(0));
    vTasDePioche.erase(vTasDePioche.begin());
}

const string &Joueur::getStrNom() const {
    return strNom;
}

const vector<Carte> &Joueur::getVCarteEnMain() const {
    return vCarteEnMain;
}

ostream& operator<<(ostream& lhs, const Joueur& rhs){
    lhs << "[ ";
    for(auto carteEnMain : rhs.vCarteEnMain){
        lhs << carteEnMain << " ";
    }
    lhs << "]" ;

    return lhs;
}

bool Joueur::demanderCarte(const Carte &carte) {
    return !(rechercherCarte(carte) == vCarteEnMain.end());
}
