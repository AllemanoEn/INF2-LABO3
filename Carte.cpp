#include "Carte.h"

using namespace std;

bool Carte::operator==(const Carte &c) const {
    return (this->MEMBRE == c.MEMBRE && this->FAMILLE == c.FAMILLE);
}
<<<<<<< Updated upstream

void Carte::setMembre(unsigned short membre) {
    MEMBRE = membre;
}

=======
bool Carte::operator<(const Carte &c) const {
    return (this->FAMILLE <= c.FAMILLE && this->MEMBRE < c.MEMBRE);
}
>>>>>>> Stashed changes
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
