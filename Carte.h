//
// ATTENTION: PAS ENCORE TESTé
//

#ifndef INF2_LABO3_CARTE_H
#define INF2_LABO3_CARTE_H

#include <iostream>
#include <vector>

class Carte {
    /**
     * Retourne le cout MF, avec M, le numéro du Membre et F, la lettre de la famille
     * @param lhs outstream
     * @param rhs la carte
     * @return le cout MF, avec M, le numéro du Membre et F, la lettre de la famille
     */
    friend std::ostream &operator<<(std::ostream &lhs, const Carte &rhs);

public:
    /**
     * Construit la carte avec le numéro du membre et la lettre de la famille (nombre ASCII si unsigned short)
     * @param FAMILLE lettre représentant la famille (nombre ASCii si mit en unsigned short)
     * @param MEMBRE numéro du membre
     */
    Carte(unsigned short FAMILLE, unsigned short MEMBRE) : FAMILLE(FAMILLE), MEMBRE(MEMBRE) {}

    /**
     * Compare les cartes, avec l'opérateur ==. Retourne vrai si les carte ont le même membre et la même famille
     * @param c la carte
     * @return vrai si les carte sont les mêmes. Sinon faux.
     */
    bool operator==(const Carte &c) const;

    /**
     * Retourne un unsigned short représentant la famille en ASCII de la carte.
     * @return un unsigned short représentant la famille en ASCII de la carte.
     */
    unsigned short getFamille() const;

    /**
     * Retourne un unsigned short représentant un membre.
     * @return  un unsigned short représentant un membre.
     */
    unsigned short getMembre() const;

    void setMembre(unsigned short membre);

private:
    unsigned short FAMILLE;
    unsigned short MEMBRE;
};


#endif //INF2_LABO3_CARTE_H
