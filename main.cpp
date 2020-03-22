
#include "Partie.h"
#include <ctime>
using namespace std;

int main() {
    Partie p(1);
    p.jouerPartie();

    srand((unsigned) time(NULL));
    const int NBSERIEPARTIE = 5;

 // CAS 1
    const int NBPARTIES = 100;
    vector<int> vTotaux1(NOMBRE_JOUEURS);
    for (int j = 0; j < NBSERIEPARTIE; ++j) {
        for(int partie = 1; partie <= NBPARTIES; ++partie){
            Partie p1(1);
            vector<int> vResultats = p1.jouerPartie();

            for(int i = 0; i < NOMBRE_JOUEURS; ++i){
                vTotaux1.at(i) += vResultats.at(i);
            }
        }
    }
    cout << "Resultats cas 1 (sur " << NBSERIEPARTIE << " series de " << NBPARTIES << " parties):" << endl;
    for(int i = 0; i < NOMBRE_JOUEURS; ++i){
        cout << "Joueur " << i+1 << ": " << (float(vTotaux1.at(i))/(NBPARTIES*NOMBRE_FAMILLES*NBSERIEPARTIE)) * 100 << "%" << endl;;
    }

    // CAS 2
    const int NBPARTIES2 = 100;
    vector<int> vTotaux2(NOMBRE_JOUEURS);
    for (int k = 0; k < NBSERIEPARTIE; ++k) {
        for(int partie = 1; partie <= NBPARTIES2; ++partie){
            Partie p2(partie%NOMBRE_JOUEURS);
            vector<int> vResultats2 = p2.jouerPartie();

            for(int i = 0; i < NOMBRE_JOUEURS; ++i){
                vTotaux2.at(i) += vResultats2.at(i);
            }
        }
    }
    cout << "Resultats cas 2 (sur " << NBSERIEPARTIE << " series de " << NBPARTIES << " parties):" << endl;
    for(int i = 0; i < NOMBRE_JOUEURS; ++i){
        cout << "Joueur " << i+1 << ": " << (float(vTotaux2.at(i))/(NBPARTIES2*NOMBRE_FAMILLES*NBSERIEPARTIE)) * 100 << "%" << endl;
    }


    return 0;
}
