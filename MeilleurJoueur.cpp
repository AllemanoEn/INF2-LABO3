//
// Created by david on 22.03.20.
//

#include "MeilleurJoueur.h"
#include "Parametre.h"

Carte MeilleurJoueur::decideCarte(std::vector<bool> vFamilles) {
    int iFamille;
    if(vCarteEnMain.empty()){
        // Choisir une famille au hasard
        iFamille = (rand() % NOMBRE_FAMILLES) + 1;

        // Incrémente jusqu'à trouver une famille qui n'est pas complétée
        while(vFamilles.at(iFamille - 1)) {
            iFamille = ((iFamille + 1)%NOMBRE_FAMILLES) + 1;
        }
    }
    else {
        // Décide de la famille dont il lui manque le moins de membres
        unsigned iMaxMembres = 0;
        for(int fam = 1; fam <= NOMBRE_FAMILLES; ++fam){
            unsigned count = compteCartesFamille(fam);
            if(count > iMaxMembres){
                iFamille = fam;
                iMaxMembres = count;
            }
        }
    }

    // Choisir une carte au hasard
    unsigned int iMembre = rand() % CARTES_PAR_FAMILLE + 65;

    // Incrémente la carte jusqu'à trouver une carte qui n'est pas dans la main du joueur
    Carte carteATester (iFamille, iMembre);
    while(demanderCarte(carteATester)) {
        iMembre = (iMembre)%CARTES_PAR_FAMILLE + 65;

        carteATester.setMembre(iMembre);
    }

    return carteATester;

}
