//
// Created by micha on 2020-03-10.
//

#ifndef INF2_LABO3_TESTCARTE_H
#define INF2_LABO3_TESTCARTE_H

#include "Carte.h"
#include "iostream"

void testCarte(){
    std::cout << "Creation de cartes: c0 = 1A, c1 = 1A, c2 = 6A, c3 = 1B, c4 = 22B" << std::endl;
    Carte c0(1, 'A');
    std::cout << "c0 = " << c0 << std::endl;
    std::cout << "Le famille est: " << c0.getFamille() << std::endl;
    std::cout << "Le membre est: " << (char)c0.getMembre() << std::endl;
    Carte c1(1, 'A');
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "Le famille est: " << c1.getFamille() << std::endl;
    std::cout << "Le membre est: " << (char)c1.getMembre() << std::endl;
    Carte c2(6, 'A');
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "Le famille est: " << c2.getFamille() << std::endl;
    std::cout << "Le membre est: " << (char)c2.getMembre() << std::endl;
    Carte c3(1, 'B');
    std::cout << "c3 = " << c3 << std::endl;
    std::cout << "Le famille est: " << c3.getFamille() << std::endl;
    std::cout << "Le membre est: " << (char)c3.getMembre() << std::endl;
    Carte c4(22, 'B');
    std::cout << "c4 = " << c4 << std::endl;
    std::cout << "Le famille est: " << c4.getFamille() << std::endl;
    std::cout << "Le membre est: " << (char)c4.getMembre() << std::endl;
    std::cout << "Test surcharge ==" << std::endl;
    std::cout << "c0 == c1: " << (c0 == c1) << std::endl;
    std::cout << "c0 == c2: " << (c0 == c2) << std::endl;
    std::cout << "c0 == c3: " << (c0 == c3) << std::endl;
    std::cout << "c0 == c4: " << (c0 == c4) << std::endl;

}

#endif //INF2_LABO3_TESTCARTE_H
