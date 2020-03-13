#include <iostream>
#include "Partie.h"
#include "Parametre.h"

using namespace std;

int main() {

    Partie p1(NOMBRE_FAMILLES,CARTES_PAR_FAMILLE,NOMBRE_JOUEURS,CARTES_PAR_JOUEUR,NOM_JOUEURS);
    p1.jouerPartie();

    cout << "Final test" << endl;
    return 0;
}
