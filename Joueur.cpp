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

           if(carteAutreJoueur != j2.vCarteEnMain.end()) {
               j1.vCarteEnMain.push_back(carteAEchanger);
               j2.vCarteEnMain.erase(carteAutreJoueur);

               j1.detecterFamille();

               // Nouvel échange de cartes
               echangerCarte(j1, j2);

           }
           else {
               // Piocher
           }

}


// Détecter si une famille est complète dans sa main et la pose
void Joueur::detecterFamille() {
    // TODO: Dans la classe Partie, faire un tableau indiquant quelles familles sont terminées ou non. La mettre à jour si une famille est complétée
    

}
