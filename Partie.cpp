#include "Partie.h"
#include "Parametre.h"

#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

Partie::Partie() {

    //Generateur aléatoir
    //std::random_device dev;
    //std::mt19937 rng(dev());
    //std::uniform_int_distribution<std::mt19937::result_type> dist4(0,3);
    srand((unsigned) time(NULL));

    // Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= NOMBRE_FAMILLES; ++j) {
        for (int i = 0; i < CARTES_PAR_FAMILLE; ++i) {
            vTasDePioche.push_back(Carte(j, famille++));
        }
        famille = 65;
    }

    // On mélange le jeu de carte
    unsigned seed = time(nullptr);
    shuffle(vTasDePioche.begin(), vTasDePioche.end(), default_random_engine(seed));


    //Creation des joueurs et de leur main
    for (int i = 0, c = 0; i < NOMBRE_JOUEURS; ++i, c += CARTES_PAR_JOUEUR) {
        vJoueurs.push_back(Joueur(NOM_JOUEURS[i], slice(vTasDePioche, c, c + CARTES_PAR_JOUEUR - 1)));
        vJoueurs.at(i).trierCartesEnMain();
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(), vTasDePioche.begin() + (NOMBRE_JOUEURS * CARTES_PAR_JOUEUR));

    //Générer le vecteur vFamilles à false
    vector<bool> vFam(NOMBRE_FAMILLES, false);
    vFamilles = vFam;

    //On définit le premier tour
    iNoTour = 1;

}

unsigned int Partie::getiNoTour() {
    return iNoTour;
}

void Partie::jouerTour(Joueur &j1) {

    // Décide d'une carte à échanger
    Carte carteAEchanger = j1.decideCarte(vFamilles);

    // Décide d'un joueur à qui demander
    unsigned j2 = joueurAleatoire(j1);

    // Demande la carte à l'autre joueur
    bool carteAutreJoueur = vJoueurs.at(j2).demanderCarte(carteAEchanger);
    if (DEBUG_MODE)
        cout << j1.getStrNom() << " demande a " << vJoueurs.at(j2).getStrNom() << " la carte "
             << carteAEchanger.getFamille() << char(carteAEchanger.getMembre()) << endl;

    // Si le joueur 2 possède la carte, faire l'échange et rejouer. Sinon, le joueur 1 pioche une carte.
    if (carteAutreJoueur) {
        echangerCarte(j1, vJoueurs.at(j2), carteAEchanger);
        if (DEBUG_MODE)
            cout << "\tet " << vJoueurs.at(j2).getStrNom() << " donne la carte a " << j1.getStrNom() << endl;
        j1.detecterFamille(vFamilles);

        jouerTour(j1);
    } else {
        if (DEBUG_MODE) cout << "\tmais " << vJoueurs.at(j2).getStrNom() << " ne l'a pas" << endl;
        if (!vTasDePioche.empty()) {
            j1.piocher(vTasDePioche);
            j1.detecterFamille(vFamilles);
        }
    }


}

void Partie::jouerPartie() {
    do {

        if (DEBUG_MODE) {
            cout << "*** Tour " << iNoTour << " ***" << endl;

            for (size_t i = 0; i < vJoueurs.size(); ++i) {
                cout << vJoueurs.at(i).getStrNom() << " : " << vJoueurs.at(i) << endl;
            }
            cout << "Pioche : ";
            for (auto carteEnMain : vTasDePioche) {
                cout << carteEnMain << " ";
            }
            cout << endl;
        }

        for (auto &j : vJoueurs) {
            jouerTour(j);

        }
        iNoTour++;

    } while (checkFinDePartie());

}


bool Partie::checkFinDePartie() {
    for (const auto &f :vFamilles) {
        if (!f) {
            return true;
        }
    }
    cout << endl << "FIN DE PARTIE";
    return false;

}

std::vector<Carte> Partie::slice(std::vector<Carte> const &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<Carte> vec(first, last);
    return vec;
}

unsigned int Partie::joueurAleatoire(Joueur j) {
//    srand (static_cast<unsigned int>(time(NULL)));
//    unsigned int iRand;

    //inspiré de: http://www.cplusplus.com/reference/random/
/*    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned> distribution(0,NOMBRE_JOUEURS-1);
    unsigned iRand = distribution(generator);
    while (vJoueurs.at(iRand) == j){
        iRand = distribution(generator);
    }*/

    //do
    // iRand = rand() % 3;

    //while (vJoueurs.at(iRand) == j);


    unsigned int iRand = 0;
    do
        iRand = rand() % NOMBRE_JOUEURS;
    while (vJoueurs.at(iRand) == j);

    return iRand;

/*    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,NOMBRE_JOUEURS); // distribution in range [0, NOMBRE_JOUEURS]

    unsigned iRand = 0;
    iRand = dist(rng);
    while (vJoueurs.at(iRand) == j){
        iRand = dist(rng);
    }
    return iRand;*/

}