//
// Created by jetca on 06.03.2020.
//

#include "Carte.h"

using namespace std;

bool Carte::operator==(const Carte &c) const {
    return (this->MEMBRE == c.MEMBRE && this->FAMILLE == c.FAMILLE);
}
ostream& operator<<(ostream& lhs, const Carte& rhs)
{
    lhs << rhs.FAMILLE << char(rhs.MEMBRE);
    return lhs;
}
unsigned short Carte::getFamille() const {
    return FAMILLE;
}
unsigned short Carte::getMembre() const {
    return MEMBRE;
}