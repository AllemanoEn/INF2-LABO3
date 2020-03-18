#include <iostream>
#include "Partie.h"

using namespace std;

int main() {

    Partie p1;
    p1.jouerPartie();
    cout << p1.getiNoTour();

    cout << "Final test" << endl;
    return 0;
}
