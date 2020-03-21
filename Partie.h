#ifndef INF2_LABO3_PARTIE_H
#define INF2_LABO3_PARTIE_H

#include <vector>


#include "Joueur.h"
#include "Parametre.h"


class Partie {
public:
    Partie();

    std::vector<Carte> slice(std::vector<Carte> const &v, int m, int n);

    void jouerPartie();
    unsigned int getiNoTour();

    //TEST RANDOM


private:
    void jouerTour(Joueur& j);
    bool checkFinDePartie();

    /// \brief fonction qui retourne un joueur aléatoire qui n'est pas celui passé en paramètre
    /// \param j joueur à éviter
    /// \return un joueur aleatoire
    unsigned joueurAleatoire(Joueur j);

    std::vector<Carte> vTasDePioche;
    std::vector<Joueur> vJoueurs;
    std::vector<bool> vFamilles;

    unsigned int iNoTour;

};


#endif //INF2_LABO3_PARTIE_H
