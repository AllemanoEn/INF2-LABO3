/// \file Partie.h
/// \authors Enzo Allemano, David Pellissier, Michael Ruckstuhl
/// \date 22.03.2020
///
/// \brief \b Laboratoire \b 03
/// \brief Contient la classe Partie
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>


#include "Joueur.h"
#include "Parametre.h"


class Partie {
public:

    /**
     * Construit une partie selon les constantes de parametre.h
     * vJoueurs est initialise les joueurs de la parties
     * - Lors de sa création, la partie attribut des cartes aux joueurs
     * il est aussi défini quel est le joueur qui débute la partie
     * @param vJoueurs les joueurs de la partie
     * @param premierJoueur le premier joueur
     */
    Partie(std::vector<Joueur *> vJoueurs, unsigned premierJoueur);

    /**
     * Fonction qui sert à faire jouer la partie
     * @return le nombre de familles complétées par chaque joueur
     */
    std::vector<int> jouerPartie();

    /**
     * Accesseur du nombre de tours effectués
     * @return le nombre (unsigned int) de tours effectués
     */
    unsigned int getiNoTour();

private:

    unsigned premierJoueur;
    unsigned int iNoTour;
    std::vector<Carte> vTasDePioche;
    std::vector<Joueur *> vJoueurs;
    std::vector<bool> vFamilles;

    /**
     * Fonction qui fait jouer un joueur lors d'un tour avec ses possibilités d'actions
     * @param j le joueur qui doit jouer
     * @return true si la partie est finie. Sinon faux
     */
    bool jouerTour(Joueur &j);

    /**
     * Vérifie si la partie est terminée (toutes les familles sont complétées
     * @return true si toute les familles sont complétées. Sinon false.
     */
    bool checkFinDePartie();

    /**
     * Retourne le nombre de familles que chaque joueur ont complété dans un vecteur
     * @return le nombre de familles que chaque joueur ont complété dans un vecteur
     */
    std::vector<int> calculResultats() const;

    /**
     * fonction qui retourne un joueur aléatoire qui n'est pas celui passé en paramètre
     * @param j joueur à éviter
     * @return un joueur aleatoire
     */
    unsigned joueurAleatoire(Joueur j);

    /**
     * Fonction qui permet d'extraie un bout de vecteur entre deux positions
     * @param v vecteur source
     * @param m 1er position
     * @param n 2eme position
     * @return le vecteur entre les positions 1 et 2
     */
    std::vector<Carte> slice(std::vector<Carte> const &v, int m, int n);

};


#endif //INF2_LABO3_PARTIE_H
