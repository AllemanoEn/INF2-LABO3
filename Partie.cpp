#include "Partie.h"
#include "Parametre.h"

#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

Partie::Partie(unsigned short nbrFamille, unsigned short nbrCarteParFamille, unsigned short nbrJoueurs, unsigned short nbrCarteParJoueurs, const string nomJoueurs[]) {

    // Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= nbrFamille; ++j) {
        for (int i = 0; i < nbrCarteParFamille; ++i) {
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
    for (int i = 0,c = 0; i < nbrJoueurs; ++i,c+=nbrCarteParJoueurs) {
        vJoueurs.push_back(Joueur(nomJoueurs[i],slice(vTasDePioche,c,c+nbrCarteParJoueurs-1)));
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(),vTasDePioche.begin()+(nbrJoueurs*nbrCarteParJoueurs));

    //Générer le vecteur vFamilles à false
    vector<bool> vFam (nbrFamille, false);
    vFamilles = vFam;

}

std::vector<Carte> Partie::slice(const std::vector<Carte> &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<Carte> vec(first, last);
    return vec;
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
