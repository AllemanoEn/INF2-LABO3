#include "Partie.h"
#include "Parametre.h"

#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

Partie::Partie() {

    // Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= NOMBRE_FAMILLES; ++j) {
        for (int i = 0; i < CARTES_PAR_FAMILLE; ++i) {
            vTasDePioche.push_back(Carte(j, famille++));
        }
        famille = 65;
    }

    // On mélange le jeu de carte
    /*
    unsigned seed = time(nullptr);
    shuffle(vTasDePioche.begin(), vTasDePioche.end(), default_random_engine(seed));
     */

    //Creation des joueurs et de leur main
    for (int i = 0,c = 0; i < NOMBRE_JOUEURS; ++i,c+=CARTES_PAR_JOUEUR) {
        vJoueurs.push_back(Joueur(NOM_JOUEURS[i],slice(vTasDePioche,c,c+CARTES_PAR_JOUEUR-1)));
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(),vTasDePioche.begin()+(NOMBRE_JOUEURS*CARTES_PAR_JOUEUR));

    //Générer le vecteur vFamilles à false
    vector<bool> vFam (NOMBRE_FAMILLES, false);
    vFamilles = vFam;

    //On définit le premier tour
    iNoTour = 1;

}

unsigned int Partie::getiNoTour() {
    return iNoTour;
}

void Partie::jouerTour(Joueur j1) {

    // Décide d'une carte à échanger
    Carte carteAEchanger = j1.decideCarte(vFamilles);

    // Décide d'un joueur à qui demander
    srand (time(NULL));
    Joueur j2 = vJoueurs.at(rand()%3);
    vector<Carte> vCartesJoueur2 = j2.getVCarteEnMain();

    // Demande la carte à l'autre joueur
    auto carteAutreJoueur = j2.demanderCarte(carteAEchanger);
    if(DEBUG_MODE) cout << j1.getStrNom() << " demande à " << j2.getStrNom() << " la carte " << carteAEchanger.getFamille() << carteAEchanger.getMembre() << endl;

    // Si le joueur 2 possède la carte, faire l'échange et rejouer. Sinon, le joueur 1 pioche une carte.
    if(carteAutreJoueur != vCartesJoueur2.end()) {
        echangerCarte(j1, j2, carteAEchanger, carteAutreJoueur);
        if(DEBUG_MODE) cout << "\tet " << j2.getStrNom() << " donne la carte à " << j1.getStrNom() << endl;

        jouerTour(j1);
    }
    else if(!vTasDePioche.empty()){
        if(DEBUG_MODE) cout << "\tmais " << j2.getStrNom() << "ne l'a pas" << endl;
        j1.piocher(vTasDePioche);
    }
}

void Partie::jouerPartie() {
    do

    for(const auto& j : vJoueurs){
        jouerTour(j);
        iNoTour++;
    }

    while (checkFinDePartie());
}


bool Partie::checkFinDePartie() {
    for(const auto& f :vFamilles){
        if(f==false){
            return false;
        }
    }
    return true;
}

std::vector<Carte> Partie::slice(std::vector<Carte> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<Carte> vec(first, last);
    return vec;
}
