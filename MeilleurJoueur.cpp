/// \file MeilleurJoueur.cpp
/// \authors Enzo Allemano, David Pellissier, Michael Ruckstuhl
/// \date 22.03.2020
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#include "MeilleurJoueur.h"
#include "Parametre.h"

Carte MeilleurJoueur::decideCarte(const std::vector<bool>& vFamilles) const {
    int iFamille = 0;
    if(vCarteEnMain.empty()){
        // Choisir une famille au hasard
        iFamille = (rand() % NOMBRE_FAMILLES) + 1;

        // Incrémente jusqu'à trouver une famille qui n'est pas complétée
        while(vFamilles.at(static_cast<unsigned int>(iFamille - 1))) {
            iFamille = ((iFamille + 1)%NOMBRE_FAMILLES) + 1;
        }
    }
    else {
        // Décide de la famille dont il lui manque le moins de membres
        unsigned iMaxMembres = 0;
        for(int fam = 1; fam <= NOMBRE_FAMILLES; ++fam){
            unsigned count = compteCartesFamille(static_cast<unsigned int>(fam));
            if(count > iMaxMembres){
                iFamille = fam;
                iMaxMembres = count;
            }
        }
    }

    // Choisir une carte au hasard
    auto iMembre = rand() % CARTES_PAR_FAMILLE + 65;

    // Incrémente la carte jusqu'à trouver une carte qui n'est pas dans la main du joueur
    Carte carteATester (static_cast<unsigned short>(iFamille), static_cast<unsigned short>(iMembre));
    while(demanderCarte(carteATester)) {
        iMembre = (iMembre)%CARTES_PAR_FAMILLE + 65;

        carteATester.setMembre(static_cast<unsigned short>(iMembre));
    }

    return carteATester;

}
