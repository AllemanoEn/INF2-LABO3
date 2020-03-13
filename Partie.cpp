#include "Partie.h"

#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

Partie::Partie(unsigned short nbrFamille, unsigned short nbrCarteParFamille, unsigned short nbrJoueurs, unsigned short nbrCarteParJoueurs, const string nomJoueurs[]) {

    //Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= nbrFamille; ++j) {
        for (int i = 0; i < nbrCarteParFamille; ++i) {
            vTasDePioche.push_back(Carte(j, famille++));
        }
        famille = 65;
    }

    //On mélange le jeu de carte
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

void Partie::jouerTour(Joueur j) {

}

void Partie::jouerPartie() {

}


void Partie::familleComplete(const unsigned iFamille){
    vFamilles.at(iFamille - 1) = true;
}