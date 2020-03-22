/// \file Joueur.h
/// \authors Enzo Allemano, David Pellissier, Michael Ruckstuhl
/// \date 22.03.2020
///
/// \brief \b Laboratoire \b 03
/// \brief Contient la classe Joueur
///
/// Remarque :
///
/// Compilateur : MinGw-g++ 6.3.0
#ifndef INF2_LABO3_JOUEUR_H
#define INF2_LABO3_JOUEUR_H

#include <string>
#include <vector>
#include <algorithm>

#include "Carte.h"

class Joueur {
public:

    //Peut-être qu'il serait mieux en privé
    std::vector<Carte> vCarteEnMain;

    /**
     * Construit un joueur avec son nom et lui initialise dans son vecteur de cartes
     * en main (vCarteEnMain) les cartes du vecteur "cartes" passé en paramètre.
     * @param nom nom du joueur
     * @param cartes vecteurs de cartes
     */
    Joueur(std::string nom, std::vector<Carte> cartes) : vCarteEnMain(cartes),strNom(nom) {};

    /**
     * Prends deux joueurs en référence. La carte "carteAEchanger" va être insérée dans le vecteur
     * des cartes en main (vCarteEnMain) du premier joueur et supprimée dans celui du deuxième.
     * Pour utiliser cette fonction, une test pour s'assurer que le deuxième joueur possède cette
     * carte doit être préalablement effectué. Si ce n'est pas le cas, la fonction renvoie une erreur.
     * @param j1 premier joueur
     * @param j2 deuxième joueur
     * @param carteAEchanger la carte que le premier joueur doit prendre du deuxième
     */
    friend void echangerCarte(Joueur &j1, Joueur &j2, const Carte &carteAEchanger);


    /**
     * Decide quelle carte le jouer va demander en fonction de sa main actuelle et en prenant compte
     * des familles déjà complétées.
     * @param vFamilles vecteur de bool indiquant quelles sont les familles déjà complétées
     * @return la carte que le joueur veut demander.
     * @details Cette fonction choisis au hasard une famille
     * Incrémente la famille si celle choisie au hasard n'est pas présente dans la main du joueur.
     * Si la main du joueur est vide, la famille est incrémentée jusqu'à rouer une famille qui n'est
     * pas déjà complétée.
     * Puis un membre de la famille est choisit au hasard.
     * Ce membre est incrémenté tant que la carte définie par le membre et la famille choisie est
     * présente dans la main du joueur.
     */
    virtual Carte decideCarte(const std::vector<bool>& vFamilles) const;

    /**
     * Retourne vrai si la carte passée en paramètre est présente dans la main du joueur (vCarteEnMain).
     * Sinon faux.
     * @param carte la carte à chercher dans la main du joueur.
     * @return vrai si la carte passée en paramètre est présente dans la main du joueur (vCarteEnMain).
     * Sinon faux.
     */
    bool demanderCarte(const Carte &carte) const;

    /**
     * Retourne le nombre (unsigned) de carte de la famille "iFamille" que le joueur possède (vCarteEnMain).
     * @param iFamille la famille dont la fonction doit renvoyer le compte
     * @return le nombre (unsigned) de carte de la famille "iFamille" que le joueur possède (vCarteEnMain).
     */
    unsigned compteCartesFamille(unsigned iFamille) const;

    /**
     * Insère une carte dans la main du joueur (vCarteEnMain).
     * La carte est comparée avec les autres cartes de la mains du joueur dans l'ordre.
     * Dès qu'une que la carte à insérer rempli l'un de ces deux critères:
     * - le nombre de sa fammille est strictement inférieur à celle de la carte comparée
     * - le nombre (ASCII) de son membre est strictement inférieur à celle de la carte comparée
     *   si ces deux dernières sont de la même famille.
     * La carte est insérée avant celle comparée.
     * Si ceci n'est jamais satisfait, la carte est inserée en dernière position.
     * @param carte la carte à insérer
     */
    void insererCarteEnMain(const Carte& carte);

    /**
     * Trie les cartes de la main du joueur dans un odre croissant.
     * Une carte est plus petite qu'une si l'une des deux conditions est présente:
     * - le nombre de sa fammille est strictement inférieur à celle de la carte comparée
     * - le nombre (ASCII) de son membre est strictement inférieur à celle de la carte comparée
     *   si es deux dernières sont de la même famille.
     */
    void trierCartesEnMain();

    /**
     * Détecte dans la main du joueur (vCartesEnMain) si une famille est complète.
     * Si cela est le cas, les cartes de la familles complétées sont supprimées
     * de la mains du joueur. On ajoute le unsigned short indiquant la famille complétée
     * dans les familles complétée par le joueur vCarteEnMain. Finalement le vecteur de bool
     * vFamille est mis à true à l'emplacment de la famille complétée.
     * @param vFamilles
     */
    void detecterFamille(std::vector<bool> &vFamilles);

    /**
     * Retourne en référence la main du joueur vCarteEnMain
     * @return en référence la main du joueur vCarteEnMain
     */
    const std::vector<Carte> &getVCarteEnMain() const;

    /**
     * Retourne en référence le nom (string) du joueur
     * @return  en référence le nom (string) du joueur
     */
    const std::string &getStrNom() const;

    /**
     * Définit la main d'un joueur
     * @param vCarteEnMain
     */
    void setVCarteEnMain(const std::vector<Carte> &vCarteEnMain);

    /**
     * Prend la dernières carte du vecteur passer en paramètre
     * Insère cette carte dans la main du joueur (vCarteEnMain)
     * Supprime cette carte du vecteur passé en référence
     * @param vTasDePioche vecteur passé en référence
     */
    void piocher(std::vector<Carte> &vTasDePioche);

    /**
     * Surcharge de l'opérateur ==.
     * Retourne vrai si les joueur ont les mêmes nom et jeu de carte. Sinon faux.
     * @param lhs un joueur
     * @param rhs un autre joueur
     * @return vrai si les joueur ont les mêmes nom et jeu de carte. Sinon faux.
     */
    friend bool operator==(const Joueur &lhs, const Joueur &rhs) {
        return (lhs.strNom == rhs.strNom) && (lhs.getVCarteEnMain() == rhs.getVCarteEnMain());
    }

    /**
     * Lors d'un cout affiche:
     * les carte de la main du joueur [Les familles complétées du joueur]
     * @param lhs outstream
     * @param rhs le joueur
     * @return ce qui est indiqué plus haut
     */
    friend std::ostream &operator<<(std::ostream &lhs, const Joueur &rhs);

    /**
     * Accesseur de vFamillesSurTable
     * @return vFamillesSurTable en référence
     */
    const std::vector<unsigned short> &getVFamillesSurTable() const;

    /**
     * Modifie vFamillesSurTable comme le vecteur passé en paramètre (référence)
     * @param vFamillesSurTable
     */
    void setVFamillesSurTable(const std::vector<unsigned short> &vFamillesSurTable);

private:
    const std::string strNom;
    std::vector<unsigned short> vFamillesSurTable;

    /**
     * Recherche une carte dans la main du joueur (vCarteEnMain)
     * @param carte carte à rechercher
     * @return l'itérateur de la carte recherchée
     */
    std::vector<Carte>::const_iterator rechercherCarte(const Carte &carte) const;
};


#endif //INF2_LABO3_JOUEUR_H
