#ifndef INF2_LABO3_PARAMETRE_H
#define INF2_LABO3_PARAMETRE_H

#include <string>
#include <vector>
#include <iostream>

const unsigned short NOMBRE_FAMILLES = 9;
const unsigned short CARTES_PAR_FAMILLE = 4;
const unsigned short NOMBRE_JOUEURS = 4;
const unsigned short CARTES_PAR_JOUEUR = 5;
const bool DEBUG_MODE = true;

const std::string NOM_JOUEURS[] {"Alice",
                                 "Bob",
                                 "Carol",
                                 "Dave",
                                 "Eve"};

//MESSAGES DU DEBUG MODE
const std::string MESSAGE_TOUR_DEBUT = "*** Tour ";
const std::string MESSAGE_TOUR_FIN = " ***";
const std::string MESSAGE_PIOCHE = "Pioche : ";
const std::string SEPARATEUR = " : ";
const std::string MESSAGE_DEMANDE_0 = " demande a ";
const std::string MESSAGE_DEMANDE_1 = " la carte ";
const std::string MESSAGE_PAS_DE_CARTE_0 = "mais ";
const std::string MESSAGE_PAS_DE_CARTE_1 = " ne l'as pas";
const std::string MESSAGE_A_LA_CARTE_0 = "et ";
const std::string MESSAGE_A_LA_CARTE_1 = " donne la carte a ";
const std::string MESSAGE_PIOCHER_0 = " prend une carte dans la pioche (";
const std::string MESSAGE_PIOCHER_1 = ")";
const std::string MESSAGE_FIN_DE_PARTIE = "La partie est finie !";
const std::string MESSAGE_NB_TOURS = "Nombre de Tours : ";

const std::string TABULATEUR = "\t";



#endif //INF2_LABO3_PARAMETRE_H
