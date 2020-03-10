//
// Created by jetca on 06.03.2020.
//

#ifndef INF2_LABO3_CARTE_H
#define INF2_LABO3_CARTE_H


class Carte {
    //friend ostream& operator<<();
public:
    Carte(const unsigned short FAMILLE, const unsigned short MEMBRE) : FAMILLE(FAMILLE), MEMBRE(MEMBRE) {}
    bool Carte::operator==(const Carte& c);
private:
    const unsigned short FAMILLE;
    const unsigned short MEMBRE;

};


#endif //INF2_LABO3_CARTE_H
