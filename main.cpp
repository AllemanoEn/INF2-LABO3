#include <iostream>
#include "Partie.h"

#include "Parametre.h"
#include <vector>


using namespace std;

int main() {
    Partie p1;
    p1.jouerPartie();

//    Partie p1(NOMBRE_FAMILLES,CARTES_PAR_FAMILLE,NOMBRE_JOUEURS,CARTES_PAR_JOUEUR,NOM_JOUEURS);
 //   p1.jouerPartie();

//    Partie p1(NOMBRE_FAMILLES,CARTES_PAR_FAMILLE,NOMBRE_JOUEURS,CARTES_PAR_JOUEUR,NOM_JOUEURS);
//    p1.jouerPartie();

/*    vector<Carte> v;
    v.push_back(Carte(1,'C'));
    v.push_back(Carte(2,'C'));
    v.push_back(Carte(4,'A'));
    v.push_back(Carte(2,'B'));
    v.push_back(Carte(1,'B'));
    v.push_back(Carte(2,'A'));
    v.push_back(Carte(3,'A'));
    v.push_back(Carte(5,'D'));
    v.push_back(Carte(3,'D'));
    v.push_back(Carte(10,'A'));


    Joueur j("Alice", v);

    j.trierCartesEnMain();

    for (int k = 0; k < j.vCarteEnMain.size(); ++k) {
        for (int i = 0; i < j.vCarteEnMain.size(); ++i) {
            cout << j.vCarteEnMain.at(i) << " < " << j.vCarteEnMain.at(k) << " : " << (j.vCarteEnMain.at(i) < j.vCarteEnMain.at(k)) << endl;
        }
    }


    for (int i = 0; i < j.vCarteEnMain.size(); ++i) {
       cout << j.vCarteEnMain.at(i) << " ";
    }
    cout << endl;
    j.insererCarteEnMain(Carte(1,'A'));
    j.insererCarteEnMain(Carte(11,'A'));
    j.insererCarteEnMain(Carte(5,'L'));
    for (int i = 0; i < j.vCarteEnMain.size(); ++i) {
        cout << j.vCarteEnMain.at(i) << " ";
    }*/



    cout << "Final test" << endl;

    return 0;
}
