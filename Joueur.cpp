#include "Joueur.h"
#include "Parametre.h"

using namespace std;

// Décide de la carte à demander et demande à l'autre joueur si il a la carte
bool Joueur::demanderCarte(const Joueur& j2, Carte* carte) {

}

// Decide quelle carte demander en fonction de sa main actuelle
Carte* Joueur::decideCarte() const{

}


// Possède carte


// Détecter si une famille est complète dans sa main et la pose

void echangerCarte(Joueur& j1, Joueur& j2) {
    bool bPossedeCarte = true;

    // Tant que le joueur 2 possède la carte à échanger
    while(bPossedeCarte)
    {
        // Demander la carte
           Carte* carteAEchanger = j1.decideCarte();

        //
    }
}

// Recherche une carte dans la main du joueur
vector<Carte>::iterator Joueur::chercherCarte(const Carte &carte) {

    auto posCarte = vCarteEnMain.begin();
    for(; posCarte != vCarteEnMain.end(); ++posCarte){
        if(*posCarte == carte)
            break;
    }

    return posCarte;
}
