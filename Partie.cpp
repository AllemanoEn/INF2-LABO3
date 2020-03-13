#include "Partie.h"

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


    //Creation des joueurs
    for (int i = 0,c = 0; i < nbrJoueurs; ++i,c+=nbrCarteParJoueurs) {
        vJoueurs.push_back(Joueur(nomJoueurs[i],slice(vTasDePioche,c,c+nbrCarteParJoueurs-1)));
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(),vTasDePioche.begin()+(nbrJoueurs*nbrCarteParJoueurs));

}
