#include "Joueur.h"
#include "Parametre.h"
#include "Affichage.h"

using namespace std;

Carte Joueur::decideCarte(const vector<bool>& vFamilles) const{

    // Choisir une famille au hasard
    int iFamille = (rand() % NOMBRE_FAMILLES) + 1;

    // Incrémente la famille jusqu'à trouver une famille qui n'est pas déjà complétée et dont il possède au moins une carte
    while (vFamilles.at(static_cast<unsigned int>(iFamille - 1)) || ((compteCartesFamille(
            static_cast<unsigned int>(iFamille)) == 0) && !(vCarteEnMain.empty()))) {
        iFamille = ((iFamille + 1) % NOMBRE_FAMILLES) + 1;
    }

    // Choisir une carte au hasard
    unsigned int iMembre = rand() % CARTES_PAR_FAMILLE + 65;

    // Incrémente la carte jusqu'à trouver une carte qui n'est pas dans la main du joueur
    Carte carteATester(static_cast<unsigned short>(iFamille), static_cast<unsigned short>(iMembre));
    while (demanderCarte(carteATester)) {
        iMembre = (iMembre) % CARTES_PAR_FAMILLE + 65;
        carteATester.setMembre(static_cast<unsigned short>(iMembre));
    }
    return carteATester;
}

const vector<unsigned short> &Joueur::getVFamillesSurTable() const {
    return vFamillesSurTable;
}


// Recherche une carte dans la main du joueur
vector<Carte>::const_iterator Joueur::rechercherCarte(const Carte &carte) const {

    auto posCarte = vCarteEnMain.begin();
    for (; posCarte != vCarteEnMain.end(); ++posCarte) {
        if (*posCarte == carte)
            break;
    }

    return posCarte;
}


void echangerCarte(Joueur &j1, Joueur &j2, const Carte &carteAEchanger) {

    auto carteJ2 = j2.rechercherCarte(carteAEchanger);
    j1.insererCarteEnMain(carteAEchanger);
    j2.vCarteEnMain.erase(carteJ2);
}

// insère une carte à sa place
void Joueur::insererCarteEnMain(const Carte& carte) {
    bool inseree = false;
    for (unsigned int i = 0; i < vCarteEnMain.size(); ++i) {
        if (carte < this->vCarteEnMain.at(i)) {
            vCarteEnMain.insert(vCarteEnMain.begin() + static_cast<int>(i), carte);
            inseree = true;
            break;
        }
    }
    if (!inseree)
        vCarteEnMain.push_back(carte);
}

// Trie les cartes de la main du joueur
void Joueur::trierCartesEnMain() {
    std::sort(vCarteEnMain.begin(), vCarteEnMain.end());
}


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille(std::vector<bool> &vFamilles) {

    unsigned int iCpt, iPos = 0;
    for (unsigned short fam = 1; fam <= NOMBRE_FAMILLES; fam++) {
        iCpt = 0;
        for (auto c = vCarteEnMain.begin() + static_cast<int>(iPos); c < vCarteEnMain.end(); c++, iPos++) {
            if (c->getFamille() == fam) {
                iCpt++;
                if (iCpt == CARTES_PAR_FAMILLE) {
                    iPos -= (CARTES_PAR_FAMILLE - 1);
                    auto pos = vCarteEnMain.begin() + static_cast<int>(iPos);
                    vFamilles.at(vCarteEnMain.at(iPos).getFamille() - 1) = true;
                    vFamillesSurTable.push_back(pos->getFamille());
                    vCarteEnMain.erase(pos, pos + CARTES_PAR_FAMILLE);
                }
            } else if (c->getFamille() > fam) break;
        }
    }

}

void Joueur::piocher(std::vector<Carte> &vTasDePioche) {
    afficherPiocher(this, vTasDePioche.at(vTasDePioche.size() - 1));
    this->insererCarteEnMain(vTasDePioche.at(vTasDePioche.size() - 1));
    vTasDePioche.pop_back();
}

const string &Joueur::getStrNom() const {
    return strNom;
}

const vector<Carte> &Joueur::getVCarteEnMain() const {
    return vCarteEnMain;
}

ostream &operator<<(ostream &lhs, const Joueur &rhs) {
    //Affiche les cartes du joueur
    for (auto carteEnMain : rhs.vCarteEnMain) {
        lhs << carteEnMain << " ";
    }
    //Un espace
    lhs << " ";
    //Affiche les familles complétées du joueurs entre crochets
    lhs << "[ ";
    for (auto FamillesSurTable : rhs.vFamillesSurTable) {
        lhs << FamillesSurTable << " ";
    }
    lhs << "]";
    return lhs;
}

bool Joueur::demanderCarte(const Carte &carte) const{
    return !(rechercherCarte(carte) == vCarteEnMain.end());
}

void Joueur::setVFamillesSurTable(const vector<unsigned short> &vFamillesSurTable) {
    Joueur::vFamillesSurTable = vFamillesSurTable;
}

unsigned Joueur::compteCartesFamille(unsigned iFamille) const{
    unsigned count = 0;
    for (auto carte : vCarteEnMain) {
        if (carte.getFamille() == iFamille)
            count++;
    }
    return count;
}

void Joueur::setVCarteEnMain(const vector<Carte> &vCarteEnMain) {
    Joueur::vCarteEnMain = vCarteEnMain;
}
