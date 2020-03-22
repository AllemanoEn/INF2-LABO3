#ifndef INF2_LABO3_AFFICHAGE_H
#define INF2_LABO3_AFFICHAGE_H

#include "Parametre.h"
#include "Joueur.h"

/**
 * Affiche le string de la constante MESSAGE_PARTIE de Parametre.h
 */
void afficherPartie();

/**
 * Affiche l'état du trour:
 * Le tour actuel si "AfficherTour" == true
 * Les mains est familles complétées des joueurs
 * L'état de la pioche
 * @param iNoTour tour actuel
 * @param vJoueurs Les joueurs
 * @param vTasDePioche La pioche
 * @param AfficherTour décris plus haut
 */
void afficherTour(unsigned iNoTour, const std::vector<Joueur *> &vJoueurs, const std::vector<Carte> &vTasDePioche,
                        bool AfficherTour);

/**
 * Affiche la carte qu'un joueur veut demander à un autre joueur
 * @param j1 Le joueur qui demande une carte
 * @param j2 le joueur à qui on demande une carte
 * @param vJoueurs la liste des joueurs
 * @param carteAEchanger la carte demandée
 */
void afficherDemandeDeCarte(const Joueur &j1, unsigned j2, const std::vector<Joueur *> &vJoueurs,
                                  const Carte &carteAEchanger);

/**
 * Annonce qu'un joueur n'a pas une carte
 * @param j2 le joueur qui ne possède pas la carte
 * @param vJoueurs la liste des joueurs
 */
void afficherPasDeCarte(unsigned j2, const std::vector<Joueur *> &vJoueurs);

/**
 * Annonce qu'un joueur à une carte et la donne à un autre joueur
 * @param j1 le joueur qui recoit la carte
 * @param j2 le joueur qui donne la carte
 * @param vJoueurs liste des joueurs
 */
void afficherALaCarte(const Joueur &j1, unsigned j2, const std::vector<Joueur *> &vJoueurs);

/**
 * Affiche qu'un joueur pioche une carte
 * @param j1 le joueur qui pioche la carte
 * @param carte la carte piochée
 */
void afficherPiocher(Joueur *j1, const Carte &carte);

/**
 * Affiche que la partie est finie
 */
void afficherFinDePartie();

/**
 * Affiche le nombre de tours qui a été effectués afin de finir la partie
 * @param iNoTour le nombre de tours effectués
 */
void afficherNbTour(unsigned iNoTour);

#endif //INF2_LABO3_AFFICHAGE_H
