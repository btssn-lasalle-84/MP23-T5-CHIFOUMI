#include "Joueur.h"
#include <string>

Joueur::Joueur() : pseudo("")
{
}

Joueur::Joueur(std::string pseudo) : pseudo(pseudo)
{
}

std::string Joueur::getPseudo() const
{
    return pseudo;
}

void Joueur::setPseudo(std::string pseudo)
{
    this->pseudo = pseudo;
}