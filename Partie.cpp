#include "Partie.h"

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
    vector<Joueur> vJoueurs;

    //Creation des joueurs
    for (int i = 0,c = 0; i < nbrJoueurs; ++i,c+=CARTES_PAR_JOUEUR+1) {
        vJoueurs.push_back(Joueur(NOM_JOUEURS[i],slice(vTasDePioche,c,c+CARTES_PAR_JOUEUR)));
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(),vTasDePioche.begin()+(NOMBRE_JOUEURS*CARTES_PAR_JOUEUR));

}
