#include "Partie.h"

#include <random>

using namespace std;

Partie::Partie(unsigned short nbrFamille, unsigned short nbrCarteParFamille, unsigned short nbrJoueurs, unsigned short nbrCarteParJoueurs) {
    //Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= nbrFamille; ++j) {
        for (int i = 0; i < nbrCarteParFamille; ++i) {
            vTasDePioche.push_back(Carte(j, famille++));
        }
        famille = 65;
    }

    //On mélange le jeu de carte

    //Creation des joueurs
    for (int i = 0; i < nbrJoueurs; ++i) {

    }

}
