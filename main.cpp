
#include "Partie.h"

using namespace std;

int main() {
    Partie p1(1);
    p1.jouerPartie();

/*    // CAS 1
    const int NBPARTIES = 100;
    vector<int> vTotaux1(4);
    for(int partie = 1; partie <= NBPARTIES; ++partie){
        Partie p1(1);
        vector<int> vResultats = p1.jouerPartie();

        for(int i = 0; i < NOMBRE_JOUEURS; ++i){
            vTotaux1.at(i) += vResultats.at(i);
        }
    }
    cout << "Resultats cas 1 (sur " << NBPARTIES << " parties):" << endl;
    for(int i = 0; i < NOMBRE_JOUEURS; ++i){
        cout << "Joueur " << i+1 << ": " << (float(vTotaux1.at(i))/(NBPARTIES*NOMBRE_FAMILLES)) * 100 << "%" << endl;;
    }

    // CAS 2
    const int NBPARTIES2 = 100;
    vector<int> vTotaux2(4);
    for(int partie = 1; partie <= NBPARTIES2; ++partie){
        Partie p2(partie%NOMBRE_JOUEURS);
        vector<int> vResultats2 = p2.jouerPartie();

        for(int i = 0; i < NOMBRE_JOUEURS; ++i){
            vTotaux2.at(i) += vResultats2.at(i);
        }
    }
    cout << endl << "Resultats cas 2 (sur " << NBPARTIES << " parties):" << endl;
    for(int i = 0; i < NOMBRE_JOUEURS; ++i){
        cout << "Joueur " << i+1 << ": " << (float(vTotaux2.at(i))/(NBPARTIES2*NOMBRE_FAMILLES)) * 100 << "%" << endl;
    }*/


    return 0;
}
