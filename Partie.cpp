#include "Partie.h"
#include <string>
#include <iostream>
#include "IHM.h"
#include "Symbole.h"

Partie::Partie() : nbParties()
{
}

Partie::Partie(unsigned int nbParties) : nbParties(nbParties)
{
}

unsigned int Partie::getNbParties()
{
    return nbParties;
}

void Partie::setNbParties(unsigned int nbParties)
{
    this->nbParties = nbParties;
}

void Partie::demarrerPartie()
{
    std::cout << "La partie va commencer" << std::endl;
    std::cout << "Choisissez votre Main" << std::endl;
    std::cout << " Pierre [1]" << std::endl;
    std::cout << "Feuille [2]" << std::endl;
    std::cout << " Ciseau [3]" << std::endl;
}