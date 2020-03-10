//
// Created by jetca on 06.03.2020.
//

#include "Carte.h"

bool Carte::operator==(const Carte &c) {
    return (this->MEMBRE == c.MEMBRE && this->FAMILLE == c.FAMILLE);
}