//
// Created by micha on 2020-03-21.
//

#include "Affichage.h"
#include <iostream>

using namespace std;

const void afficherPartie() {
    if (DEBUG_MODE) cout << MESSAGE_PARTIE << endl;
}

const void afficherTour(unsigned iNoTour, const std::vector<Joueur*> &vJoueurs, const std::vector<Carte> &vTasDePioche,
                        bool AfficherTour) {
    if (DEBUG_MODE) {
        if (AfficherTour)
            cout << MESSAGE_TOUR_DEBUT << iNoTour << MESSAGE_TOUR_FIN << endl;

        for (size_t i = 0; i < vJoueurs.size(); ++i) {
            cout << vJoueurs.at(i)->getStrNom() << TABULATEUR << SEPARATEUR << *vJoueurs.at(i) << endl;
        }
        cout << MESSAGE_PIOCHE << TABULATEUR << SEPARATEUR;
        for (auto carteEnMain : vTasDePioche) {
            cout << carteEnMain << " ";
        }
        cout << endl;
    }
}

const void afficherDemandeDeCarte(const Joueur &j1, unsigned j2, const std::vector<Joueur*> &vJoueurs,
                                  const Carte &carteAEchanger) {
    if (DEBUG_MODE)
        cout << j1.getStrNom() << MESSAGE_DEMANDE_0 << vJoueurs.at(j2)->getStrNom() << MESSAGE_DEMANDE_1
             << carteAEchanger.getFamille() << char(carteAEchanger.getMembre()) << endl;
}

const void afficherPasDeCarte(unsigned j2, const std::vector<Joueur*> &vJoueurs) {
    if (DEBUG_MODE) cout << MESSAGE_PAS_DE_CARTE_0 << vJoueurs.at(j2)->getStrNom() << MESSAGE_PAS_DE_CARTE_1 << endl;
}

const void afficherALaCarte(const Joueur &j1, unsigned j2, const std::vector<Joueur*> &vJoueurs) {
    if (DEBUG_MODE)
        cout << MESSAGE_A_LA_CARTE_0 << vJoueurs.at(j2)->getStrNom() << MESSAGE_A_LA_CARTE_1 << j1.getStrNom() << endl;
}

const void afficherPiocher(Joueur *j1, const Carte &carte) {
    if (DEBUG_MODE)
        cout << j1->getStrNom() << MESSAGE_PIOCHER_0 << carte << MESSAGE_PIOCHER_1 << endl;
}

const void afficherFinDePartie() {
    if (DEBUG_MODE) cout << MESSAGE_FIN_DE_PARTIE << endl;
}

const void afficherNbTour(unsigned iNoTour) {
    if (DEBUG_MODE) cout << MESSAGE_NB_TOURS << iNoTour << endl;
}