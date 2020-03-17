#ifndef INF2_LABO3_PARAMETRE_H
#define INF2_LABO3_PARAMETRE_H

#include <string>
#include <vector>

const unsigned short NOMBRE_FAMILLES = 9;
const unsigned short CARTES_PAR_FAMILLE = 4;
const unsigned short NOMBRE_JOUEURS = 4;
const unsigned short CARTES_PAR_JOUEUR = 5;
const bool DEBUG_MODE = true;

const std::string NOM_JOUEURS[] {"Alice",
                                 "Bob",
                                 "Corona",
                                 "Dickael",
                                 "Henso"};

template<typename T>
std::vector<T> slice(std::vector<T> const &v, int m, int n);

#endif //INF2_LABO3_PARAMETRE_H
