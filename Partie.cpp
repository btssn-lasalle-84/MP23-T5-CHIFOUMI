#include "Partie.h"
#include <string>

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