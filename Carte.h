//
// ATTENTION: PAS ENCORE TESTé
//

#ifndef INF2_LABO3_CARTE_H
#define INF2_LABO3_CARTE_H

#include <iostream>
#include <vector>

class Carte {
    /**
     * Retourne le cout "FM". Avec F, le numéro de la famille de la carte et M, la lettre du membre de cette carte.
     * @param lhs outstream
     * @param rhs la carte
     * @return le cout "FM". Avec F, le numéro de la famille de la carte et M, la lettre du membre de cette carte.
     */
    friend std::ostream &operator<<(std::ostream &lhs, const Carte &rhs);

public:
    /**
     * Construit la carte avec le numéro de la famille et la lettre du membre de la famille.
     * (la lettre doit être mis avec l'équivalent de son nombre ASCII car stockée en unsigned short)
     * @param FAMILLE lettre représentant la famille (nombre ASCii si mit en unsigned short)
     * @param MEMBRE numéro du membre
     */
    Carte(unsigned short FAMILLE, unsigned short MEMBRE) : famille(FAMILLE), membre(MEMBRE) {}

    /**
     * Compare les cartes, avec l'opérateur ==. Retourne vrai si les carte ont le même membre et la même famille.
     * Sinon retourne faux.
     * @param c la carte
     * @return vrai si les carte sont les mêmes. Sinon faux.
     */
    bool operator==(const Carte &c) const;

    /**
     * Cette surcharge d'opérateur est crée afin de pouvoir facilement trier les cartes des joueurs.
     * Il est fait en sorte qu'une carte soit strictement plus petite lorsque:
     * - le nombre de sa fammille est strictement inférieur à celle de la carte comparée
     * - le nombre (ASCII) de son membre est strictement inférieur à celle de la carte comparée
     *   si es deux dernières sont de la même famille.
     * @param c la carte
     * @return vrai si la la carte est strictement inférieur (v. description au début).
     *         Sinon faux.
     */
    bool operator<(const Carte &c) const;

    /**
     * Retourne un unsigned short représentant la famille de la carte.
     * @return un unsigned short représentant la famille de la carte.
     */
    unsigned short getFamille() const;

    /**
     * Retourne un unsigned short représentant en ASCII un membre.
     * @return  un unsigned short représentant en ASCII un membre.
     */
    unsigned short getMembre() const;

    /**
     * Permet de changer le membre
     * @param membre (nouvelle valeur du menmbre)
     */
    void setMembre(unsigned short membre);

private:
    unsigned short famille;
    unsigned short membre;
};


#endif //INF2_LABO3_CARTE_H
