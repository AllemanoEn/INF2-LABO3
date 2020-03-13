#include "Joueur.h"
#include "Parametre.h"

using namespace std;


// Decide quelle carte demander en fonction de sa main actuelle
Carte Joueur::decideCarte() const{
    // TODO: Demander une carte qui n'appartient pas à une famille déjà complète
    // TODO: Ne pas demander plusieurs fois la même carte à un joueur ?
    // Partie 1 : Carte random à demander, que le joueur ne possède PAS, et dont la famille n'est pas complète
    // Partie Bonus: Carte selon le nombre de cartes de cette famille dans la main

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


void echangerCarte(Joueur& j1, Joueur& j2) {


        // Décide de la carte à échanger
           Carte carteAEchanger = j1.decideCarte();
           auto carteAutreJoueur = j2.demanderCarte(carteAEchanger);
           if(DEBUG_MODE) cout << j1.strNom << " demande à " << j2.strNom << " la carte " << carteAEchanger.getFamille() << carteAEchanger.getMembre() << endl;

           if(carteAutreJoueur != j2.vCarteEnMain.end()) {
               j1.vCarteEnMain.push_back(carteAEchanger);
               j2.vCarteEnMain.erase(carteAutreJoueur);

               if(DEBUG_MODE) cout << "\tet " << j2.strNom << " donne la carte à " << j1.strNom << endl;

               echangerCarte(j1, j2);
               j1.detecterFamille();

               // Nouvel échange de cartes

           }
           else {

               if(DEBUG_MODE) cout << "\tmais " << j2.strNom << "ne l'a pas" << endl;
               // Piocher
           }

}
// insère une carte à sa place
void Joueur::insererCarteEnMain(Carte& carte){

}

// Trie les cartes de la main du joueur
void Joueur::trierCartesEnMain(){
    // https://fr.wikipedia.org/wiki/Tri_par_insertion


}


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille() {

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
}

void Joueur::setvCartEnMain(Carte c) {
    vCarteEnMain.push_back(c);
}

void Joueur::piocher(std::vector<Carte>& vTasDePioche) {
    this->vCarteEnMain.push_back(vTasDePioche.at(0));
    vTasDePioche.erase(vTasDePioche.begin());
}
