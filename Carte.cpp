#include "Carte.h"

using namespace std;

bool Carte::operator==(const Carte &c) const {
    return (this->membre == c.membre && this->famille == c.famille);
}

bool Carte::operator<(const Carte &c) const {
    if (this->famille < c.famille)
        return true;
    if (this->famille == c.famille)
        return (this->membre < c.membre);
    return false;
}

ostream &operator<<(ostream &lhs, const Carte &rhs) {
    lhs << rhs.famille << char(rhs.membre);
    return lhs;
}

unsigned short Carte::getFamille() const {
    return famille;
}

unsigned short Carte::getMembre() const {
    return membre;
}

void Carte::setMembre(unsigned short membre) {
    this->membre = membre;
}