#include "Partie.h"
#include "IHM.h"
#include "Joueur.h"
#include "Symbole.h"
#include <string>

#ifdef DEBUG_PARTIE
#include <iostream>
#endif

Partie::Partie(IHM* ihm) : ihm(ihm), joueur(new Joueur)
{
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
}

Partie::~Partie()
{
    delete joueur;
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] " << this
              << std::endl;
#endif
}

void Partie::demarrer()
{
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << " ..." << std::endl;
#endif
    std::string pseudo = ihm->saisirPseudo();
    joueur->setPseudo(pseudo);
#ifdef DEBUG_PARTIE
    std::cout << "[" << __PRETTY_FUNCTION__ << ":" << __LINE__ << "] "
              << "pseudo = " << joueur->getPseudo() << std::endl;
#endif
}

unsigned int Partie::choisirNbOrdinateur()
{
    int choixOrdinateur;
    srand(time(0));
    choixOrdinateur = rand() % 3 + 1;
    return choixOrdinateur;
}