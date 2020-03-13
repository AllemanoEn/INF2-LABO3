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


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille() {
    // TODO: Dans la classe Partie, faire un tableau indiquant quelles familles sont terminées ou non. La mettre à jour si une famille est complétée
    vector<vector<Carte>::iterator> vCartesParFamille;

    // Pour chaque famille:
    for(int iFamille = 0; iFamille < NOMBRE_FAMILLES; ++iFamille){
        unsigned count = 0;
        for (auto carte = vCarteEnMain.begin(); carte != vCarteEnMain.end(); ++carte){
            if (carte->getFamille() == iFamille ){
                vCartesParFamille.push_back(carte);
            }
            if(vCartesParFamille.size() == CARTES_PAR_FAMILLE){
                for ( auto carteASupprimer : vCartesParFamille){
                    vFamillesSurTable.push_back(*carteASupprimer); // TODO: Mettre toutes les cartes ou seulement le nom de la famille ?
                    vCarteEnMain.erase(carteASupprimer);
                }

            }
        }
    }

}
