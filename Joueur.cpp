#include "Joueur.h"
#include "Parametre.h"

using namespace std;


// Decide quelle carte demander en fonction de sa main actuelle
Carte Joueur::decideCarte(const vector<bool>& vFamilles) const{
    // TODO: Demander une carte qui n'appartient pas à une famille déjà complète
    // TODO: Ne pas demander plusieurs fois la même carte à un joueur ?
    // Partie 1 : Carte random à demander, que le joueur ne possède PAS, et dont la famille n'est pas complète
    // Partie Bonus: Carte selon le nombre de cartes de cette famille dans la main

    // Prendre en compte le cas où le joueur n'a plus de cartes
    if(vCarteEnMain.empty()){
        // Demander une carte d'une famille qui n'a pas déjà été complétée

    }

    // Sinon il va compter ses cartes et demander une carte qu'il ne possède pas encore de la famille la plus remplie dans sa main.

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
    }

}


// Recherche une carte dans la main du joueur
vector<Carte>::iterator Joueur::demanderCarte(const Carte &carte) {

    auto posCarte = vCarteEnMain.begin();
    for(; posCarte != vCarteEnMain.end(); ++posCarte){
        if(*posCarte == carte)
            break;
    }

    return posCarte;
}


void echangerCarte(Joueur& j1, Joueur& j2, const Carte& carteAEchanger, vector<Carte>::iterator carteAutreJoueur) {
    j1.vCarteEnMain.push_back(carteAEchanger);
    j2.vCarteEnMain.erase(carteAutreJoueur);
}

// insère une carte à sa place
void Joueur::insererCarteEnMain(Carte& carte){

}

// Trie les cartes de la main du joueur
void Joueur::trierCartesEnMain(){
    //https://fr.wikipedia.org/wiki/Tri_par_insertion


}


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille(std::vector<bool>& vFamilles) {

    vFamillesSurTable += slice(vCarteEnMain,i,j);

    vFamilles.at(iFamille - 1) = true;

    vector<vector<Carte>::iterator> vCartesParFamille;
/*
    // Pour chaque famille:
    for(int iFamille = 1; iFamille <= NOMBRE_FAMILLES; ++iFamille){

        // On compte le nombre de cartes de cette famille que le joueur possède
        for (auto carte = vCarteEnMain.begin(); carte != vCarteEnMain.end(); ++carte){
            if (carte->getFamille() == iFamille ){
                vCartesParFamille.push_back(carte);
            }

            // Si la famille est complétée
            if(vCartesParFamille.size() == CARTES_PAR_FAMILLE){

                // Supprimer les cartes de la main
                for ( auto carteASupprimer : vCartesParFamille)
                    vCarteEnMain.erase(carteASupprimer);

            }
        }
        vCartesParFamille.clear();
    }*/
// vFamilles.at(iFamille - 1) = true;
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
