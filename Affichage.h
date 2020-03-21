#ifndef INF2_LABO3_AFFICHAGE_H
#define INF2_LABO3_AFFICHAGE_H

#include "Parametre.h"
#include "Joueur.h"

const void afficherTour(unsigned iNoTour,const std::vector<Joueur>& vJoueurs, const std::vector<Carte>& vTasDePioche);
const void afficherDemandeDeCarte(const Joueur& j1, unsigned j2, const std::vector<Joueur>& vJoueurs, const Carte& carteAEchanger);
const void afficherPasDeCarte(unsigned j2, const std::vector<Joueur>& vJoueurs);
const void afficherALaCarte(const Joueur& j1, unsigned j2, const std::vector<Joueur>& vJoueurs);
const void afficherPiocher(Joueur *j1, const Carte& carte);
const void afficherFinDePartie();
const void afficherNbTour(unsigned iNoTour);

#endif //INF2_LABO3_AFFICHAGE_H
