#include "Partie.h"
#include "Parametre.h"
#include "Affichage.h"
#include "MeilleurJoueur.h"


#include <algorithm>
#include <random>

using namespace std;

Partie::Partie(std::vector<Joueur*> joueurs, const unsigned premierJoueur) : vJoueurs(joueurs) , premierJoueur(premierJoueur) {


    // Creation du tas de pioche
    unsigned short famille = 65;
    for (unsigned short j = 1; j <= NOMBRE_FAMILLES; ++j) {
        for (int i = 0; i < CARTES_PAR_FAMILLE; ++i) {
            vTasDePioche.push_back(Carte(j, famille++));
        }
        famille = 65;
    }

    // On mélange le jeu de cartes
    unsigned seed = time(nullptr);
    shuffle(vTasDePioche.begin(), vTasDePioche.end(), default_random_engine(seed));


    for (int i = 0, c = 0; i < NOMBRE_JOUEURS; ++i, c += CARTES_PAR_JOUEUR) {
        vJoueurs.at(i)->setVCarteEnMain(slice(vTasDePioche, c, c + CARTES_PAR_JOUEUR - 1));
        vJoueurs.at(i)->trierCartesEnMain();
        vJoueurs.at(i)->setVFamillesSurTable(vector<unsigned short>());
    }

    //On enlève les cartes du tas de pioche qui ont été distribuées
    vTasDePioche.erase(vTasDePioche.begin(), vTasDePioche.begin() + (NOMBRE_JOUEURS * CARTES_PAR_JOUEUR));

    //Générer le vecteur vFamilles à false
    vector<bool> vFam(NOMBRE_FAMILLES, false);
    vFamilles = vFam;

    //On définit le premier tour
    iNoTour = 1;

    vJoueurs.at(0)->decideCarte(vFamilles);
}

unsigned int Partie::getiNoTour() {
    return iNoTour;
}


bool Partie::jouerTour(Joueur& j1) {

    // Décide d'une carte à échanger
    Carte carteAEchanger = j1.decideCarte(vFamilles);

    // Décide d'un joueur à qui demander
    unsigned j2 = joueurAleatoire(j1);

    // Demande la carte à l'autre joueur
    bool carteAutreJoueur = vJoueurs.at(j2)->demanderCarte(carteAEchanger);
    afficherDemandeDeCarte(j1,j2,vJoueurs,carteAEchanger);
    // Si le joueur 2 possède la carte, faire l'échange et rejouer. Sinon, le joueur 1 pioche une carte.
    if (carteAutreJoueur) {
        echangerCarte(j1, *vJoueurs.at(j2), carteAEchanger);
        afficherALaCarte(j1,j2,vJoueurs);
        j1.detecterFamille(vFamilles);
        if(checkFinDePartie()){
            return true;
        }
        jouerTour(j1);
    } else {
        afficherPasDeCarte(j2,vJoueurs);
        if (!vTasDePioche.empty()) {
            j1.piocher(vTasDePioche);
            j1.detecterFamille(vFamilles);
        }
    }

    return checkFinDePartie();

}

vector<int> Partie::jouerPartie() {

    afficherPartie();
    bool finDePartie = false;
    do {
        afficherTour(iNoTour, vJoueurs, vTasDePioche, true);
        for (auto &j : vJoueurs) {
            finDePartie = jouerTour(*j);
            if(finDePartie){
                afficherTour(iNoTour, vJoueurs, vTasDePioche, false);
                afficherFinDePartie();
                afficherNbTour(iNoTour);
                return calculResultats();
            }
        }
        iNoTour++;

    } while (true);

}


bool Partie::checkFinDePartie() {
    for (const auto &f :vFamilles) {
        if (!f) {
            return false;
        }
    }
    return true;

}

std::vector<Carte> Partie::slice(std::vector<Carte> const &v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<Carte> vec(first, last);
    return vec;
}

unsigned int Partie::joueurAleatoire(Joueur j) {
    unsigned int iRand = 0;
    do
        iRand = rand() % NOMBRE_JOUEURS;
    while (*vJoueurs.at(iRand) == j || vJoueurs.at(iRand)->vCarteEnMain.empty());

    return iRand;
}

vector<int> Partie::calculResultats() const{
    vector<int> vResultats;
    for(auto& joueur : vJoueurs){
        vResultats.push_back(joueur->getVFamillesSurTable().size());
    }
    return vResultats;
}
